#include<iostream>
#include<cstdlib>


using namespace std;

int main(){
    int pn[100];
    const int n = 1000;

    for(int i=0; i<100; ++i)pn[i] = 0;
    pn[0] |= (1<<0);
    pn[0] |= (1<<1);
    cout << pn[0] << endl;
    for(int i = 2; i*i < n; ++i){
        int a = i/(sizeof(int)*8), b = i % (8*sizeof(int));
        // cout << pn[a] << " " << (1<< b) << endl;
        //cout << (pn[a]&(1<< b)) << endl;
        
        if( ~pn[a] & (1<<b) ){
            for(int j=i*2; j<n; j+=i){
                pn[j/(sizeof(int)*8)] |= (1<<j%(sizeof(int)*8));
                //cout << j << endl;
            }
        }
    }

    for(int i = 0; i<n; ++i ){
        int a = i/(sizeof(int)*8), b = i % (8*sizeof(int));
        //cout << a << " " << b << endl;
        if( ~pn[a] & (1<<b) ){
            cout << i << endl;
        }
    }
}
