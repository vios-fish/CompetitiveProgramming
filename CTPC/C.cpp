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
    int n;
    cin >> n;

    string aaa;
    getline(cin, aaa);

    int cnt = 0;
    int tcnt = 0;
    rep(i,n){
        string ss;
        getline(cin, ss);
        if( ss.length() <= 140 && ss.length() >= 1 ){
            ++tcnt;
            if( ss[0] == '@' ){
                ++cnt;
            }
        }
    }

    if( tcnt == 0 ){
        cout << "Tweet:NA Reply:NA" << endl;
    }
    else {
        cout << "Tweet:"<< (tcnt-cnt)*100/tcnt <<" Reply:" << (cnt*100/tcnt) << endl;
    }

    return 0;
}

