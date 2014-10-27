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
#define rreep(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define rrep(i,n) rreep(i,n,0)
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

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
int board[8][8] = {0};

inline bool isRange(int x, int y){
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void print(){
    char m[] = {".ox"};
    rep(i,8){
        rep(j,8)
            cout << m[board[j][i]];
        cout << endl;
    }
}

int search(const int x, const int y, const int p, const int d, const int num, const bool change = false){
    if(!isRange(x,y) || board[x][y] == 0) return 0;
    if(board[x][y] == p) return num;
    int res = search(x+dx[d], y+dy[d], p, d, num+1, change);
    if(change && res != 0) board[x][y] = p;
    
    return res;
}

int Put(const int p){
    int res = 0;
    int ax, ay;
    rep(y,8){
        rep(x,8){
            if(board[x][y] != 0) continue;
            int num = 0;
            rep(k,8){
                num += search(x+dx[k], y+dy[k], p, k, 0);
            }
            
            if(num > 0 && res-p+1 < num){
                res = num;
                ax = x;
                ay = y;
            }
        }
    }
    
    if(res > 0){
        rep(i,8) search(ax+dx[i], ay+dy[i], p, i, 0, true);
        board[ax][ay] = p;
    }
    
    return res;
}


int main(){
    rep(i,8){
        string ss;
        cin >> ss;
        rep(j,8){
            if(ss[j] == '.') board[j][i] = 0;
            if(ss[j] == 'o') board[j][i] = 1;
            if(ss[j] == 'x') board[j][i] = 2;
        }
    }

    int choco, cheese;
    do{
        choco = Put(1);
        cheese = Put(2);
    }while(choco != 0 || cheese != 0);

    print();
}

