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

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

int main(){
    int n;
    int cnt = 0;

    while(1){
        int m[4] = {10,50,100,500};
        int c[4];
        cin >> n;
        if(n==0) break;
        rep(i,4) cin >> c[i];
        
        int sum = 0;
        rep(i,4) sum += m[i]*c[i];

        int o = sum - n;

        int used[4] = {0};
        
        for(int i=3;i>=0;--i){
            for(int j=0;o>=m[i];++j){
                o -= m[i];
                used[i]++;
            }
        }

        if(cnt != 0) cout << endl;
        rep(i,4){
            if(c[i] > used[i]){
                cout << m[i] << " " << c[i]-used[i] << endl;
            }
        }
        ++cnt;
    }
}

