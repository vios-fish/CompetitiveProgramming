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

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long int LLI;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

int main(){
    int n;
    while(cin >> n, n){
        VS vs;
        rep(i,n){
            string ss;
            cin >> ss;
            vs.push_back(ss);
        }

        int dep = -1;
        rep(i,n){
            rep(j,vs[i].size()){
                dep = max(dep, j);
                if(vs[i][j] != '.') break;
                if(vs[i][j] == '.') vs[i][j] = ' ';
                if(vs[i][j+1] != '.') vs[i][j] = '+';
            }
        }

        rep(i,dep){
            bool f = false;
            int pre = 0;
            rep(j,n){
                if( f && vs[j][i] == '+' ){
                    reep(k,pre,j){
                        if(vs[k][i] == ' ') vs[k][i] = '|';
                    }
                }
                if( vs[j][i] == '+') f = true;
                if( vs[j][i] != ' ' && vs[j][i] != '+'){
                    f = false;
                    pre = j;
                }
            }
        }

        rep(i,n) cout << vs[i] << endl;
    }
}
