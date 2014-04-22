// BEGIN CUT HERE

// END CUT HERE
#line 5 "NoRepeatPlaylist.cpp"
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

#define FOR(i,a,b) for( int i = (a); i < int(b); ++i)
#define rep(i,n) FOR(i,0,n)

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}


int X = 1000000007;

class NoRepeatPlaylist {
    public:
    int numPlaylists(int N, int M, int P) {
        int result = 1;

        rep( i, P ){
            int pos = min(P-i,N) - min(i, M);
            // dump( pos );
            result *= pos;
            result %= X;
        }
            
        if( P > N ) result += N;
        
        return result;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(0, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 4; int Arg3 = 24; verify_case(3, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(4, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 5; int Arg2 = 100; int Arg3 = 222288991; verify_case(5, Arg3, numPlaylists(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    NoRepeatPlaylist __test;
    __test.run_test(-1);
}

// END CUT HERE
