#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define ll long long
int main()
{
	io
	int t;
	cin>>t;
	while(t--)
	{
	ll ts,a,cou=0;
	cin>>ts;
	a = ts;
	vector<int> pos;
	while(ts/2)
	{
		if(ts&1)
		{
		break;	
		}
		ts/=2;
		cou++;
	}
	cou = pow(2,cou);
	cou = a/cou;
	cout<<cou/2<<"\n";
	}
	return 0;
		
}