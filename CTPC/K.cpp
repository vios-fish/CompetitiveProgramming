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
    bitset<10000000> prime;
    prime.set();
    prime[1] = 0;
    prime[0] = 0;

    int sl = sqrt(1000000);
    reep(i,2,sl){
        if( prime[i] == 1 ){
            for( int j = 2; i*j < 10000000; ++j){
                prime[i*j] = 0;
            }
        }
    }

    map<int,int> m;

    long long int num = 1;
    rep(i,10000000){
        if( prime[i] ){
            num *= i;
            num %= 1000000;
            m[num] = 1;
        }
    }

    int t;
    cin >> t;
    rep(i,t){
        int a;
        cin >> a;
        if( m[a] == 1 ){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}

