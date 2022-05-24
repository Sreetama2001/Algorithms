#include<bits/stdc++.h>
using namespace std;
void long_in_sub(int arr[],int n)
{
	int length[n],longest=INT_MIN;
	for(int i=0;i<n;i++)
	{
		length[i]=1;
		for(int j=0;j<i;j++)
		{ if(arr[j]<arr[i])
		  length[i]=max(length[i],length[j]+1);
		}
		if(length[i]>longest)
		longest=length[i];	
	}
	for(int i=0;i<n;i++)
	{ cout<< "Length is " << length[i] <<" till "<<arr[i]<<endl;
	}
	cout<<" Length of the longest subsequence is "<<longest<<endl; 
}
int main()
{
	int n ;
	cout<< " Input : ";
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	long_in_sub(arr,n);
	return 0;
}
