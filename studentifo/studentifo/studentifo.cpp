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
        cout<<"******ѧ����Ϣ******"<<endl;
        cout<<"<1>��ѯ��Ϣ"<<endl;
		cout<<"<2>�����Ϣ"<<endl;
		cout<<"<3>��ӳɼ�"<<endl;
		cout<<"<4>ɾ����Ϣ"<<endl; 
		cout<<"<5>�˳�����"<<endl; 
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
			default:cout<<"��������Ч������"<<endl; 
		} 
    }
}
void list(){
       cout<<"����\t"<<"ѧ��\t"<<"�ɼ�\t"<<endl;
       for(int i=0;i<studentcount;i++)
       cout<<students[i].name<<"\t"<<students[i].number[i]<<"\t"<<students[i].grade<<endl;
}
void addlist(){
	if(studentcount==120)
	cout<<"��������";
	 else{
 		cout<<"����������";
		 cin>>students[studentcount].name;
		 cout<<"������ѧ��";
		 cin>>students[studentcount].number;
		 cout<<"������ɼ�";
		 cin>>students[studentcount].grade; 
		 studentcount++;
		 cout<<"�Ƿ������ӣ��ǣ�1 ����0";
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
		cout<<"������ѧ������";
		cin>>dname;
		i=find(dname);
		if(i==studentcount)
			cout<<"ѧ��������";
		else{
			students[i].name=dname;
			cout<<"������ѧ��";
			cin>>students[i].number[i];
			cout<<"������ɼ�";
			cin>>students[i].grade;
		}
		cout<<"�Ƿ�������룬���������밴1������0";
		cin>>n;
	}
}

void deletelist(){
	cout<<"����������";
	string dname;
	cin>>dname;
	int i=find(dname);
	if(i==studentcount)
	cout<<"ѧ��������";
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