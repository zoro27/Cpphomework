#include<iostream>
#include<string>
using namespace std;
void list();
void addlist();
void deletelist();
void input();

int find(string&dname);
int studentcount=0;
struct student{
	string name;
	string number; 
	int grade;
}students[120];
int main(){
    char action=0;
    while (1){
        cout<<"******学生信息******"<<endl;
        cout<<"<1>查询信息"<<endl;
		cout<<"<2>添加信息"<<endl;
		cout<<"<3>添加成绩"<<endl;
		cout<<"<4>删除信息"<<endl; 
		cout<<"<5>退出程序"<<endl; 
		cin>>action;
		switch(action){
			case'1':list();
			break;
			case'2':addlist();
			break;
			case'3':input();
			break;
			case'4':deletelist();
			break;
			case'5':return 0;
			default:cout<<"请输入有效的数字"<<endl; 
		} 
    }
}
void list(){
       cout<<"姓名\t"<<"学号\t"<<"成绩\t"<<endl;
       for(int i=0;i<studentcount;i++)
       cout<<students[i].name<<"\t"<<students[i].number[i]<<"\t"<<students[i].grade<<endl;
}
void addlist(){
	if(studentcount==120)
	cout<<"人数已满";
	 else{
 		cout<<"请输入姓名";
		 cin>>students[studentcount].name;
		 cout<<"请输入学号";
		 cin>>students[studentcount].number;
		 cout<<"请输入成绩";
		 cin>>students[studentcount].grade; 
		 studentcount++;
		 cout<<"是否继续添加？是：1 ；否：0";
		 int n=0;
		 cin>>n;
		 if(n)
		 addlist();
		  
 	} 
}
void input(){
	int n=1;
	int i;
	string dname;
	while(n){
		cout<<"请输入学生姓名";
		cin>>dname;
		i=find(dname);
		if(i==studentcount)
			cout<<"学生不存在";
		else{
			students[i].name=dname;
			cout<<"请输入学号";
			cin>>students[i].number[i];
			cout<<"请输入成绩";
			cin>>students[i].grade;
		}
		cout<<"是否继续输入，继续输入请按1，否则按0";
		cin>>n;
	}
}

void deletelist(){
	cout<<"请输入姓名";
	string dname;
	cin>>dname;
	int i=find(dname);
	if(i==studentcount)
	cout<<"学生不存在";
	else{
		for(;i<(studentcount-1);i++){
			students[i]=students[i+1];
		}studentcount--;
	} 
}
int find(string &dname){
	int i=0;
	while(students[i].name!=dname&&i<studentcount)
		i++;
	return i;
}