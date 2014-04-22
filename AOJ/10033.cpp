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

int main(){
  int n;
  cin >> n;
  vector<char> ans;
  stack<char> p[n];

  while(1){
    string com;
    cin >> com;

    if( com == "push" ){
      string s;
      char q;
      cin >> s >> q;
      int t = toInt(s)-1;
      p[t].push(q);
    }else if(com == "pop"){
      string s;
      cin >> s;
      int t = toInt(s)-1;
      ans.push_back(p[t].top());
      p[t].pop();
    }else if(com == "move"){
      string s1;
      string s2;
      cin >> s1 >> s2;
      int t1 = toInt(s1)-1;
      int t2 = toInt(s2)-1;
      char a = p[t1].top();
      p[t1].pop();
      p[t2].push(a);
    }else if(com == "quit"){
      break;
    }
  }

  for( vector<char>::iterator vci = ans.begin(); vci != ans.end(); ++vci){
    cout << *vci << endl;
  }

  return 0;
}
