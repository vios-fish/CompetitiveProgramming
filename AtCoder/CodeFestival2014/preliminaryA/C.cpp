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

int sub(int A,int B, int d){
    int c = 0;
    if( A%d == 0 || B%d == 0) ++c;
    return c;
}

int main(){
    LLI A,B;

    cin >> A >> B;

    int Ai = ((A/4)+1)*4;
    if(A%4 == 0) Ai -= 4;
    int Bi = (B/4)*4;
    LLI cnt = (Bi-Ai)/4;
    cnt++;

//    cout << Ai << " " << Bi << endl;
//    cout << cnt << endl;

    int id = ((A/100)+1)*100;
    if( A % 100 == 0 ) id -= 100;
    for(LLI i = id; i <= B; i+=100){
        cnt--;
    }
//    cout << cnt << endl;

    id = ((A/400)+1)*400;
    if( A % 400 == 0) id -= 400;
    for(LLI i = id; i <=B; i += 400){
        cnt++;
    }

    cout << cnt << endl;
    
}

