#include<bits/stdc++.h>
using namespace std;
#define max 10
class Bankers
{
	public:
		int all[max][max],mar[max][max],work[max],need[max][max],avl[max];
		int n,m,count,trial,exec;
		bool finish[max];
		void getdata()
		{
			cout<<"Enter the number of processes"<<endl;
			cin>>n;
			cout<<"Enter the number of resources"<<endl;
			cin>>m;
			for(int i=0;i<n;i++)
			finish[i]=0;
			cout<<"Enter the number of resources allocated to processes:"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"PROCESS "<<i+1<<endl;
				for(int j=0;j<m;j++)
				{
					cout<<"Resource "<<j+1<<":";
					cin>>all[i][j];
				}
			}
			cout<<"Enter the number of maximum resources required to processes:"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"PROCESS "<<i+1<<endl;
				for(int j=0;j<m;j++)
				{
					cout<<"Resource "<<j+1<<":";
					cin>>mar[i][j];
				}
			}
			cout<<"Enter  the avaliable intances of resources:"<<endl;
			for(int i=0;i<m;i++)
			{
				cout<<"Resource "<<i+1<<":";
				cin>>work[i];
			}
		}
		void calculate_need()
		{
			//formation of need matrix
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					need[i][j]=mar[i][j]-all[i][j];
			}
			//calculation of all instances of resources
			for(int k=0;k<m;k++)
			avl[k]=0;
			for(int j=0;j<m;j++)
			{
				for(int i=0;i<n;i++)
					avl[j]=avl[j]+all[i][j];
				avl[j]=avl[j]+work[j];
			}
		}
		void calculation()
		{
			trial=n;
			count=0;
			cout<<"Sequence of process completed"<<endl;
			while(trial--)
			{
				for(int i=0;i<n;i++)
				{
					exec=0;
					for(int j=0;j<m;j++)
					{
						if(finish[i]==1) break;
						if(need[i][j]<=work[j])
							exec++;
						else
						break;
					}
					if(exec==m)
					{
						for(int j=0;j<m;j++)
							work[j]=work[j]+all[i][j];
						finish[i]=1;
						cout<<"Process "<<i+1<<endl;
					}
				}
			}
			cout<<"Instances of resources"<<endl;
			for(int i=0;i<m;i++)
			{
				if(avl[i]==work[i])
					count++;
				cout<<"Resource "<<i+1<<": "<<work[i]<<endl;
			}
			if(count==m)
				cout<<"Safe state"<<endl;
			else
				cout<<"Unsafe state"<<endl;
		}
};
int main()
{
	Bankers obj;
	obj.getdata();
	obj.calculate_need();
	obj.calculation();
} 
