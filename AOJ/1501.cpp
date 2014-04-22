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

#define MOD 100000007
const int INF = 1<<29;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int sp[1010][1010] = {0};
int mem[1010][1010];

struct M{
    int x,y;
    M(int a=0, int b=0): x(a), y(b){}
};

int r, c, a1, a2, b1, b2;

int serch(int x, int y){
    if(mem[x][y] != -1) return mem[x][y];

    int res = 0;
    rep(i,4){
        int nx = (x + dx[i] + r)%r;
        int ny = (y + dy[i] + c)%c;
        if(sp[nx][ny] < sp[x][y]) res += serch(nx, ny);
    }

    return mem[x][y] = res%MOD;
}

int main(){

    cin >> r >> c >> a1 >> a2 >> b1 >> b2;

    rep(i,r) rep(j,c) sp[i][j] = INF;
    rep(i,r) rep(j,c) mem[i][j] = -1;
    
    queue<M> qm;
    qm.push(M(a1,a2));
    sp[a1][a2] = 0;
    while(!qm.empty()){
        M nm = qm.front();
        qm.pop();

        rep(i,4){
            int nx = (nm.x + dx[i] + r)%r;
            int ny = (nm.y + dy[i] + c)%c;
            if(sp[nx][ny] == INF){
                sp[nx][ny] = sp[nm.x][nm.y] + 1;
                qm.push(M(nx,ny));
            }
        }
    }

    mem[a1][a2] = 1;
    cout << serch(b1, b2) << endl;
    
}

