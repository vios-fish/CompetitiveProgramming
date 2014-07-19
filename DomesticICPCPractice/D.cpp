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
#define lengthof(x) (sizeof(x)/sizeof(*(x)))

#define ALL(a) begin(a),end(a)

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long int LLI;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

struct stat{
    int p,t,c;
    bool operator<(const stat st) const {
        return this->c < st.c;
    }
};

int N,M,H,K;
int c[101][101];
int h[101][101];
int r[101][101];

typedef PII Vertex;
typedef pair<int,Vertex> State;

int dijkstra(int s, int t, int kai){
    priority_queue<State> pq;
    map<Vertex,int> visit;

    int ans = 1<<28;
    pq.push(State(0,Vertex(s,0)));
    while(!pq.empty()){
        State st = pq.top();pq.pop();
        Vertex v = st.second;
        int cost = st.first;
        if(visit.find(v) != visit.end()) continue;
        visit[v] = cost;
        int d = v.first;

        if(d == t){
            ans = cost;
            break;
        }

        rep(i,N){
            if(c[d][i] != -1){
                if( v.second+h[d][i] > H) continue;
                int tmp = c[d][i];
                if( kai & 1<<(r[d][i]-1) ){
                    tmp = 0;
                }
                pq.push(State(tmp+cost,Vertex(i,v.second+h[d][i])));
            }
        }
    }

    return ans;
}

int main(){
    while(cin >> N >> M >> H >> K, N){
        fill((int*)c, (int*)(c+lengthof(c)), -1);
        fill((int*)h, (int*)(h+lengthof(h)), -1);
        fill((int*)r, (int*)(r+lengthof(r)), -1);
        
        rep(i,N){
            int a,b;
            cin >> a >> b >> c[a][b] >> h[a][b] >> r[a][b];
        }

        int s,t,P;
        cin >> s >> t >> P;

        VI kai(P);
        VI d(P);
        rep(i,P){
            int l;
            cin >> l >> d[i];
            kai[i] = 0;
            rep(j,l){
                int a;
                cin >> a;
                kai[i] |= 1<<(a-1);
            }
        }
        
        int dp[1<<8];
        fill(ALL(dp),1<<28);
        dp[0] = 0;
        rep(i,P){
            for(int j=0; j<(1<<8); ++j){
                dp[j|kai[i]] = min(dp[j]+d[i], dp[j|kai[i]]);
            }
        }

        rep(i,1<<8) cout << i << " " << dp[i] << endl;;

        int ans = dijkstra(s, t, 0);
        cout << ans << endl;
        rep(i,1<<8){
            if(dp[i] == 1<<28) continue;
            ans = min(ans, dp[i]+dijkstra(s, t, i));
        }

        cout << ans << endl;
    }
}

