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

int main(){
    int n;
    while(cin >> n ,n){
        int cnt = 0;
        
        bool l,r;
        l = r = false;
        bool foot = 0;
        
        rep(i,n){
            string ss;
            cin >> ss;
            bool check = false;
            
            if(ss == "lu"){
                if(foot == 0) check = true;
                foot = 1;
                l=true;
            }else if(ss == "ld"){
                if(foot == 0) check = true;
                foot = 1;
                l=false;
            }else if(ss == "ru"){
                if(foot == 1) check = true;
                foot = 0;
                r=true;
            }else if(ss == "rd"){
                if(foot == 1) check = true;
                
                foot = 0;
                r= false;
            }

            if(l == r && check){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}

