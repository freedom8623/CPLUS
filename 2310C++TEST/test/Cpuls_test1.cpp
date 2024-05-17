#include <iostream>
using namespace std;

class Fract{
	int num,den;
public:
	Fract(int a=0,int b=1){num=a;den=b;}
	int ged(int,int);
	Fract add(Fract);
	void show(){cout<<num<<'/'<<den<<endl;}
};
int Fract::ged(int m,int n) {
	int k;
	if(m>n)k=n;
	else k=m;
	for(;k>0;k--)
		if(m%k==0&&n%k==0)
			break;
			return k;
}
Fract Fract::add(Fract f) {
	Fract ff;
	int v;
	v=ged(den,f.den);
	v=den*f.den/v;
	num=v/den*num;
	f.num=v/f.den*f.num;
	ff.num=num+f.num;
	ff.den=v;
	v=ged(ff.num,ff.den);
	ff.num/=v;
	ff.den/=v;
	return ff;
}
void main(){
	Fract f1(1,5),f2(7,20),f3; //注15
	f3=f1.add(f2);
	f3.show();
}
