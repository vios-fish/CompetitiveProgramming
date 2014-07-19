#include<iostream>

using namespace std;


int main(){
	int *p;
	int a[]={1,5,-4,7,-2,0,3,6,-8,10};
	p = a;
	p[2] = 4;
	
	cout << a[0] << " " << *p << " " << a[2] << endl;
	
	p+=3;
	cout << *p <<" " << p[2] << endl;

	for(int i = 0; i < 10;++i)
	  {
	    cout << i << endl;
	  }
	
	
	p=&a[5];
	cout << *(p+2) << endl;
	
	p=a+7;--p;
	cout << p[0] << endl;
	
	cout << (int)'n' << endl;
	cout << (char)0x4A << endl;
	
	double dd = 1.89383;
	printf("%f\n",dd );
	printf("%lf\n",dd);
}
