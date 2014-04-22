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
	int n,m;
	string s;

	int cntioi = 0;
	int ans = 0;

	cin >> n;
	if(n == 0) break;
	cin >> m >> s;

	rep(i,m){
	    if(cntioi == 0){
		if(s[i] == 'I' && i < m-2){
		    if(s[i+1] == 'O' && s[i+2] == 'I'){
			++cntioi;
			i+=2;
		    }
		}
	    }else{
		if(s[i] == 'O' && s[i+1] == 'I'){
		    ++cntioi;
		    i+=1;
		}else{
		    if(cntioi >= n) ans += cntioi - n +1;
		    cntioi = 0;
		    i-=1;
		}
		    
	    }
	}
	if(cntioi >= m) ans += cntioi-n+1;
	cout << ans << endl;
    }
    return 0;
}

