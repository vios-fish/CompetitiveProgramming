// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysDirectoryListing.cpp"
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

class EllysDirectoryListing {
    public:
    vector <string> getFiles(vector <string> files) {
        vector <string> result = files;

        int cnt = 1;
        rep(i, result.size()-2){
            if( result[i] == "." || result[i] == ".." ){
                swap( result[i],result[result.size()-cnt] );
                --i;
                cnt=2;
            }
        }

        return result;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ContestApplet.jnlp", ".", "Image.jpg", "..", "Book.pdf", "Movie.avi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ContestApplet.jnlp", "Movie.avi", "Image.jpg", "Book.pdf", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getFiles(Arg0)); }
	void test_case_1() { string Arr0[] = {"Image.jpg", "..", "."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Image.jpg", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getFiles(Arg0)); }
	void test_case_2() { string Arr0[] = {"..", ".", "Image.jpg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Image.jpg", ".", ".." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getFiles(Arg0)); }
	void test_case_3() { string Arr0[] = {"No", "..", "Zaphod", ".", "Just", "very", "very...", "Improbable"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"No", "Improbable", "Zaphod", "very...", "Just", "very", ".", ".." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getFiles(Arg0)); }
	void test_case_4() { string Arr0[] = {"www.topcoder.com", "Ever.tried", ".", "Ever.failed", "..", "No", "Matter.", "Try", "Again.", "Fail", "Again..", "Fail.Better"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"www.topcoder.com", "Ever.tried", "Fail.Better", "Ever.failed", "Again..", "No", "Matter.", "Try", "Again.", "Fail", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getFiles(Arg0)); }
	void test_case_5() { string Arr0[] = {"This", ".", "is", "tricky", "test", ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"This", "test", "is", "tricky", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getFiles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    EllysDirectoryListing __test;
    __test.run_test(-1);
}

// END CUT HERE
