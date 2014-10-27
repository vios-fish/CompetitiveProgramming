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

const int INF = 1e6;


void solve(VI& a, VI& ans){
    stack<pair<int,int>> S;
    int N = ans.size();
    rep(i,N){
        while(!S.empty() && S.top().first <= a[i]) S.pop();
        if(S.empty()){
            ans[i] += i;
        }else{
            ans[i] += i - S.top().second - 1;
        }
        S.emplace(a[i],i);
    }
}

int main(){
    int N;
    cin >> N;
    VI h(N);
    VI cnt(N,0);
    for(int i = 0; i < N; ++i){
        cin >> h[i];
    }

    solve(h, cnt);
    reverse(ALL(h));
    reverse(ALL(cnt));
    solve(h, cnt);
    reverse(ALL(cnt));
    
    rep(i,N) cout << cnt[i] << endl;
    
    return 0;
}

