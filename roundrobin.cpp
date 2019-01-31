//ROUND ROBIN
#include<iostream>
#define max 10
using namespace std;
class RoundRobin
{
	public:
		int n,qun;
			float bt[max],rbt[max],tat[max],wt[max],time=0.0;
		void getdata()
		{
			cout<<"Enter the number of processes with arrival time 0"<<endl;
			cin>>n;
			cout<<"Enter quantum time"<<endl;
			cin>>qun;
		
			cout<<"Enter the burst time(BT)"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"PROCESS"<<i+1<<":";
				cin>>bt[i];
				rbt[i]=bt[i];
			}
			
		}
		void calculation()
		{
			while(1)
			{
				int flag=1;
				for(int i=0;i<n;i++)
				{
					if(rbt[i]>0)
					{
						flag=0;
						if(rbt[i]>qun)
						{
							time=time+qun;
							rbt[i]=rbt[i]-qun;	
						}
						else
						{
							time=time+rbt[i];
							
							wt[i]=time-bt[i];
							rbt[i]=0;
							tat[i]=bt[i]+wt[i];
						}
					}
				}
			if(flag==1)break;
			}	
		}
		void traverse()
		{
			cout<<"Turn around time:"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"Process"<<i+1<<":"<<tat[i]<<endl;	
			}
			cout<<"Waiting time:"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"Process"<<i+1<<":"<<wt[i]<<endl;	
			}
		}	
};

int main()
{
	RoundRobin obj;
	obj.getdata();
	obj.calculation();
	obj.traverse();
	return 0;
}
