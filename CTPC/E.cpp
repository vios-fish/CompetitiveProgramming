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


int graph[20][20];
int n;
const int MAX_VALUE = 1000000;

bool dijkstra(void) {
  int min = MAX_VALUE;

  int preview[20];
  bool visited[20];
  int distance[20];

  for (int i = 0; i < n; i++)
    visited[i] = false, distance[i] = MAX_VALUE;
  distance[0] = 0;
  preview[0] = 0; 

  int next = 0, p = 0;

  do {
    p = next;
    visited[p] = true;
    min = MAX_VALUE;

    for (int j = 0; j < n; j++) {
      if (visited[j]) continue;
      if (graph[p][j] < MAX_VALUE &&
          distance[p] + graph[p][j] < distance[j]){
        distance[j] = distance[p] + graph[p][j];
        preview[j] = p;
      }
      if (distance[j] < min) {
        next = j;
        min = distance[j];
      }
    }
  } while (min < MAX_VALUE);

/*  cout << "point" << " preview" << " distance" << endl;
  for (int i = 0; i < n; i++) {
    cout << i << "      " << preview[i] << "        " << distance[i] << endl;
  }
*/

  rep(i,n){
      if( distance[i] != 0 ){
          return false;
      }
  }
  return true;
}


int main(){
    map<string,int> m;

    cin >> n;
    rep(i,n){
        string ss;
        cin >> ss;
        m[ss] = i;
    }

    int l;
    cin >> l;

    rep(i,20)rep(j,20)graph[i][j] = 1;
    
    rep(i,l){
        string ss1,ss2;
        cin >> ss1 >> ss2;

        if( graph[m[ss1]][m[ss2]] == 5 || ss1 == ss2 ){
            cout << "No" << endl;
            return 0;
        }

        graph[m[ss1]][m[ss2]] = 0;
        graph[m[ss2]][m[ss1]] = 5;
    }

/*    rep(i,n){
        rep(j,n){
            rep(k,n){
                if( graph[j][k] > graph[j][i] + graph[i][k] ){
                    graph[j][k] = graph[j][i] + graph[i][k];
                }
            }
        }
    }
*/
    if(dijkstra()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
/*    
    rep(i,n){
        if( graph[i][i] != 0 ){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
*/
    
}

