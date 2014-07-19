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

int num = 0;
bool hoge(int val){
    return (val % num);
}

int main(){
    bool isPrime[1000];
    fill(ALL(isPrime), true);

    const double up = sqrt(1000);
    isPrime[0] = isPrime[1] = false;
    rep(i,1000){
        if(isPrime[i]){
            for(int j=2;j*i<1000;++j){
                isPrime[i*j] = false;
            }
        }
    }

    int ans = 1;
    num = 0;
    vector<int> vi;
    rep(i,1000) vi.push_back(i+1);
    while(1){
        while(!isPrime[num] && num < 1000) ++num;
        if(num >= 1000) break;

        printf("? %d\n", num); fflush(stdout);
        char judge[2];
        scanf("%s", judge);

        if(judge[0] == 'Y'){
            if(num > 500){
                ans = num;
                printf("! %d\n", ans);
                return 0;
            }

            vi.erase(remove_if(vi.begin(), vi.end(), hoge), vi.end());
            ans = num;
        }
        ++num;
    }

    if( ans == 1 ){
        printf("! %d\n", ans);
        return 0;
    }

    auto x = vi.begin();
    while(x < vi.end()){
//        if( x >= vi.end()) x = vi.begin();
        printf("? %d\n", *x); fflush(stdout);
        char judge[2];
        scanf("%s", judge);

        if(judge[0] == 'Y'){
            num = *x;
            vi.erase(remove_if(vi.begin(), vi.end(), hoge), vi.end());
            ans = num;
        }else{
//            vi.erase(remove(vi.begin(), vi.end(), *x), vi.end());
        }

        ++x;
    }

    printf("! %d\n", ans);
        
}

