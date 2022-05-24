// leetcode __problem__https://leetcode.com/problems/next-permutation/

// genrating next_permutation of an given vector
#include<bits/stdc++.h>
using namespace std;

void swap(int *a ,int *b)
{	int t;
	t=*a;
	*a=*b;
	*b=t;	
}
    void nextPermutation(vector<int>& nums) {
      vector<int>vi;
	if(nums.size()==1) {
		return;
	}
	else{
	int indx=-1,i=1;
	int n=nums.size();
	// find the least weightage peak 
	// if not found then the array is in descending order
	while(i<nums.size())
	{ if(nums[i]>nums[i-1])
		indx=i;
		i+=1;
	}
      int index=indx;
	if(indx==-1)
	{ // sort in ascending or swap 
	    for(int j =0;j<n/2;j++)
	    	swap(&nums[j],&nums[n-j-1]);
	}		
	else
	{
		for(int j=indx ;j<n;j++)
		{ 
		  // find elements between highest peak and  lowest number before it
		  
		  if ((nums[j]>nums[indx-1]) && (nums[j]<nums[indx]))
				vi.push_back(nums[j]);	}
		if (vi.empty()) 
		swap(&nums[indx],&nums[indx-1]);
		else{
		int minimum=INT_MAX;
		for(int i=0;i<vi.size();i++)
		 minimum= min(minimum,vi[i]);
         int ind;
         for(int j=indx ;j<n;j++)
         {if (nums[j]==minimum)
             ind=j;
          }
		 swap(&nums[index-1],&nums[ind]);
	}
	// sort 
	sort(nums.begin()+index,nums.end());
    }
  }  
 }

int main()
{	
	int n;
	cout<<"Input: ";
	cin>>n;
	vector<int>nums;
	int y;
	for(int i=0;i<n;i++) 
		{ cin>>y;
		nums.push_back(y);}
	 nextPermutation(nums);
		 for(auto x: nums)
	 	cout<<x<<" ";	
	return 0;	
	
}

