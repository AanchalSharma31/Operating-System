//SJF
#include<bits/stdc++.h>
using namespace std;
#define max 10
class  Process
{
	int n;
	float exe[max];
	public:
	void getdata();
	void time_calculation();
};
void Process::getdata()
{
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	cout<<"Assume all processes arrive at 0 interval"<<endl;
	cout<<"Execution time of processes"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		cout<<"PROCESS "<<i+1<<" ";
		cin>>exe[i];
	}
}
void Process::time_calculation()
{

	sort(exe,exe+n);
	float tat=0.0,wt=0.0;
	for(int i=0;i<=n-1;i++)
	{
		tat+=exe[i];
		wt=tat-exe[i];
		cout<<"TAT & WT of process with burst time"<<exe[i]<<" "<<tat<<" "<<wt<<endl;
	}
	
}
main()
{
	Process obj;
	obj.getdata();
	obj.time_calculation();
	cout<<"CT:Completion time,TAT:Turn around time,WT:Waiting time "<<endl; 
}

