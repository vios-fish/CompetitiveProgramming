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
#include <unordered_map>

using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

#define reep(i,a,b) for( int i = (int)(a); i < (int)(b); ++i)
#define rep(i,n) reep(i,0,n)
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

struct S{
    int depth;
    string ss;
};

int main(){
    string sin;
    char cm[] = {'r','g','b'};
    char m[256][256];

    rep(i,3) rep(j,3)
        if(i != j) m[cm[i]][cm[j]] = cm[3-(i+j)];
    
    while(cin >> sin, sin != "0"){
        queue<S> qs;
        unordered_map<string,bool> usb;
        bool f = false;
        int ans = 0;
        
        qs.push(S{0,sin});
        while(!qs.empty()){
            S x = qs.front();
            qs.pop();

            ans = x.depth;

            if( usb.find(x.ss) != usb.end() ) continue;
            usb[x.ss] = 1;

            f = false;
            rep(i,x.ss.size()-1){
                if(x.ss[i] != x.ss[i+1]){
                    f = true;
                    break;
                }
            }
            if(!f) break;

            rep(i,x.ss.size()-1){
                if( x.ss[i] == x.ss[i+1]) continue;
                string tmp = x.ss;
                tmp[i] = tmp[i+1] = m[x.ss[i]][x.ss[i+1]];
                qs.push(S{x.depth+1,tmp});
            }
        }
        if(!f) cout << ans << endl;
        else cout << "NA" << endl;
    }
}

