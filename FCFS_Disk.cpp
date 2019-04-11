#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,start;
	cout<<"Enter the number of cylinders"<<endl;
	cin>>n;
	cout<<"Enter the starting cylinder no."<<endl;
	cin>>start;
	int req[n];
	cout<<"Enter the pending request"<<endl;
	for(int i=0;i<n;i++)
	cin>>req[i];
	int num=start;
	int count=0;
	for(int i=0;i<n;i++)
	{
		count+=abs(num-req[i]);
		num=req[i];
	}
	
	cout<<"Total distance travelled"<<count;	
	return 0;
}
