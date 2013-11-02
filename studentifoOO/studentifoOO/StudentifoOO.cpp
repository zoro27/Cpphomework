#include<iostream>

using namespace std;

struct student{
        int id;
        int score;
}students[1000];

void list(int &count){
        cout<<"**********欢迎进入查看系统**********\n"<<endl;	
        for(int i=0;i<count;i++)
                cout<<"学号： "<<students[i].id<<";成绩："<<students[i].score<<endl;
        system("pause");
};
void addStudent(int id,int &count){
        students[count].id=id;
        count++;
}
void courseselection(int &count){
	int Num;
        do{
                cout<<"************欢迎进入选课系统************\n"<<endl;
                cout<<"************输入数字选择操作类型************"<<endl;
                cout<<"1.<添加多个学号>"<<endl; 
			    cout<<"2.<添加一个学号>"<<endl;
                cout<<"3.<退出选课系统>"<<endl;
                cout<<"*********************************************\n"<<endl;
                cin>>Num;
                switch(Num){
                case 1:
                        long head;
                        int num;
                        cout<<"请输入所要添加学生的起始学号："<<endl;
                        cin>>head;
                        cout<<"请输入要添加的人数："<<endl;
                        cin>>num;
                        for(int i=0;i<num;i++){
                                addStudent(head+i,count);
                        }
                        break;
                case 2:
                        cout<<"请输入所要添加学生的学号："<<endl;
                        cin>>head;
                        addStudent(head,count);
                        break;
                case 3:
                        break;
                default:
                        cout<<"您的输入有误，请重新选择1,2或者3"<<endl;
                        break;
                }
        }while (Num!=3);

};
void dropcourse(int &count){
        int found(int id,int &count);
        int Num;
        int id;
        int flag;
        do{
                cout<<"**********欢迎进入退课系统**********\n"<<endl;
                cout<<"1.退课"<<endl;
                cout<<"2.退出退课系统"<<endl;
				cout<<"请输入操作序号：";
                cin>>Num;
                switch(Num){
                case 1:
                        cout<<"请输入要删除的学号："<<endl;
                        cin>>id;
                        flag=found(id,count);
                        if(flag==count)
                                cout<<"您输入的学号不存在，请重选择"<<endl;
                        else{
                                for(int i=flag;i<count;i++){
                                        students[i]=students[i+1];
                                }
                                count--;
                                cout<<"退课成功！"<<endl;
                        }
                        break;
                case 2:
                        break;
                default:
                        cout<<"您的输入有误，请重新选择"<<endl;
                }
        }while (Num!=2);
};

void recordScore(int &count){
	    int found(int id,int &count);
        int id;
        int score=0;
        cout<<"**********欢迎进入成绩录入系统**********\n"<<endl;
        cout<<"请输入学号：";
        cin>>id;
        if(id!=-1){
                int flag=found(id,count);
                if(flag==count)
                        cout<<"您输入的学号不存在，请重新输入"<<endl;
                for(;flag<count;flag++){
                        cout<<"请输入学号为："<<students[flag].id<<"的学生的分数：";
                        cin>>score;
                        if(score!=-1){
                                students[flag].score=score;
                        }
                        else
                                break;
                }
                if(flag==count)
                        cout<<"录入已完毕"<<endl;
        }
};
int found(int id,int &count){
        int i;
        for(i=0;i<count;i++)
                if(students[i].id==id)
                        break;
        return i;
};

int main(){
	int Num;
	int count=0;
	cout<<"*******欢迎进入学生信息系统*******"<<endl;
	while(true){
	 cout<<"输入数字编号进行操作"<<endl;
	 cout<<"1.查看名单"<<endl;
	 cout<<"2.学生选课"<<endl;
	 cout<<"3.学生退课"<<endl;
	 cout<<"4.录入成绩"<<endl;
	 cout<<"5.退出系统"<<endl;
	 cin>>Num;
	 switch(Num){
		 case 1:
			 list(count);
			 break;
		 case 2:
			 courseselection(count);
			 break;
		 case 3:
			 dropcourse(count);
			 break;
		 case 4:
			 recordScore(count);
			 break;
		 case 5:
			 return 0;
	     default:
             cout<<"输入有误，请重新输入"<<endl;
             break;
	      }
	}
}