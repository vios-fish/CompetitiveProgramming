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
#include <random>

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
    random_device seed_gen;
    mt19937 engine(seed_gen());

    uniform_int_distribution<> dist1(0,2);
    uniform_int_distribution<> dist2(0,1);
    
    int s[3] = {0};
    int a[3][2] = {{0}};
    string sa[3][2] = {{"亀津", "野口"}, {"井手", "杉本" },{"徳永","松村"}};
    rep(i,3){
        int r = dist1(engine);
        while(s[r] != 0) r = dist1(engine);
        s[r] = 1;
        rep(j,2){
            int t = dist2(engine);
            while(a[r][t] != 0) t = dist2(engine);
            a[r][t] = 1;
            cout << i*2+j+1 << " " << sa[r][t] << endl;
        }
    }
}

