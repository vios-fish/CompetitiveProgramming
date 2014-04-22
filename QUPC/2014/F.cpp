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

const int mod = 1000000009;

int main(){
    int N, T, M;
    VI D;

    cin >> N >> T >> M;

    rep(i,N){
        int a;
        cin >> a;
        D.push_back(a);
    }

    int dp[101][10001] = {0};
    dp[0][0] = 1;
    rep(i,N){
        rep(j,i+1){
            rep(k,T+1){
                if(k>D[i]){
                    dp[j][k] += dp[j-1][k-D[i]];
                    dp[j][k] %= mod;
                }
            }
        }
    }
    rep(i,N){
        rep(j,T+1){
            cout << dp[i][j];
        }
        cout << endl;
    }
    int ans = 0;
    reep(i,M,N){
        rep(j,T+1){
            ans += dp[i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
}

