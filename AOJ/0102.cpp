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
    int n;

    while(1){
        
    int g[15][15] = {0};
        
    cin >> n;
    if(n==0) break;
    
    rep(i, n){
        rep(j, n){
            cin >> g[i][j];
            g[i][n] += g[i][j];
            g[n][j] += g[i][j];
        }
    }

    rep(i,n) g[n][n]+=g[i][n];

    rep(i,n+1){
        rep(j,n+1){
            printf("%5d",g[i][j]);
        }
        puts("");
    }

    }
    return 0;
}

