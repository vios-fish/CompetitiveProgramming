// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysCheckers.cpp"
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

#define FOR(i,a,b) for( int i = (a); i < (b); ++i)
#define rep(i,n) FOR(i,0,n)

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

class EllysCheckers {
    public:
    string getWinner(string board) {
        string result;


        return result;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    EllysCheckers __test;
    __test.run_test(-1);
}

// END CUT HERE
