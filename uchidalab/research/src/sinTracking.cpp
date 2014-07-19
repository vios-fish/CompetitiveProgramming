#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <tuple>
#include <sstream>
#include <unordered_map>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "LPS.hpp"
  
const double EPS = 10e-12;

// tupleのハッシュ関数
namespace std{
    namespace
    {
  
        // Code from boost
        // Reciprocal of the golden ratio helps spread entropy
        //     and handles duplicates.
        // See Mike Seymour in magic-numbers-in-boosthash-combine:
        //     http://stackoverflow.com/questions/4948780
  
        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
  
        // Recursive template code derived from Matthieu M.
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
            struct HashValueImpl
            {
                static void apply(size_t& seed, Tuple const& tuple)
                    {
                        HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
                        hash_combine(seed, std::get<Index>(tuple));
                    }
            };
  
        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
            static void apply(size_t& seed, Tuple const& tuple){
                hash_combine(seed, std::get<0>(tuple));
            }
        };
    }
      
    template <typename ... TT>
    struct hash<std::tuple<TT...>> 
    {
        size_t operator()(std::tuple<TT...> const& tt) const
        {                                              
            size_t seed = 0;                             
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
            return seed;                                 
        }
  
    };
}


using namespace std;

////////////////////////////////////////////////////////////////

// 疎行列の一つの要素を表す
// (x, y, 係数)
typedef tuple<int, int, double> SP;

// 疎行列を表す
typedef vector<SP> SPMat;

// 一つの辺を表す
// (t, i, j)
typedef tuple<int, int, int> Edge;

// 目的関数の一つの変数を表す
// (変数の番号, 係数, 変数名)
typedef tuple<int, double, string> Obj;

// 制約行列の一つの要素を表す
// (変数の番号, 係数)
typedef tuple<int, double> Coff;

// 制約式を表す型
// (係数のベクター, 制約のタイプ, 上界, 下界, 制約式の名前)
typedef tuple<vector<Coff>, lps::LPS::TypeOfSrtucturalVariable, double, double, string> Constrain;

///////////////////////////////////////////////////////////////

size_t n, m;
size_t T;
unordered_map<Edge, int, hash<Edge>> flowmap;
unordered_map<int, Edge> rflowmap;
vector<Edge> flowsink, flowsource;

inline bool isRange(int i){
    return (0 <= i && i < n);
}
  
inline void debugmap(int t, int i, int j){
    if( flowmap[Edge(t,i,j)] == 0) cout << "map " << t << " " << i << " " << j <<endl;
}
  
template<typename ...Ts>
inline void debugtuple(tuple<Ts...> tu){
    cout << get<0>(tu) << " " << get<1>(tu) << " " << get<2>(tu) << " ";
}
  
void neighborhood(int t, int i, vector<int>& N){
    N = vector<int>();
    const int diff[] = {-2,-1,0,1,2};
      
    for(auto& d : diff){
        if(isRange(i+d)){
            N.push_back(i+d);
        }
    }
}
  
void setEdgefromSource(){
    flowsource = vector<Edge>();
    for(int j=0; j<n; ++j) flowsource.push_back(Edge(-1,-1,j));
}
  
void setEdgetoSink(){
    flowsink = vector<Edge>();
    for(int i=0; i<n; ++i) flowsink.push_back(Edge(T-1,i,-1));
}


