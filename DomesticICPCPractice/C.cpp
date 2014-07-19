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

int idx;
string ss;

string readLetter();
string readString();
string readCipher();

string nextLetter(string s){
    if(s != "?") s[0] = (s[0]-'A'+1)%26 + 'A';
    return s;
}

string prevLetter(string s){
    if(s != "?") s[0] = (s[0]-'A'-1+26)%26 + 'A';
    return s;
}

string readLetter(){
    string res = "";
    if(ss[idx] == '+'){
        ++idx;
        res = nextLetter(readLetter());
    }else if( ss[idx] == '-'){
        ++idx;
        res = prevLetter(readLetter());
    }else{
        res = ss[idx++];
    }
    
    return res;
}

string readString(){
    string res = "";
    if( ss[idx] == '['){
        ++idx;
        res = readCipher();
        reverse(res.begin(), res.end());
        ++idx;
    }else{
        res += readLetter();
    }
    return res;
}

string readCipher(){
    string res = "";
    while( idx < (int)ss.size() && ss[idx] != ']'){
        res += readString();
    }

    return res;
}


int main(){
    while(cin >> ss, (ss != ".")){
        idx = 0;
        string ans = readCipher();
        replace(ans.begin(), ans.end(), '?', 'A');
        cout << ans << endl;
    }
}

