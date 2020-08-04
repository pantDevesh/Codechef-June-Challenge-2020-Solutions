#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define ll long long
#define fo(i,n) for(ll i = 0; i < n; i++)
#define pb push_back 
#define N 2000
#define INF 10000000000
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;

//trying to solve using convex hull wait... but its concave no?:)

ll a,b;
int in = 0;
pii p0;
vpii points;
vpii hulls[N];

//next poll
pii nextToTop(stack<pii> &S) 
{ 
    pii p = S.top(); 
    S.pop();
    pii res = S.top(); 
    S.push(p); 
    return res; 
} 

// distance between p1 and p2 
ll dist(pii p1, pii p2) 
{ 
	return (p1.first - p2.first)*(p1.first - p2.first) + 
		(p1.second - p2.second)*(p1.second - p2.second); 
} 
ll orientation(pii p, pii q, pii r) 
{ 
	ll val = (q.second - p.second) * (r.first - q.first) - 
			(q.first - p.first) * (r.second - q.second); 

	if (val == 0) return 0; // colinear 
	return (val > 0)? 1: 2; // clock or counterclock wise 
}

bool cmp(pii p, pii q)
{
     ll o = orientation(p0, p, q); 
     if (o == 0) 
     return (dist(p0, p)< dist(p0, q));
   return (o == 2)? true: false; 
}

ll isInside(pii p, pii q, pii r) 
{ 
    ll tmp = (r.second - p.second)* (q.first - p.first) - (r.first - p.first)* (q.second - p.second);
    return tmp;
}
bool check(vpii v, pii p0)
{
    pii p,q;
    p.first = v[0].first;
    p.second = v[0].second;
    ll f;
    for(int i = v.size()-1; i >=0; i--)
    {
        q.first = v[i].first;
        q.second = v[i].second;
        ll tmp = isInside(p,q,p0);
        if(i == v.size()-1)
        f = tmp;
        else if((f<=0&&tmp>=0)||(f>=0&&tmp<=0))
        return false;
        p = q;
    }
    return true;
}

int  Hull(vpii polls)
{
    ll n = polls.size();
    vpii v;
    stack<pii> S; 
    //find minimum y coordinate-
    ll ymin = polls[0].second;
    ll ind  = 0;
    fo(i,n)
    {
        if(i && (ymin>polls[i].second||(ymin==polls[i].second&& polls[i].first< polls[ind].first)))
        ymin = polls[i].second, ind = i;
    }
    // placing the minimum poll at the first position 
    {
        pii temp = polls[0];
        polls[0] = polls[ind];
        polls[ind]=temp;
    }
    p0 = polls[0];
   // fo(i,n)
    //cout<<polls[i].first<<" "<<polls[i].second<<"a\n";
    //sorting 
    sort(polls.begin()+1,polls.end(), cmp); 
   	
    //fo(i,n)
    //cout<<polls[i].first<<" "<<polls[i].second<<"aa\n";
    // Initializing the size of modified array
    ll m = 1;
   for (ll i=1; i<n; i++) 
   { 
       //cout<<polls[i].first<<" "<<polls[i].second<<"r\n";
       //if angle of i and i+1 is same remove them-
       while (i < n-1 && orientation(p0, polls[i], polls[i+1]) == 0) 
        {
		v.push_back(polls[i]);
		i++;
		}
  
       polls[m] = polls[i]; 
       m++;
   } 

    // convex hull not possible :(
   if (m < 3) return 0;

   //push polls in the stack
   S.push(polls[0]); 
   S.push(polls[1]); 
   S.push(polls[2]); 
  //cout<<polls[0].first<<" "<<polls[1].first<<" "<<polls[2].first<<"aa\n";

//return S;
   // Process remaining  
   for (ll i = 3; i < m; i++) 
   { 
      while (!S.empty() && orientation(nextToTop(S), S.top(), polls[i]) != 2) 
      {
          //cout<<"Yes\n";
          v.push_back(S.top());
          S.pop();
      }
      S.push(polls[i]); 
   } 
   points.clear();
   points = v;
    //cout<<S.size()<<"q\n";
   while(S.size())
    {
    hulls[in].push_back(S.top());
    S.pop();
    }
    int ind1 = 0;
    for(int i = 0; i< points.size(); i++)
    {
    if(check(hulls[in],points[i]))
    points[ind1++]=points[i];
	}
	points.erase(points.begin()+ind1, points.end());
    in++;
    return 1;
}

int main()
{
    io
    //freopen("test.out", "rt", stdin);
    //freopen("test.out", "wt", stdout);
    ll t;
    cin>>t;
    while(t--)
    {
    	fo(i,N)
    	hulls[i].clear();
    	points.clear();
    	in = 0;
        ll n,q, flag = 0;
        cin>>n>>q;
        fo(i,n)
        {
            cin>>a>>b;
            points.push_back({a,b});
        }
        while(!points.empty())
    {
    	
        int i = Hull(points);
        if(!i)
        break;
    }
   // cout<<in<<endl;
    //cout<<hulls[1][0].first<<" "<<hulls[1][0].second<<"a\n";
    //cout<<hulls[1][1].first<<" "<<hulls[1][1].second<<"a\n";
    //cout<<hulls[1][2].first<<" "<<hulls[1][2].second<<"a\n";
    //cout<<hulls[1][3].first<<" "<<hulls[1][3].second<<"a\n";
    while(q--)
    {
    	int ans = 0;
    	     cin>>a>>b; 
    		for(int i = in-1; i>= 0; i--)
    		{
    		if(check(hulls[i],{a,b}))
    		{ans = i+1;break;}
			} 	
    cout<<ans<<"\n";
    }
	    }
    return 0;
}