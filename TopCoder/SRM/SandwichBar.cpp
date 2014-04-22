#line 2 "SandwichBar.cpp"
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

#define FOR(i,a,b) for( int i = (a); i < (int)(b); ++i)
#define rep(i,n) FOR(i,0,n)

typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
typedef pair<int, int> PII;

inline int toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

class SandwichBar {
public:
	int whichOrder( vector <string> available, vector <string> orders ) {
		int result = -1;
        rep(i, orders.size()){
            VS ss;
            string s = "";
            rep(j, orders[i].size()){
                if( orders[i][j] == ' ' ){
                    if( s != "") ss.push_back(s);
                    s = "";
                }else{
                    s = s + orders[i][j];
                }
            }
            ss.push_back(s);

            bool f = false;
            rep(j, ss.size()){
                int pos = -1;
                rep(k, available.size()){
                    if(ss[j] == available[k]){
                        pos = k;
                        break;
                    }
                }
                if(pos == -1){
                    f = true;
                    break;
                }
            }
            if(!f){
                result = i;
                break;
            }
        }

		return result;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string available[]        = { "ham", "cheese", "mustard" };
			string orders[]           = { "ham cheese" };
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = SandwichBar().whichOrder(vector <string>(available, available + (sizeof available / sizeof available[0])), vector <string>(orders, orders + (sizeof orders / sizeof orders[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string available[]        = { "cheese", "mustard", "lettuce" };
			string orders[]           = { "cheese ham", "cheese mustard lettuce", "ketchup", "beer" };
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SandwichBar().whichOrder(vector <string>(available, available + (sizeof available / sizeof available[0])), vector <string>(orders, orders + (sizeof orders / sizeof orders[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string available[]        = { "cheese", "cheese", "cheese", "tomato" };
			string orders[]           = { "ham ham ham", "water", "pork", "bread", "cheese tomato cheese", "beef" };
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SandwichBar().whichOrder(vector <string>(available, available + (sizeof available / sizeof available[0])), vector <string>(orders, orders + (sizeof orders / sizeof orders[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string available[]        = { "foo", "bar", "baz", "gazonk", "quux", "bat", "xyzzy",
  "shme", "hukarz", "grault", "waldo", "bleh" };
			string orders[]           = { "kalatehas", "spam eggs", "needle haystack", "bleh blarg", "plugh", 
  "the best sandwich in the universe" };
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = SandwichBar().whichOrder(vector <string>(available, available + (sizeof available / sizeof available[0])), vector <string>(orders, orders + (sizeof orders / sizeof orders[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string available[]        = ;
			string orders[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SandwichBar().whichOrder(vector <string>(available, available + (sizeof available / sizeof available[0])), vector <string>(orders, orders + (sizeof orders / sizeof orders[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string available[]        = ;
			string orders[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SandwichBar().whichOrder(vector <string>(available, available + (sizeof available / sizeof available[0])), vector <string>(orders, orders + (sizeof orders / sizeof orders[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string available[]        = ;
			string orders[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SandwichBar().whichOrder(vector <string>(available, available + (sizeof available / sizeof available[0])), vector <string>(orders, orders + (sizeof orders / sizeof orders[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
