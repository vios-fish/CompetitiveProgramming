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

int tile[25][25];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int serch(int x, int y){
    int res = 1;
    tile[x][y] = 1;
    rep(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( tile[nx][ny] == 0) res += serch(nx, ny);
    }
    return res;
}

int main(){
    int W, H;
    while(cin >> W >> H, W){
        char mc[255];
        mc['.'] = 0;
        mc['#'] = 1;
        mc['@'] = 0;

        rep(i,25) rep(j,25) tile[i][j] = 1;

        int sx, sy;

        rep(i,H){
            string ss;
            cin >> ss;
            rep(j,W){
                tile[j+1][i+1] = mc[ss[j]];
                if( ss[j] == '@'){
                    sx = j+1;
                    sy = i+1;
                }
            }
        }

        cout << serch(sx, sy) << endl;
    }
}

