#include<iostream>

using namespace std;

struct student{
        int id;
        int score;
}students[1000];

void list(int &count){
        cout<<"**********��ӭ����鿴ϵͳ**********\n"<<endl;	
        for(int i=0;i<count;i++)
                cout<<"ѧ�ţ� "<<students[i].id<<";�ɼ���"<<students[i].score<<endl;
        system("pause");
};
void addStudent(int id,int &count){
        students[count].id=id;
        count++;
}
void courseselection(int &count){
	int Num;
        do{
                cout<<"************��ӭ����ѡ��ϵͳ************\n"<<endl;
                cout<<"************��������ѡ���������************"<<endl;
                cout<<"1.<��Ӷ��ѧ��>"<<endl; 
			    cout<<"2.<���һ��ѧ��>"<<endl;
                cout<<"3.<�˳�ѡ��ϵͳ>"<<endl;
                cout<<"*********************************************\n"<<endl;
                cin>>Num;
                switch(Num){
                case 1:
                        long head;
                        int num;
                        cout<<"��������Ҫ���ѧ������ʼѧ�ţ�"<<endl;
                        cin>>head;
                        cout<<"������Ҫ��ӵ�������"<<endl;
                        cin>>num;
                        for(int i=0;i<num;i++){
                                addStudent(head+i,count);
                        }
                        break;
                case 2:
                        cout<<"��������Ҫ���ѧ����ѧ�ţ�"<<endl;
                        cin>>head;
                        addStudent(head,count);
                        break;
                case 3:
                        break;
                default:
                        cout<<"������������������ѡ��1,2����3"<<endl;
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
                cout<<"**********��ӭ�����˿�ϵͳ**********\n"<<endl;
                cout<<"1.�˿�"<<endl;
                cout<<"2.�˳��˿�ϵͳ"<<endl;
				cout<<"�����������ţ�";
                cin>>Num;
                switch(Num){
                case 1:
                        cout<<"������Ҫɾ����ѧ�ţ�"<<endl;
                        cin>>id;
                        flag=found(id,count);
                        if(flag==count)
                                cout<<"�������ѧ�Ų����ڣ�����ѡ��"<<endl;
                        else{
                                for(int i=flag;i<count;i++){
                                        students[i]=students[i+1];
                                }
                                count--;
                                cout<<"�˿γɹ���"<<endl;
                        }
                        break;
                case 2:
                        break;
                default:
                        cout<<"������������������ѡ��"<<endl;
                }
        }while (Num!=2);
};

void recordScore(int &count){
	    int found(int id,int &count);
        int id;
        int score=0;
        cout<<"**********��ӭ����ɼ�¼��ϵͳ**********\n"<<endl;
        cout<<"������ѧ�ţ�";
        cin>>id;
        if(id!=-1){
                int flag=found(id,count);
                if(flag==count)
                        cout<<"�������ѧ�Ų����ڣ�����������"<<endl;
                for(;flag<count;flag++){
                        cout<<"������ѧ��Ϊ��"<<students[flag].id<<"��ѧ���ķ�����";
                        cin>>score;
                        if(score!=-1){
                                students[flag].score=score;
                        }
                        else
                                break;
                }
                if(flag==count)
                        cout<<"¼�������"<<endl;
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
	cout<<"*******��ӭ����ѧ����Ϣϵͳ*******"<<endl;
	while(true){
	 cout<<"�������ֱ�Ž��в���"<<endl;
	 cout<<"1.�鿴����"<<endl;
	 cout<<"2.ѧ��ѡ��"<<endl;
	 cout<<"3.ѧ���˿�"<<endl;
	 cout<<"4.¼��ɼ�"<<endl;
	 cout<<"5.�˳�ϵͳ"<<endl;
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
             cout<<"������������������"<<endl;
             break;
	      }
	}
}