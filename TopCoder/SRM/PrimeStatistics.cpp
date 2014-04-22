#line 2 "PrimeStatistics.cpp"
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
#include <array>

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

class PrimeStatistics {
public:
	int mostCommonRemainder( int lowerBound, int upperBound, int modulo ) {
        const int m = 200010;
		int result = m;
        array<bool, m> isp = {0};

        isp[0] = true;
        isp[1] = true;
        for(int i=2; i*i <= m; ++i){
            if( !isp[i] ){
                for(int j=2; i*j <= m; ++j){
                    isp[i*j] = true;
                }
            }
        }

        map<int,int> mm;

        

        FOR(i,lowerBound, upperBound+1){
            if(!isp[i]){
                mm[i%modulo] += 1;
            }
        }

        if( mm.empty() ){
            result = 0;
        }else{
            int mi = m;
            int ma = -1;
            for(auto itr = begin(mm); itr != end(mm); ++itr){
                if( ma < (*itr).second ){
                    mi = (*itr).first;
                    ma = (*itr).second;
                }
                
            }
            result = mi;
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
			int lowerBound            = 3;
			int upperBound            = 14;
			int modulo                = 5;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int lowerBound            = 3;
			int upperBound            = 33;
			int modulo                = 1000;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int lowerBound            = 25;
			int upperBound            = 27;
			int modulo                = 17;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int lowerBound            = 1;
			int upperBound            = 200000;
			int modulo                = 2;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int lowerBound            = 1;
			int upperBound            = 1000;
			int modulo                = 6;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int lowerBound            = ;
			int upperBound            = ;
			int modulo                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int lowerBound            = ;
			int upperBound            = ;
			int modulo                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int lowerBound            = ;
			int upperBound            = ;
			int modulo                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PrimeStatistics().mostCommonRemainder(lowerBound, upperBound, modulo);
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
