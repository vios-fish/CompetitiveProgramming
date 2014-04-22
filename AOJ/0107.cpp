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
#include <algorithm>

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
        int a[3];
        rep(i,3) cin>>a[i];

        if(a[0] == 0 && a[1] == 0 && a[2] == 0) break;

        sort(a,a+3);

        double rm = sqrt( a[0]*a[0] + a[1]*a[1] )/2.0;

        int n;
        cin >> n;
        rep(i,n){
            int r;
            cin >> r;
        
            if(r > rm) cout << "OK" << endl;
            else cout << "NA" << endl;
        }
    }
}

