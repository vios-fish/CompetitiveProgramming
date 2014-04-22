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

int DP[100];
int dn[] = {2,3,5,10,12,15};

int hoge( int m){
    if( DP[m] != 100000000) return DP[m];
    
    rep(i,6){
        if( m-dn[i] <= 1 ) break;
        DP[m] = min( DP[m], hoge(  m-dn[i] ) + DP[dn[i]] );
    }

    return DP[m];
}

int main(){
    fill( DP,DP+100,100000000 );
    
    DP[2] =380;
    DP[3]=550;
    DP[5]=850;
    DP[10]=380*5*0.8;
    DP[12]=550*4*0.85;
    DP[15]=850*3*0.88;

    int a;
    while(1){
        cin >> a;
        if(a==0) break;
        cout << hoge(a/100) << endl;
        
    }

    
}

