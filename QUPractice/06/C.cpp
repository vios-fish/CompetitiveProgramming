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

int main(){
    while(1){
        int d, n, m;

        cin >> d;
        if(d == 0) break;
        cin >> n >> m;
        VI S(100000);
        VI Sr(100000);
        S[0] = Sr[0] = 0;
        rep(i,n-1){
            cin >> S[i+1];
            Sr[i+1] = S[i+1];
        }
        sort(S.begin(), S.end());
        int cost[100000];

        int ans = 0;
        rep(i,m){
            int a;
            cin >> a;
            VI::iterator b = lower_bound(S.begin(), S.end(), a);
            if( b==S.end() ){
                ans += min(a-*(b-1), d-a);
            }else{
                ans += min(abs(*b-a), abs(*(b-1)-a));
            }
        }

        cout << ans << endl;
    }
}

