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

int main()
{
    int n,m;
    VI pre[20], lat[20];
    int s[20] = {0};
    map<int,int> mp;

    
    
    cin >> n >> m;

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        s[a]++;
        pre[a].push_back(b);
        lat[b].push_back(a);
    }

    stack<int> si;
    while(1){
        if(mp.size() == n) break;
        rep(i,n){
            if(s[i] == 0){
                s[i] = -1;
                mp[i] = 1;
                si.push(i+1);
            }
        }

        
        for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
            if( (*it).second == 1){
                FOREACH(iv,lat[(*it).first]){
                    s[(*iv)]--;
                }
            }
            (*it).second++;
        }
    }

    rep(i,n){
        cout << si.top() << endl;
        si.pop();
    }
}
