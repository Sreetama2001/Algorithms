
// Calculate power of 2 ,
# include<bits/stdc++.h>
using namespace std;

bool power2(int n)
{
	if (n==1)
		return true;
	if (n<=0||n%2!=0)
		return false;
	return power2(n/2);
}

bool power3(int n)
{	if (n==1)
	 return true;
	if (n<=0||n%3!=0)
		return false;
	return power3(n/3);
}

bool power4(int n)
{	if (n==1)
		return true;
	if (n<=0||n%4!=0)
		return false;
	return power4(n/4);
}


int main()
{
	if(power4(50))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	(power2(64))?cout<<"True"<<endl:cout<<"False"<<endl;
	(power3(27))?cout<<"True"<<endl:cout<<"False"<<endl;
return 0;
}

