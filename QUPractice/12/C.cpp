#include <iostream>
#include <cstdlib>
#include <cstdio>
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
#include <algorithm>
#include <numeric>
#include <climits>
#include <array>

using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

#define reep(i,a,b) for( int i = (int)(a); i < (int)(b); ++i)
#define rep(i,n) reep(i,0,n)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define DEBUG(x) cerr << #x << " = " << (x) << "(L" << __LINE__ << ")" << __FILE__ << endl;
#define DUMPA(a, n) cerr << #a << " = {" << a[0]; reep(itr, 1, n) { cout << ", " << a[itr]; } cerr << "}" << endl;
#define DUMPAA(a, n, m) rep(itr, n) {rep(jtr, m) {cout << a[itr][jtr] << " ";} cout << endl;}

#define ALL(a) begin(a),end(a)
#define rALL(a) (a).begin(),(a).end()

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long int LLI;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

int main(){
    string ss;
    int L;

    while( cin >> ss >> L, L ){
        map<string,int> m;
        int cnt = 0;
        while(1){
            string smax = ss;
            string smin = ss;

            sort(ALL(smin));
            sort(rALL(smax));

            int imax = toInt(smax);
            int imin = toInt(smin);

            ss = toString(imax-imin);

            for(int i = L; i>=0; --i){
                
            }


            auto mit = m.find(ss);
            if( mit != m.end() ){
                cout << ss << " " <<  (*mit).first << " " << cnt;
                break;
            }else{
                m[ss] = cnt;
            }

            ++cnt;
        }
    }
}











