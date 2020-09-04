using namespace std;
#include <bits/stdc++.h>
#include <ctime>
#define random(a,b) (rand()%(b-a+1))+a
class pig
{
	private:	
		int pigtype;											//0Ϊ����1Ϊ����2Ϊ���� 
		double m;
		int growthday;
		double growthm;
	public:
		pig *next;
		pig(int i)												//���캯��ȷ����������� 
		{														//i��ʾ�������
			pigtype=i;
			double a=random(200,500);							//�����ȡ���� 
			m=a/10;
		}
		double nowm();											//���㵱ǰ���� !!	
		bool oksell(int day);									//���Ƿ������
		void print(); 

};
double pig::nowm()
{
	double a=random(0,12);
	growthm=a/10;
	m+=growthm;
	return m;
}
bool pig::oksell(int day)
{
	if(day>360||m>75)
	return 1;
	else 
	return 0;
}
void pig::print()
{
	cout<<m<<"\t"<<pigtype<<endl;
}


class juan
{
	private:
		int number;
		int type;
		int count;
		int pigcount;
	public:
		pig *head;
		void print();
		int getcount(int);
		int numadd();
		int numsub();
		
};
void juan::print()
{
	pig *target=head;
	for(int i=0;i<count;i++)
	{
		target->print();
		target=target->next;
	}
}
int juan::numadd()
{
	number+=1;
	return number; 
}
int juan::numsub()
{
	number-=1;
	return number;
} 
int juan::getcount(int c)
{
	count=c;
	return c;
}

	
juan zhujuan[100];


pig *creatb(int num)												//numΪ��������������������������� 
{
	pig *head=NULL,*end=NULL;
	for(int i=0;i<num;i++)
	{
		pig *p=new pig(0);
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
			end=p;
		}
		else
		{
			end->next=p;
			end=p;
		}
	}	
	end->next=NULL;
	return head;
}


pig *creato(int num1,int num2)										//�������˺����������,num1Ϊ����������num2Ϊ�������� 
{
	pig *head=NULL,*end=NULL;
	for(int i=0;i<num1+num2;i++)
	{
		if(i<num1)
		{
			pig *p=new pig(1);
			p->next=NULL;
			if(head==NULL)
			{
				head=p;
				end=p;
			}
			else
			{
				end->next=p;
				end=p;
			}	
		}
		else
		{
			pig *q=new pig(2);
			q->next=NULL;
			end->next=q;
			end=q;
		}
	}
	end->next=NULL;
	return head;
} 


int main()
{
	int open=1;
	int times=0;
	for(;open==1;times++)
	{	
		int blackp,whitep,flowerp;
		cout<<"����:";	cin>>blackp;
		cout<<"����:";	cin>>whitep;
		cout<<"����:";	cin>>flowerp;
		int bjuan=0,ojuan=0,aveb=0,aveo=0,remb=0,remo=0;
		if((blackp+whitep+flowerp)<100)
		{	
			bjuan=blackp;remb=0;aveb=1;
			ojuan=flowerp+whitep;remb=0;aveb=1;
		} 
		else 
		{
			bjuan=((blackp*100)/(blackp+whitep+flowerp));							//����Ҫ���ٺ���Ȧ 
			if(bjuan==0&&blackp!=0) bjuan=1;									//���ٱ�֤һ������Ȧ 
			ojuan=100-bjuan;													//Ҫ����������Ȧ 
		}		
			aveb=blackp/bjuan;
			remb=blackp%bjuan;
			aveo=(whitep+flowerp)/ojuan;
			remo=(whitep+flowerp)%ojuan;										//���Ʒ�����Ȧ 
		cout<<"juan"<<bjuan<<" "<<ojuan<<endl;
		cout<<"ave"<<aveb<<" "<<aveo<<endl;
		cout<<"rem"<<remb<<" "<<remo<<endl;
		pig *bpig=NULL;
		bpig=creatb(blackp);
		pig *opig=NULL;
		opig=creato(whitep,flowerp);

		pig *logo=bpig,*logo1=bpig;
		int juannum=0;
		for(int i=juannum;juannum<remb+i;juannum++)
		{
			zhujuan[juannum].head=logo;
			zhujuan[juannum].getcount((aveb+1));
			for(int j=0;j<(aveb+1);j++)
			{
				logo1=logo;
				logo=logo->next;
			}
			logo1->next=NULL;
			logo1=logo;
			zhujuan[juannum].print();
			cout<<endl;
		} 
		for(int i=juannum;juannum<(bjuan-remb+i);juannum++)
		{
			zhujuan[juannum].head=logo;
			zhujuan[juannum].getcount(aveb);
			for(int j=0;j<aveb;j++)
			{
				logo1=logo;
				logo=logo->next;
			}
			logo1->next=NULL;
			logo1=logo;
			zhujuan[juannum].print();
			cout<<endl;
		}
		logo=opig;logo1=opig;
		for(int i=juannum;juannum<remo+i;juannum++)
		{
			zhujuan[juannum].head=logo;
			zhujuan[juannum].getcount((aveo+1));
			for(int j=0;j<(aveo+1);j++)
			{
				logo1=logo;
				logo=logo->next;
			}
			logo1->next=NULL;
			logo1=logo;
			zhujuan[juannum].print();
			cout<<endl;
		} 
		for(int i=juannum;juannum<(ojuan-remo+i);juannum++)
		{
			zhujuan[juannum].head=logo;
			zhujuan[juannum].getcount(aveo);
			for(int j=0;j<aveo;j++)
			{
				logo1=logo;
				logo=logo->next;
			}
			logo1->next=NULL;
			logo1=logo;
			zhujuan[juannum].print();
			cout<<endl;
		}
		cin>>open;
	}
	return 0;
}

