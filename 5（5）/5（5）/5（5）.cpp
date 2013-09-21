#include <iostream>
using namespace std;
void main(){
	int n,m;
cout<<"please input n:"<<endl;
cin>>n;
cout<<"please input m:"<<endl;
cin>>m;
	  float f;
	  int i,j,f1,f2;
  for(i=1;i<n;i++)
  {
   f1=i*(i+1);}
  for(j=n;j<m;j++)
  {
	  f2=j*(j+1);}
  f=f2/f1;
cout<<"result:"<<endl;
cout<<f<<endl;
}