//FCFS
#include<iostream>
using namespace std;
#define max 10
class  Process
{
	int n;
	float arr[max],exe[max];
	public:
	void getdata();
	void time_calculation();
};
void Process::getdata()
{
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	cout<<"Arrival time of processes"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		cout<<"PROCESS "<<i+1<<" ";
		cin>>arr[i];
	}
	cout<<"Execution time of processes"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		cout<<"PROCESS "<<i+1<<" ";
		cin>>exe[i];
	}
}
void Process::time_calculation()
{
	float ct=0.0,tat=0.0,wt=0.0,avgtat=0.0,avgwt=0.0;
	cout<<"                " <<"  CT     "<<"  TAT    "<<"    WT "<<endl;
	for(int i=0;i<=n-1;i++)
	{
		if(ct>arr[i])
		{
			ct=ct+exe[i];
			tat=ct-arr[i];
			wt=tat-exe[i];
			cout<<"PROCESS  "<<i+1<<endl;
			
			cout<<"                 "<<ct<<"        "<<tat<<"        "<<wt<<endl;
			
			avgtat=tat+avgtat;
			avgwt=wt+avgwt;
			
		}
		else
		{
			ct=0.0;
			ct=arr[i]+exe[i];
			tat=ct-arr[i];
			wt=tat-exe[i];
			cout<<"PROCESS  "<<i+1<<endl;
			
			cout<<"                "<<ct<<"        "<<tat<<"        "<<wt<<endl;
			avgtat=tat+avgtat;
			avgwt=wt+avgwt;
			
		}
		
	
	
	
	}	
	
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	cout<<"AVERAGE TAT "<<avgtat<<endl;
		cout<<"AVERAGE WT "<<avgwt<<endl;
	
	
	
}
main()
{
	Process obj;
	obj.getdata();
	obj.time_calculation();
	cout<<"CT:Completion time,TAT:Tune around time,WT:Waiting time "<<endl; 
}
