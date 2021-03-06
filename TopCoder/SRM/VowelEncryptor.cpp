// BEGIN CUT HERE

// END CUT HERE
#line 5 "VowelEncryptor.cpp"
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

class VowelEncryptor {
	public:
	vector <string> encrypt(vector <string> text) {
		vector <string> result;

        for( int i = 0; i < text.size(); ++i)
	    {
            result[i] = "";
            for( int j = 0; j < text[i].size(); ++j)
            {
                char a = text[i][j];
                
                if( a != 'a' && a != 'i' && a != 'u' && a != 'e' && a != 'o')
                {
                    result[i] += a;
                }
            }
            
            if( result[i].empty() )
            {
                result[i] = text[i];
            }
	    }
		return result;
	}

	
// BEGIN CUT HERE

// END CUT HERE

};

// BEGIN CUT HERE

// END CUT HERE

