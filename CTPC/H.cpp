#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <sstream>

using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << "(L" << __LINE__ << ")" << __FILE__ << endl;

#define reep(i,a,b) for( int i = (int)(a); i < (int)(b); ++i)
#define rep(i,n) reep(i,0,n)

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

int main(){
    int masu[25][25];
    int cat[25][25];
    int m,n,c;
    const int p = 1000000;
    int dx[] = {0,1,1,-1,-1,-1,0,1,0};
    int dy[] = {1,0,1,1,0,-1,-1,-1,0};

    cin >> m >> n >> c;

    rep(i,m+1)rep(j,n+1)masu[i][j] = 0;

    rep(i,c){
        int p,q;
        cin >> p >> q;
        rep(j,8) cat[p+dx[j]][q+dy[j]] = -1;
        cat[p][q] = -2;
    }

    masu[0][0] = 1;
    rep(i,m+1){
        rep(j,n+1){
            if( cat[i][j] == -2 ) continue;
            
            rep(k,3){
                if( i-dx[k] < 0 || j-dy[k] < 0) continue;
                if( cat[i-dx[k]][j-dy[k]] == -2)continue;
                if( cat[i-dx[k]][j-dy[k]] != -1 ){
                    if(k==2){
                        masu[i][j] = masu[i-1][j-1];
                    }else{
                        masu[i][j] += masu[i-dx[k]][j-dy[k]];
                    }
                }else{
                    if( k != 2 ){
                        masu[i][j] += masu[i-dx[k]][j-dy[k]];
                    }
                }
                masu[i][j] %= p;

            }
        }
    }

    rep(i,m+1){rep(j,n+1)cout << masu[i][j] << " ";cout << endl;}
    
    cout << masu[m][n] << endl;

}

