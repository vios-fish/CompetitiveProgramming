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

using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

#define reep(i,a,b) for( int i = (int)(a); i < (int)(b); ++i)
#define rep(i,n) reep(i,0,n)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define DEBUG(x) cerr << #x << " = " << (x) << "(L" << __LINE__ << ")" << __FILE__ << endl;
#define DUMPA(a, n) cerr << #a << " = {" << a[0]; reep(itr, 1, n) { cout << ", " << a[itr]; } cerr << "}" << endl;
#define DUMPAA(a, n, m) rep(itr, n) {rep(jtr, m) {cout << a[itr][jtr] << " ";} cout << endl;}

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}
int mp[1010][1010] = {0};
int dp[3][1010][1010] = {0};

int main(){
    int n,m,k;

    cin >> n >> m >> k;

    int ms[256] = {0};

    ms['J'] = 0;
    ms['O'] = 1;
    ms['I'] = 2;
    
    reep(i,1,n+1){
        reep(j,1,m+1){
            char c;
            cin >> c;
            mp[i][j] = ms[c];
        }
    }

    rep(i,n+1) rep(j,3) dp[j][i][0] = 0;
    rep(i,m+1) rep(j,3) dp[j][0][j] = 0;
    
    reep(i,1,n+1){
        reep(j,1,m+1){
            rep(k,3){
                dp[k][i][j] = dp[k][i-1][j] + dp[k][i][j-1] - dp[k][i-1][j-1];
                if(mp[i][j] == k) dp[k][i][j] += 1;
            }
        }
    }

    rep(i,k){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        --a;
        --b;

        rep(j,3){
            cout << dp[j][a][b] - dp[j][a][d] - dp[j][c][b] + dp[j][c][d];
            if(j!=2) cout << " ";
        }
        cout << endl;
    }

}

