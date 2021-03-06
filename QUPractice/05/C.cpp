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
    int n,k;

    int m;
    cin >> m;
    rep(i,m){
        VI v;
        cin >> n >> k;
        int pnum,num;
        int fi,la;
        
        rep(j,n){
            cin >> num;
            if(j != 0){
                v.push_back(num-pnum);
            }
            if(j == 0) fi = num;
            if(j == n-1) la = num;
            pnum = num;
        }

        if(n <= k){
            cout << 0 << endl;
            continue;
        }
        
        int sum = la - fi;

        sort(v.rbegin(),v.rend());
        
        rep(j,k-1){
            sum -= v[j];
            if(sum < 0) break;
        }

        cout << (sum<0?0:sum) << endl;
    }
}