// create map for mapping time t, point i and point j to intger
void createEdgeMap( ){
    int cnt = 1;
    // from source
    for(auto& sflow : flowsource){
        rflowmap[cnt] = sflow;
        flowmap[sflow] = cnt++;
    }
      
    for(int t=0; t<T-1; ++t){
        for(int i=0; i<n; ++i){
            vector<int> N;
            neighborhood(t, i, N);
            for(auto& j : N){
                rflowmap[cnt] = Edge(t,i,j);
                flowmap[Edge(t,i,j)] = cnt++;
            }
        }
    }
    
    // to sink
    for(auto& sflow : flowsink){
        rflowmap[cnt] = sflow;
        flowmap[sflow] = cnt++;
    }
}
  
  
void setObjectfunction(vector<Obj>& coff, const cv::Mat& sinImage){
    const double p = 0.7, q = 0.25;
    const double pcost = log(p/(1.0-p));
    const double qcost = log(q/(1.0-q));
    cout << "pcost " << pcost << endl;
    cout << "qcost " << qcost << endl;
      
    for(int t=0; t<T-1; ++t){
        for( int i=0; i<n; ++i){
            int mono = 0;
            for(int c=0; c<sinImage.channels(); ++c){
                mono += sinImage.data[ i*sinImage.step + t*sinImage.elemSize() + c];
//                  cout << (int)sinImage.data[ i*sinImage.step + t*sinImage.elemSize() + c] << " ";
            }
//              cout << "mono " << mono << " "  << sinImage.channels() << endl;
            double tmp;
            if( mono != 255*sinImage.channels() ) tmp = pcost;
            else tmp = qcost;
              
            vector<int> N;
            neighborhood(t, i, N);
            for(auto& j : N){
                ostringstream sout;
                sout << "OBJ(" << t << "," << i << "," << j << ")";
                debugmap(t, i, j);
                coff.push_back( Obj(flowmap[Edge(t,i,j)], tmp, sout.str()) );
            }
        }
    }
  
    // from source
    for(auto& sflow : flowsource){
        ostringstream sout;
        sout << "OBJ(" << get<0>(sflow) << "," << get<1>(sflow) << "," << get<2>(sflow) << ")";
        coff.push_back( Obj(flowmap[sflow], -0.1, sout.str()) );
    }
  
    // to sink
    for(auto& sflow : flowsink){
        int mono = 0;
        for(int c=0; c<sinImage.channels(); ++c){
            mono += sinImage.data[ get<1>(sflow)*sinImage.step + get<0>(sflow)*sinImage.elemSize() + c];
        }
        double tmp;
        if( mono != 255*sinImage.channels() ) tmp = pcost;
        else tmp = qcost;
        ostringstream sout;
        sout << "OBJ(" << get<0>(sflow) << "," << get<1>(sflow) << "," << get<2>(sflow) << ")";
        coff.push_back( Obj(flowmap[sflow], tmp, sout.str()) );
    }        
}
  
void setCapacityRequirements(vector<Constrain>& capreq ){
    for(int t=0; t<T-1; ++t){
        for(int i=0; i<n; ++i){
            vector<int> N;
            neighborhood(t, i, N);
            vector<Coff> tmp;
            for(auto& j : N){
                tmp.push_back( Coff(flowmap[Edge(t,i,j)], 1.0) );
            }
            ostringstream sout;
            sout << "CAP(" << t << "," << i << ")";
            capreq.push_back( Constrain(tmp, lps::LPS::TypeOfSrtucturalVariable::UP, 1.0, 1.0, sout.str()) );
        }
    }
}
  
void setFlowRequirements(vector<Constrain>& flowreq){
    for(int t=1; t<T-1; ++t){
        for(int i=0; i<n; ++i){
            vector<int> N;
            neighborhood(t, i, N);
            vector<Coff> tmp;
            for(auto& j : N){
                tmp.push_back( Coff(flowmap[Edge(t,i,j)], 1) );
                tmp.push_back( Coff(flowmap[Edge(t-1,j,i)], -1) );
            }
            ostringstream sout;
            sout << "FLW(" << t << "," << i << ")";
            flowreq.push_back( Constrain(tmp, lps::LPS::TypeOfSrtucturalVariable::UP, 0.0, 0.0, sout.str() ));
        }
    }
  
    // from source
  
    for(int i=0; i<n; ++i){
        vector<int> N;
        neighborhood(0, i, N);
        vector<Coff> tmp;
        ostringstream sout;
        sout << "FLW(" << -1 << "," << i << ")";
        tmp.push_back( Coff(flowmap[Edge(-1,-1,i)], -1));
        for(auto& j : N){
            tmp.push_back( Coff(flowmap[Edge(0,i,j)], 1));
        }
        flowreq.push_back( Constrain(tmp, lps::LPS::TypeOfSrtucturalVariable::UP, 0.0, 0.0, sout.str()));
    }
      
    // to sink
  
    for(int i=0; i<n; ++i){
        vector<int> N;
        neighborhood(0, i, N);
        vector<Coff> tmp;
        ostringstream sout;
        sout << "FLW(" << T-1 << "," << i << ")";
        tmp.push_back( Coff(flowmap[Edge(T-1,i,-1)], 1));
        for(auto& j : N){
            tmp.push_back( Coff(flowmap[Edge(T-2,j,i)], -1));
        }
        flowreq.push_back( Constrain(tmp, lps::LPS::TypeOfSrtucturalVariable::UP, 0.0, 0.0, sout.str()) );
    }
  
    // sink to source
  
    vector<Coff> tmp;
    for(auto& sflow : flowsource){
        tmp.push_back( Coff(flowmap[sflow], 1) );
    }
    for(auto& sflow : flowsink){
        tmp.push_back( Coff(flowmap[sflow], -1) );
    }
    flowreq.push_back( Constrain(tmp, lps::LPS::TypeOfSrtucturalVariable::UP, 0.0, 0.0, "(FLW,SNK)"));
}
  
