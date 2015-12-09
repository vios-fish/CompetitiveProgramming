#include <iostream>
#include <string>

using namespace std;

int main(){
  string ss;
  cin >> ss;
  ss[ss.size()-1] = '5';
  cout << ss << endl;
}
