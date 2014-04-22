// BEGIN CUT HERE

// END CUT HERE
#line 5 "KingSort.cpp"
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

const double	EPS = 1e-10;
const double	PI  = acos(-1.0);

#define dump(x)	    cerr << #x << " = " << (x) << endl;
#define debug(x)    cerr << #x << " = " << (x) << "(L" << __LINE__ << ")" << __FILE__ << endl;

#define FOR(i,a,b)  for( int i = (a); i < (b); ++i)
#define rep(i,n)    FOR(i,0,n)

typedef vector<int>	VI;
typedef vector<VI>	VII;
typedef vector<string>	VS;
typedef pair<int, int>	PII;

inline int			toInt( string s ){int v; istringstream sin(s);sin >> v;return v;}
template<class T> inline string toString( T x ){ostringstream sout;sout<<x;return sout.str();}

class KingSort {
    public:
    vector <string> getSortedList(vector <string> kings) {
        vector <string> result;

	map<char,int>	m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;

	map<int, string>    k;
	string		    a,s;

	sort( kings.begin(), kings.end() );

	string			kn    = "";
	int			cnt   = 0;
	rep( i, kings.size() ){
		istringstream	iss(kings[i]);
		iss >> a >> s;
		if( kn == "" ) kn     = a;
		if( kn != a ) cnt    += 100;
		char		last  = s[0];
		int		num   = m[last];
		FOR( j, 1, s.size() ){
			if( m[s[j]] > m[last] ){
				num  += m[s[j]] - 2*m[last];
			}
			if( m[s[j]] <= m[last] ){
				num += m[s[j]];
			}
			last = s[j];
		}
		k[cnt+num] = kings[i];
	}

	for( map<int,string>::iterator it = k.begin(); it != k.end(); ++it){
		result.push_back( it->second );
	}

        return result;
    }

    
// BEGIN CUT HERE
	public:
	void				run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string	print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void				test_case_0() { string Arr0[]													= {"Louis IX", "Louis VIII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis VIII", "Louis IX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSortedList(Arg0)); }
	void				test_case_1() { string Arr0[]													= {"Louis IX", "Philippe II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis IX", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSortedList(Arg0)); }
	void				test_case_2() { string Arr0[]													= {"Richard III", "Richard I", "Richard II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Richard I", "Richard II", "Richard III" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSortedList(Arg0)); }
	void				test_case_3() { string Arr0[]													= {"John X", "John I", "John L", "John V"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John I", "John V", "John X", "John L" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSortedList(Arg0)); }
	void				test_case_4() { string Arr0[]													= {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSortedList(Arg0)); }
	void				test_case_5() { string Arr0[]													= {"Philippe II", "Philip II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Philip II", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getSortedList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    KingSort	__test;
    __test.run_test(-1);
}

// END CUT HERE
