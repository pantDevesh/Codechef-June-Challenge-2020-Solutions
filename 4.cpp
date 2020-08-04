#include<bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define ll int
#define fo(i,n) for(int i = 0; i < n; i++)
#define pb push_back 
#define N 100001
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;

void ipg(int,int, vi*);
void dfs(int,int, vi*);

//cp- main tumhe barbaad kar dungi
//me- nain barbaad hona chahta hun...

bool cmp(pll a, pll b)
{
    if(a.first>b.first)
    return true;
    else
    return false;   
}
bool maxValue(pll a, pll b)
{
    if(a.first>b.first||(a.first==b.first&&a.second>b.second))
    return true;
    else
    {
        return false;
    }
}
pll build(vpll &arr, vpll &tree, int low, int high, int pos)
{
    if(high == low)
    {
    tree[pos].first = arr[low].first;
    tree[pos].second=low;
    return tree[pos];
    }
    int mid = low + (high - low) / 2; 
    pll v1 = build(arr, tree, low, mid, pos*2 + 1);
    pll v2 = build(arr, tree, mid + 1, high, pos*2 + 2);
    if(maxValue(v1,v2))
    tree[pos]=v1;
    else
    tree[pos]=v2;
    return tree[pos];
}
  
void update(vpll &arr, vpll &tree, int low, int high,  
                 int index, int pos) 
{ 
    if (index < low || index > high)
{
return;
}
      
    if (low == high)  
    {     
        (tree[pos].first)--;
    } 
    else 
    { 
            int mid = low+(high-low)/2; 
              
            if (index >= low && index <= mid) 
                update(arr, tree, low, mid, index  
                            ,2 * pos + 1); 
            else
                update(arr,tree, mid + 1, high,  
                            index, 2 * pos + 2); 
              
    if(maxValue(tree[2*pos+1],tree[2*pos+2]))
    tree[pos]=tree[2*pos+1];
    else
    tree[pos]=tree[2*pos+2];
    } 
} 

int main()
{
	io
	int t;
    cin>>t;
    while(t--)
    {
        vi adj[N];
        int n,m;
        cin>>n>>m;
        vpll tree(262999);
        ipg(n,m, adj);
        vpll arr,ans;
        ll anss = 0;
        fo(i,n)
        {
            arr.pb({adj[i].size(),i});
        }
    sort(arr.begin(), arr.end());
    int curr = arr.size()-2, flag = 0;
    build(arr, tree, 0, n-1,0);
    while(curr>=0)
    {
        int b1;
        if(flag&&arr[curr].first==0)break;
         b1 = tree[0].second;
    
        
        if(flag && b1==curr)break;
        if(b1==curr)
        b1 = curr+1;

            if(arr[curr].first==0)
            anss++;
            else
            {
               update(arr,tree,0,n-1,curr,0);
                arr[curr].first--;
            }
            if(arr[b1].first==0)
            anss++;
            else
            {
              update(arr,tree,0,n-1,b1,0);
                (arr[b1].first)--;
            }
            ans.pb({arr[curr].second,arr[b1].second});
            curr--;       
    }
    sort(arr.begin(), arr.end());
    for(int i = arr.size()-1; i > 0; i--)
    {	
    if(arr[i].first==0)continue;
        for(int j = i-1; j >= 0; j--)
        {
            while(arr[j].first && arr[i].first)
            {
                ans.pb({arr[i].second, arr[j].second});
                (arr[i].first)--;
                (arr[j].first)--;
            }
            if(arr[i].first==0)
            break;
        }
        if(arr[i].first>0)
        {
            anss+=arr[i].first;
            break;
        }
    }
    cout<<anss<<" "<<ans.size()<<"\n";
    fo(i,ans.size())
      cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n"; 
    }
    return 0;
}



void ipg(int n, int m, vi adj[]){
	int i, u, v;
	while(m--){
		cin>>u>>v;
        u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}