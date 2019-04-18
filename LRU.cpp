#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,count=0;
    cout<<"Enter the number of Pages "<<endl;  
	cin>>n; 
    int page[n];
    cout<<"Enter the Reference String "<<endl;
    for(i=0;i<n;i++)  cin>>page[i];
    cout<<"Enter the number of page frames "<<endl;
    cin>>m;
    int frame[m],frame_count[m];
    for(i=0;i<m;i++)
	{
        frame[i]=-1; 
        frame_count[i]=0; 
	}
    i=0;
    while(i<n)
	{
        int j=0,flag=0;
        while(j<m)
		{
            if(page[i]==frame[j])
			{  
            	flag=1;
            	frame_count[j]=i+1;
            }
            j++;
        }   
 	    j=0;  
        if(flag==0)
		{
            int min=0,k=0;
            while(k<m-1)
			{
	        	if(frame_count[min]>frame_count[k+1]) 
                min=k+1;
                k++;
	        }
            frame[min]=page[i]; 
            frame_count[min]=i+1;
            count++;          
		    while(j<m)
	           j++;
	    }
	    i++; 
   }
   cout<<"Number of faults are = "<<count<<endl;
   count=n-count;
   cout<<"Number of hits are = "<<count<<endl;
   return 0;
}       

