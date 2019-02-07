#include<iostream>
using namespace std;
#define max 10
class Semaphore
{
	public:
	int n,s=1,e,f=0,arr[max],front=0,rear=0;
	int wait(int w)
	{
		int a=w;
		return --a;                                               ;
	}
	int signal(int w)
	{
		int a=w;
		return ++a;
	}
	void producer()
	{
		e=wait(e);		
		s=wait(s);
		arr[rear]=1;
		rear++;
      	s=signal(s);
      	f=signal(f);
    }
    void consumer()
    {
		f=wait(f);
  		s=wait(s);
		front++;
  		s=signal(s);
   		e=signal(e);
    }
};
int main()
{
	Semaphore obj;
	cout<<"Enter the size of buffer"<<endl;
	cin>>obj.n;
	obj.e=obj.n;
	int choice;
	cout<<"1:Producer"<<endl<<"2:Consumer"<<endl<<"3:Exit"<<endl;
	while(1)
	{
		cout<<"Enter choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					if(obj.s==1&&obj.e!=0)
					obj.producer();
					break;
				}
			case 2:
				{
					if(obj.s==1&&obj.f!=0)
					obj.consumer();
					break;
				}
			default:cout<<"exit"<<endl;
					break;
		}
	cout<<"Places full in buffer :"<<obj.f<<endl<<"Empty places in buffer :"<<obj.e<<endl;
	}
	return 0;
}
