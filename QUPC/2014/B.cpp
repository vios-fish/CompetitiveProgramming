#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string ssv[2][10] = { {"Nil", "Un", "Bi", "Tri", "Quad", "Pent", "Hex", "Sept", "Oct", "En"},
                                   {"nil", "un", "bi", "tri", "quad", "pent", "hex", "sept", "oct", "en"}};

    string sin;

    cin >> sin;

    bool prei = false;
    bool preenn = false;
    for(int i=0; i<sin.size(); ++i){
        int ind = sin[i]-'0';
        
        
        if( ind != 0 && preenn ) cout << "n";
        if(i==0){
            cout << ssv[0][ind];
        }else{   
            cout << ssv[1][ind];
        }
        
        prei = false;
        preenn = false;
        if( ind == 2 || ind == 3 ) prei = true;
        if( ind == 9 ) preenn = true;
    }
    if(preenn) cout << "n";
    if(prei) cout << "um" << endl;
    else cout << "ium" << endl;
}
