#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class D{
public:
  int A, B, diff;
  
  D(int _A, int _B) : A(_A), B(_B) {diff = A-B;}

  bool operator<(const D& lhs) const{
    return this->diff > lhs.diff;
  }
};

int main(){
  int N, T;
  cin >> N >> T;

  int sum = 0;
  vector<D> v;
  for(int i=0; i<N; ++i){
    int a,b;
    cin >> a >> b;
    v.push_back(D(a,b));
    sum += a;
  }
  
  sort(v.begin(), v.end());

  for(int i=0; i<N; ++i) cout << v[i].diff << endl;
  
  bool f = true;
  for(int i=0; i<N; ++i){
    if(sum <= T){
      f = false;
      cout << i << endl;
      break;
    }
    sum -= v[i].diff;
  }
  if(f) cout << -1 << endl;
}
