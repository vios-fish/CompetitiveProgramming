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
    string s[3];
    rep(i,3) cin >> s[i];
    int N = s[0].size()/2;

    VI cnt[3];
    fill(ALL(cnt),VI(26,0));

    rep(i,3){
        rep(j,s[i].size()){
            cnt[i][s[i][j]-'A']++;
        }
    }

    bool f = true;
    int must1 = 0, must2 = 0;
    rep(i,'Z'-'A'){
        if(cnt[2][i] > cnt[0][i]+cnt[1][i]){
            f = false;
            break;
        }
        must1 += max(0, cnt[2][i] - cnt[1][i]);
        must2 += max(0, cnt[2][i] - cnt[0][i]);
    }

    if( f && must1 <= N && must2 <= N) cout << "YES" << endl;
    else cout << "NO" << endl;
}

