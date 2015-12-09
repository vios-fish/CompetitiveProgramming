#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    for(int i=0; i<4; ++i){
        for(int j=0; j<3; ++j){
            for(int k=0; k<2; ++k){
                v.push_back(pow(2,i) * pow(3,j) * pow(5,k));
            }
        }
    }
    sort(v.begin(), v.end());
    for(auto x: v) cout << x << endl;
}

