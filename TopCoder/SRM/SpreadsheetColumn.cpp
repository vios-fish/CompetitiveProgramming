#line 2 "SpreadsheetColumn.cpp"
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

class SpreadsheetColumn {
public:
	string getLabel( int column ) {
		string result = "";

        if( column > 26 )
            result += ('A'+(((column-1)/26)-1));
        
        result += ('A'+((column-1)%26));
        
        

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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int column                = 1;
			string expected__         = "A";

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int column                = 2;
			string expected__         = "B";

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int column                = 27;
			string expected__         = "AA";

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int column                = 111;
			string expected__         = "DG";

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int column                = 702;
			string expected__         = "ZZ";

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int column                = 26;
			string expected__         = "Z";

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int column                = 53;
			string expected__         = "BA";

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int column                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SpreadsheetColumn().getLabel(column);
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
