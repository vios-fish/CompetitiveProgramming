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

using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

#define reep(i,a,b) for( int i = (int)(a); i < (int)(b); ++i)
#define rep(i,n) reep(i,0,n)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define DEBUG(x) cerr << #x << " = " << (x) << "(L" << __LINE__ << ")" << __FILE__ << endl;
#define DUMPA(a, n) cerr << #a << " = {" << a[0]; reep(itr, 1, n) { cout << ", " << a[itr]; } cerr << "}" << endl;
#define DUMPAA(a, n, m) rep(itr, n) {rep(jtr, m) {cout << a[itr][jtr] << " ";} cout << endl;}
#define pb push_back
#define mp make_pair
#define SQR(x) ((x)*(x))
#define SIZE(x) ((int)x.size())
#define ALL(x)  x.begin(),x.end()

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

int main(){
    string ss = "1992";
    cout << toInt(ss.substr(0,4)) << endl;
    int a = 1000;
    string str = toString(a);
}

