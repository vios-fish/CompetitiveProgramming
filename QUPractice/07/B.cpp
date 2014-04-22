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
        int g[510][510] = {0};
        int n,m;
        cin >> n >> m;
        if(n==0 && m==0) break;

        
        rep(i,m){
            int a,b;
            cin >> a >> b;
            --a;
            --b;
            g[a][b] = 1;
            g[b][a] = 1;
        }

        int ans = 0;
        int vis[510] = {0};
        vis[0] = true;
        VI p;
        rep(i,n){
            if(g[0][i]){
                ++ans;
                p.push_back(i);
                vis[i] = true;;
            }
        }

        rep(i,p.size()){
            rep(j,n){
                if(g[p[i]][j] && !vis[j]){
                    ++ans;
                    vis[j] = true;
                }
            }
        }

        cout << ans << endl;
    }
}

