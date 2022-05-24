#include<bits/stdc++.h>
using namespace std;
// path in a n*n grid 
// find the optimal path to tansverse a grid of numbers such that it finds the maximum sum in the grid travelling only left and down

void path(int *g,int size)
{ 
	int sum[size][size],i,j;
	
	for(i=1;i<size;i++)
	{
		for(j=1;j<size;j++)
		{
		 if((i-1)==0)
		 	sum[i-1][j]=0;
			 
			 else if((j-1)==0)
			 sum[i][j-1]=0;
			 
		//cout<<sum[i][j-1]<<" "<<sum[i-1][j]<<endl;	 	
		sum[i][j]=max(sum[i][j-1],sum[i-1][j])+ *((g+i*size)+j) ;
		int x=*((g+i*size)+j);
		cout<<sum[i][j]<<" "<<x<<endl;		
		}
	    	
	} 
	cout<<"Maximum sum with optimal path:  "<<sum[size-1][size-1]<<endl; 
}
int main()
{

	int n;
	cin>>n;
	int grid[n+1][n+1];
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>grid[i][j];
	}
	cout<<endl;
	cout<<"The grid :"<<endl;cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		 cout<< grid[i][j]<<" ";
		 cout<<endl;
	}
	path(&grid[1][1],int(n+1));
	return 0;
}

