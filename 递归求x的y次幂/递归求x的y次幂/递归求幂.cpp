#include <iostream>
using namespace std;
double re(int x,int y){
	if(y==1){
	return x;}
	return re(x,y-1)*x;}
	
void main(){
	int x,y;
	cout<<"please input x:"<<endl;
	cin>>x;
	cout<<"please input y:"<<endl;
	cin>>y;
	cout<<"result is:"<<re(x,y)<<endl;
	}
