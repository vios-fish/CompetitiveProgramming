#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;

  long long int num = 1, ans = 0;
  for(int i=0; i<N-1; ++i) num *= 2;

  for(int i=0; i<N; ++i){
    int a;
    cin >> a;
    ans += num * a;
    num /= 2;
  }
  
  cout << ans << endl;
}
