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
    int N, T, L, B;
    while(cin >> N >> T >> L >> B, N){
        int board[200] = {0};
        int state[200] = {0};
        int lmap[200] = {0};

        rep(i,L){
            int t;
            cin >> lmap[i];
            board[lmap[i]] = 1;
        }
        rep(i,B){
            int t;
            cin >> t;
            board[t] = 2;
        }

        int size = 1;
        rep(i,T){
            size *= 6;

            rep(j,N){
                state[j] += lmap[j];
                lmap[j] = 0;
            }
            
            rep(j,N){
                state[j] = 0;
                rep(k,6){
                    int x = (N+j-(k+1))%N;
                    if(board[j] == 1){
                        lmap[j] += state[x];
                    }else if(board[j] == 2){
                        state[0] += state[x];
                    }else{
                        state[j] += state[x];
                    }
                }
            }
        }
    }
}

