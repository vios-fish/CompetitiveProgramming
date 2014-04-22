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

int N,M;
int h[1500],w[1500];

int main(){
    while(1){
        cin >> N >> M;
        if(N==0&&M==0) break;
        rep(i,N) cin >> h[i];
        rep(i,M) cin >> w[i];

        multiset<int> hms,wms;

        rep(i,N){
            int t=h[i];
            reep(j,i,N){
                if(i!=j) t += h[j];
                hms.insert(t);
            }
        }

        rep(i,M){
            int t=w[i];
            reep(j,i,M){
                if(i!=j) t += w[j];
                wms.insert(t);
            }
        }

        multiset<int>::iterator itw,ith;
        ith = hms.begin();
        itw = wms.begin();

        int ans = 0;
        while(1){
            if(ith == hms.end() || itw == hms.end()) break;

            int num = max(*itw,*ith);
            while(ith != hms.end() && num > *ith) ++ith;
            while(itw != wms.end() && num > *itw) ++itw;
            

            if(*ith == *itw){
                int cw,ch;
                cw = ch = 0;
                while(itw != wms.end() && num == *itw) cw++,itw++;
                while(ith != hms.end() && num == *ith) ch++,ith++;
                ans += cw * ch;
            }
        }

        cout << ans << endl;
    }
        
}

