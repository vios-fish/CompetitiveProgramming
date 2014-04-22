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
        int n;
        cin >> n;
        if(n==0) break;
        
        VI f[60];
        rep(i,n){
            int m;
            cin >> m;
            rep(j,m){
                int a;
                cin >> a;
                f[i].push_back(a);
            }
            sort(f[i].begin(), f[i].end());
        }

        VI g[40];
        rep(i,n){
            rep(j,f[i].size()){
                g[f[i][j]].push_back(i);
            }
        }

        bool m[50][50] = {0};

        rep(i,n) m[i][i] = true;
        
        int ans = -1;
        rep(i,31){
            if( g[i].size() >= 2){
                rep(j,g[i].size()){
                    rep(k,g[i].size()){
                        rep(l,n){
                            m[g[i][j]][l] |= m[g[i][k]][l];
                            m[g[i][j]][l] = m[g[i][j]][l];
                        }
                    }
                }
            }
            rep(k,n){
                int cnt = 0;
                rep(j,n){
                    cnt += m[k][j];
                }
                if(cnt == n){
                    ans = i;
                    break;
                }
            }
            if(ans!=-1) break;
        }
        cout << ans << endl;
    }
}

