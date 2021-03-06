#include <iostream>
#include <cstdlib>
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

using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << "(L" << __LINE__ << ")" << __FILE__ << endl;

#define reep(i,a,b) for( int i = (int)(a); i < (int)(b); ++i)
#define rep(i,n) reep(i,0,n)

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

const int dx[] = {0,0,1,0,-1};
const int dy[] = {0,-1,0,1,0};

int main(){
    while(1){
        int w,h;
        bool visit[120][120] = {0};
        int field[120][120] = {0};

        

        cin >> h >> w;

        if(h==0 && w==0) break;

        rep( y, h ){
            string ss;
            cin >> ss;
            rep( x, w ){
                int a = 0;
                if( ss[x] == '^' ) a=1;
                if( ss[x] == '>' ) a=2;
                if( ss[x] == 'v' ) a=3;
                if( ss[x] == '<' ) a=4;
                field[x][y] = a;
            }
        }

        int posx = 0;
        int posy = 0;
        while(1){
            int x = posx, y = posy;
            if(field[x][y] == 0){

                cout << x << " " << y << endl;
                break;
            }
            if(visit[x][y]){
                cout << "LOOP" << endl;
                break;
            }
            visit[x][y] = true;

            posx += dx[field[x][y]];
            posy += dy[field[x][y]];
        }
    }
}

