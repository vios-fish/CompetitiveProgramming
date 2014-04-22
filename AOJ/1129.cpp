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

#define DUMPA(a,n) cout<<(#a)<<" = { "<<a[0];reep(i,1,n) cout<<", "<<a[i];cout<<" }"<<endl;

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

int main(){
    while(1){
        int n,r;
        int card[100];
    
        cin >> n >> r;

        if(n == 0 && r == 0) break;

        rep(i,n) card[i] = n-i;

        rep(i,r){
            int c,p;
            cin >> p >> c;

            int a[100];
            rep(j,c){
                a[j] = card[p-1+j];
            }
            rep(j,p){
                card[p+c-j-2] = card[p-j-2];
            }
            rep(j,c){
                card[j] = a[j];
            }
        }


        cout << card[0] << endl;
    }
}

