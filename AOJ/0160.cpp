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

int main(){
    while(1){
        int n;
        cin >> n;
        if( n == 0 )break;

        int r[] = { 600, 800, 1000, 1200, 1400, 1600, 0 };
        int ans = 0;

        rep(i,n){
            int x,y,h,w;
            cin >> x >> y >> h >> w;

            int len = x+y+h;
            int size;

            if( len <= 60 ) size = 0;
            else if( len <= 80 ) size = 1;
            else if( len <= 100 ) size = 2;
            else if( len <= 120 ) size = 3;
            else if( len <= 140 ) size = 4;
            else if( len <= 160 ) size = 5;
            else size = 6;

            if( w <= 2 ) size       = max(0,size);
            else if( w <= 5 ) size  = max(1,size);
            else if( w <= 10 ) size = max(2,size);
            else if( w <= 15 ) size = max(3,size);
            else if( w <= 20 ) size = max(4,size);
            else if( w <= 25 ) size = max(5,size);
            else size = max(6,size);

            ans += r[size];
        }

        cout << ans << endl;
    }
}

