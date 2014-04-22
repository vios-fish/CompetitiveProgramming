// BEGIN CUT HERE
// PROBLEM STATEMENT
// N friends (numbered from 0 to N-1) play a game called Mafia. The exact rules of the game are not important for this problem. What's important is that at some point in the game they will need to choose one player who will lose and leave the game.

// END CUT HERE
#line 75 "MafiaGame.cpp"
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

class MafiaGame {
public:
	double probabilityToLose( int N, vector <int> decisions ) {
		double result;
        VI vote(N,0);
        int mv = -1;
        
        rep(i,decisions.size()) mv = max(mv, ++vote[decisions[i]]);

        if(mv == 1) return 0.0;
        
        int player = 0;
        rep(i,N) if(vote[i] == mv) ++player;

        double p = player;
        while(1){
            if(player == 1){
                result = 1.0/p;
                break;
            }

            if(player == 0){
                result = 0.0;
                break;
            }
            player = N % player;
        }
        
		return result;
	}
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int N                     = 3;
			int decisions[]           = {1, 1, 1};
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int decisions[]           = {1, 2, 3};
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 20;
			int decisions[]           = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0};
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 23;
			int decisions[]           = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17};
			double expected__         = 0.14285714285714285;

			std::clock_t start__      = std::clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int decisions[]           = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = MafiaGame().probabilityToLose(N, vector <int>(decisions, decisions + (sizeof decisions / sizeof decisions[0])));
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
