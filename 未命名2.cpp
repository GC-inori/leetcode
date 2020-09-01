#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n,res=0;
	cin>>n;
	map<int,int> m;
	for(int i=0,t;i<n;i++)
	{
		cin>>t;
		if(++m[t]>res)
		{
			res=m[t];
		}
	}
	cout<<res;
} 
