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
        if(n == 0) break;

        VI b(n),c(n);
        rep(i,n) cin >> b[i];

        int cnt = 0;
        while(1){
            map<int,int> s;

            rep(i, n){
                if(s.count(b[i]) == 0){
                    s[b[i]] = 1;
                }else{
                    ++s[b[i]];
                }
            }            
            rep(i,n){
                c[i] = s[b[i]];
            }
            if(b == c) break;
            
            ++cnt;
            b = c;
        }
        cout << cnt << endl;
        rep(i,n){
            cout << (i==0?"":" ") << b[i];
        }cout << endl;
    }
}

