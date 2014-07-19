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
#define DUMPAA(a) for(auto &x:a){for(auto &y:x){cout << y << " ";} cout << endl;}
#define ALL(a) begin(a),end(a)

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long int LLI;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

int main(){
    int W,H;

    while(cin >> W >> H, W){
        bool maze[2][31][31] = {0};
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        rep(i,2*H-1){
            if(i%2 == 0){
                rep(j,W-1) cin >> maze[1][j][i];
            }else{
                rep(j,W) cin >> maze[0][j][i];
            }
        }

        int map[31][31][4] = {0};
        rep(i,W){
            rep(j,H){
                rep(k,4){
                    if(i+dx[k] < 0 || i+dx[k] >= W || j+dy[k] < 0 || j+dy[k] >= H){
                        map[i][j][k] = 1;
                    }else{
                        if(k == 0 || k == 1){
                            map[i][j][k] = maze[k%2][j][i];
                        }else if(k == 2 || k == 3){
                            map[i][j][k] = maze[k%2][j+dy[k]][i+dx[k]];
                        }
                    }
                }
            }
        }

        rep(i,W){
            rep(j,H){
                cout << "{";
                rep(k,4) cout << map[i][j][k] << ",";
                cout << "} ";
            }
            cout << endl;
        }

        struct S{int x,y,cost;};

        queue<S> Q;
        int visited[30][30];
        
        fill(begin(visited[0]), end(visited[29]), -1);
        Q.push(S{0,0,1});
        int ans = 0;
        while(!Q.empty()){
            S st = Q.front(); Q.pop();
            if(visited[st.x][st.y] != -1) continue;
            visited[st.x][st.y] = st.cost;

            rep(i,4){
                if(map[st.x][st.y][i] == 0){
                    if(st.x+dx[i] == W-1 && st.y+dy[i] == H-1){
                        ans = st.cost+1;
                        break;
                    }
                    Q.push(S{st.x+dx[i],st.y+dy[i],st.cost+1});
                }
            }
            if(ans != 0) break;                
        }

        DUMPAA(visited);
        
        cout << ans << endl;
    }
}
