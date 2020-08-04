#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define ll long long

ll arr[3][2];

bool check(int i, int j, int k)
{
	ll d1, d2;
	if(arr[i][0]==arr[j][0])
		return false;

	else
	{
		if(arr[i][1]==arr[j][1])
		d1=0,d2=arr[j][1];
		else if((arr[i][1]-arr[j][1])%(arr[i][0]-arr[j][0])!=0)
		return false;
		else
		{
		d1 = (arr[i][1]-arr[j][1])/(arr[i][0]-arr[j][0]);
		d2 = (arr[i][1]-arr[i][0]*d1);
		}
		ll a = arr[k][0], b = arr[k][1];
		if(a*d1==b||a+d2==b||a*d1+d2==b)
		return true;
		if(!d1)
		return false;
		if(d2%d1)
		return false;
		d2 = d2/d1;
		if(a+d2==b)
		return true;
	}
	return false;
}	

int main()
{
	//freopen("test.out", "rt", stdin);
	io
	int t;
	cin>>t;
	int k = t;
	while(t--)
	{
	//cout<<"test"<<k-t<<"\n";
	int flag = 3;
	ll a,b,c,p,q,r;
	ll dd1,dd2,dd3;
	ll ddd1,ddd2,ddd3;
	cin>>a>>b>>c>>p>>q>>r;
	arr[0][0]=a;arr[1][0]=b;arr[2][0]=c;
	arr[0][1]=p;arr[1][1]=q;arr[2][1]=r;
	ll d1 = p-a, d2 = q-b, d3 = r-c;
	if(!a)dd1=0,ddd1=p;
	else dd1=p/a,ddd1=p%a;
	if(!b)dd2=0,ddd2=q;
	else dd2=q/b,ddd2=q%b;
	if(!c)dd3=0,ddd3=r;	
	else dd3=r/c,ddd3=r%c;
	//cout<<dd1<<" "<<dd2<<" "<<dd3<<"\n";
	//cout<<ddd1<<" "<<ddd2<<" "<<ddd3<<"\n";
	//all equal-
	if(!d1&&!d2&&!d3)
	flag = 0;
	//--checking for 1-
	/* check for single operation*/
	else if((!d1&&!d2)||(!d2&&!d3)||(!d1&&!d3))
	flag = 1;
	/*check for common addition*/
	else if((!d1&&(d2==d3))||(!d2&&(d1==d3))||(!d3&&(d2==d1))||((d1==d2)&&(d2==d3)))
	flag = 1;
	/*check for common multiplication*/
	else if((!ddd1&&!ddd2&&!ddd3)&&((!d1&&(dd2==dd3))||(!d2&&(dd1==dd3))||(!d3&&(dd2==dd1))||((dd1==dd2)&&(dd2==dd3))))
	flag = 1;
	//--checking for 2-
	else if(!d1||!d2||!d3||(d1==d2)||(d2==d3)||(d3==d1)||(!ddd1&&!ddd2&&(dd1==dd2))||(!ddd2&&!ddd3&&(dd2==dd3))||(!ddd3&&!ddd1&&(dd1==dd3)))
	flag = 2;
	//check for 3 subsets-
	else if(check(0,1,2)||check(2,0,1)||check(2,1,0))
	flag = 2;	
	else if(d1==d2+d3||d2==d1+d3||d3==d1+d2) 
	flag = 2;
	else if((!ddd1&&!ddd2&&!ddd3)&&(dd1==dd2*dd3 ||dd2==dd1*dd3||dd3==dd1*dd2))
	flag = 2;
	else if((!ddd1&&((q-b*dd1==d3)||(r-c*dd1==d2)))||(!ddd2&&((p-a*dd2==d3)||(r-c*dd2==d1)))||(!ddd3&&((p-a*dd3==d2)||(q-b*dd3==d1))))
	flag = 2;
	else if((!ddd3&&(a+d2)*dd3==p)||(!ddd2&&(a+d3)*dd2==p)||(!ddd3&&(b+d1)*dd3==q)||(!ddd1&&(b+d3)*dd1==q)||(!ddd2&&(c+d1)*dd2==r)||(!ddd1&&(c+d2)*dd1==r))
	flag = 2;
	cout<<flag<<'\n';
	}
	return 0;
	
		
}