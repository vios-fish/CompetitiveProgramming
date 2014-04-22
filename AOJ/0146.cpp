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

typedef pair<double, VI> PDI;

const double INF = 10000000;

PDI dp[15][1<<15];
int id[15], d[15], w[15];
int n;

PDI sdp(int nowi, int used, int weight){
    if(used == (1<<n)-1) return PDI(0.0, VI(1,id[nowi]));
    if(dp[nowi][used].first != INF) return dp[nowi][used];

    PDI res = PDI(INF, VI());
    rep(i,n){
        if((used & (1<<i)) == 0){
            PDI tmp = sdp(i, used|(1<<i), weight+w[i]);
            tmp.first += abs(d[i]-d[nowi]) / (2000.0/(70+weight));
            if(tmp.first < res.first) res = tmp;
        }
    }

    res.second.push_back(id[nowi]);

    return dp[nowi][used] = res;
}

int main(){
    cin >> n;
    rep(i,n){
        cin >> id[i] >> d[i] >> w[i];
        w[i] *= 20;
    }

    rep(i,n) rep(j,1<<n) dp[i][j] = PDI(INF, VI() );

    PDI ans(INF,VI());
    rep(i,n){
        PDI res = sdp(i,1<<i,w[i]);
        if(res.first < ans.first) ans = res;
    }

    reverse(ans.second.begin(), ans.second.end());

    rep(i,n-1) cout << ans.second[i] << " ";
    cout << ans.second[n-1] << endl;

    return 0;
}

