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

const double EPS = 1e-14;
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
    int x0, y0, vx, vy, vh;

    cin >> x0 >> y0 >> vx >> vy >> vh;

    double a = vx*vx + vy*vy - vh*vh;
    double b = vx*x0 + vy*y0;
    double c = x0*x0 + y0*y0;

    double D = b*b - a*c;

    if(abs(a) < EPS){
        if( abs(b) < EPS ){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << -c/(2*b) << endl;
        }
    }else if(abs(D) < EPS){
        if(-b/a < EPS){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << -b/a << endl;
        }
    }else if(D < -EPS){
        cout << "IMPOSSIBLE" << endl;
    }else{
        double p = (-b+sqrt(D))/a;
        double q = (-b-sqrt(D))/a;

        if(p < q) swap(p,q);

        if(p < EPS){
            cout << "IMPOSSIBLE" << endl;
        }else{
            if(q > EPS){
                cout << q << endl;
            }else{
                cout << p << endl;
            }
        }
    }
}