void setFrequencyRequipments(vector<Constrain>& freqreq){
    const int freqency = 42;

    for(int t=0; t+freqency<T-1; ++t){
        for(int i=0; i<n; ++i){
            vector<int> N;
            neighborhood(t, i, N);
            for(auto& j: N){
                vector<Coff> tmp;
                ostringstream sout;
                sout << "FRQ(" << t << "," << i << "," << j << ")";
                tmp.push_back(Coff(flowmap[Edge(t,i,j)], -1));
                tmp.push_back(Coff(flowmap[Edge(t+freqency, i, j)], 1));
                freqreq.push_back( Constrain(tmp, lps::LPS::TypeOfSrtucturalVariable::UP, 0.0, 0.0, sout.str()) );
            }
        }
    }
}
  
  
int main(){
    cv::Mat sinImage = cv::imread("../bin/sinImage8.png", 1);
    const string winname = "Sin Tracking";
    const string outputname = "output.png";
    if( sinImage.empty() ){
        cout << "error: input file" << endl;
        exit(1);
    }
    n = sinImage.rows;
    m = sinImage.cols;
    T = sinImage.cols;
    
    setEdgefromSource();
    setEdgetoSink();
    createEdgeMap();
    
    lps::LPS lp; // Create lp solver
    
    // set maximum
    lp.setObjDir(lps::LPS::OptDirectFlag(2));
    
    // 目的関数の係数設定
    vector<Obj> coff;
    setObjectfunction(coff, sinImage);
    lp.addCols(coff.size());
    for(int i=0; i<coff.size(); ++i){
        lp.setObjCoef(get<0>(coff[i]), get<1>(coff[i]));
        lp.setColName(get<0>(coff[i]), get<2>(coff[i]));
        lp.setColBnds(get<0>(coff[i]), lps::LPS::TypeOfSrtucturalVariable(2), 0, 0);
    }

    // 制約の設定
    vector<Constrain> constrains;
    setCapacityRequirements(constrains);
    setFlowRequirements(constrains);
    setFrequencyRequipments(constrains);
    
    SPMat cofmat;
    int cnt = 1;
    lp.addRows(constrains.size());
    for(auto& con : constrains){
        lp.setRowBnds(cnt, get<1>(con), get<2>(con), get<3>(con));
        lp.setRowName(cnt, get<4>(con));
        for(auto& coff : get<0>(con) ){
            cofmat.push_back( SP(cnt, get<0>(coff), get<1>(coff)) );
        }
        ++cnt;
    }
    
    // 値が重なったり範囲外にアクセスしてないか確認
    if( lp.checkDup(cofmat.size(), coff.size(), cofmat) != 0){
        cout << "error" << endl;
    }
    // 制約行列を設定
    lp.setLoadMatrix(cofmat);
    
    // 設定した問題をテキストに
    lp.writeProb(0, "prob.gzz");
    
    // シンプレックス法で計算
    lp.simplex();
    
    // 結果をテキストに書き出す
    lp.printSol("sol.txt");
    
    // 結果を画像へ出力
    vector<double> colprim;
    lp.getColPrim(colprim, coff.size());
    for(int i=0; i<colprim.size(); ++i){
        Edge flow = rflowmap[i+1];
//          cout << "(" << get<0>(flow) << ", " << get<1>(flow) << ", " << get<2>(flow) << ")=" << colprim[i] << endl;
        
        if( get<0>(flow) == -1){
            continue;
        }
        
        if( colprim[i] - 1.0 >= -EPS ){
//              cout << "a " << get<0>(flow) << " " << get<1>(flow) << endl;
            for(int c=0; c<sinImage.channels(); ++c){
                sinImage.data[get<1>(flow)*sinImage.step +  get<0>(flow)*sinImage.elemSize() + c] = 0;
            }
        }
    }
    
    cout << n << " " << T << endl;
    cout << coff.size() << endl;
    
    cv::imwrite(outputname, sinImage);
    
    cv::namedWindow(winname, CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
    cv::imshow(winname, sinImage);
    
    cv::waitKey();
    
    return 0;
}
