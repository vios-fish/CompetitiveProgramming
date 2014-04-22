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

int R;
int W[2], H[2];
int X[2], Y[2];
int m[2][600][600];
int ans;
VI cost[2];
bool visited[2][600][600] = {0};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int search(int r, int y, int x, int k){

//    cout << r << " " << y << " " << x << " " << k << endl;
    if( m[k][y][x] == -1) return 0;
    if( m[k][y][x] > r) return 0;
    if(visited[y][x]) return 0;
    visited[k][y][x] = 1;
    rep(i,4){
        visited[k][y][x] += search(r, y+dy[i], x+dx[i], k);
    }

    return visited[k][y][x];
        
}

    
int canR[2][500*500] = {0};

int main(){
    while(1){
        rep(k,600)rep(l,600) m[0][k][l] = m[1][k][l] = -1;
        cin >> R;
        if(R == 0) break;
        rep(i,2){
            cin >> W[i] >> H[i] >> X[i] >> Y[i];

            rep(j,H[i]){
                rep(k,W[i]){
                    cin >> m[i][j+1][k+1];
                    cost[i].push_back(m[i][j+1][k+1]);
                }
            }

            cost[i].push_back(0);
        }

        rep(i,2) sort(cost[i].rbegin(), cost[i].rend());

        rep(i,2){
            int t = cost[i].size();
            rep(j,t+1){
                canR[i][j] = -1;
            }
        }
    
        rep(i,2){
            int j = 0;
            FOREACH(it,cost[i]){
                rep(k,600)rep(l,600) visited[k][l] = 0;
                if(canR[i][j] != -1) continue;
                canR[i][j] = search((*it), Y[i], X[i], i);
                ++j;
            }
        }

        int answer = 100000000;

        int k = 0;
        FOREACH(i,cost[0]){
            int c = (*i);
            int l = 0;
            FOREACH(j,cost[1]){
                int d = (*j);
                if( canR[0][k] + canR[1][l] >= R ){
                    answer = min(answer, c+d);
                }
                ++l;
            }
            ++k;
        }
        cout << answer << endl;
    }
}

