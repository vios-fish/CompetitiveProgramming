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
#include <cstdio>
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
    int m,n;
    bool prime[150000] = {false};
    int mat[600][600];
    prime[1] = prime[0] = 1;
    reep(i,2,100050){
        if(!prime[i]){
            for(int j=2;j*i<100050;++j) prime[j*i] = 1;
        }
    }

    scanf("%d %d",&n,&m);
    rep(i,n) rep(j,m) scanf("%d",&mat[i][j]);

    int r[600], c[600];
    int tmp[600][600] = {0};

    rep(i,n) rep(j,m){
        int cnt = 0;
        reep(k,mat[i][j],150000){
            if(!prime[k]) break;
            ++cnt;
        }
        tmp[i][j] = cnt;
    }

    rep(i,n) rep(j,m) r[i] += tmp[i][j];
    rep(i,m) rep(j,n) c[i] += tmp[j][i];
    
    sort(r,r+n);
    sort(c,c+m);
    
    printf("%d\n",min(r[0],c[0]));
}
