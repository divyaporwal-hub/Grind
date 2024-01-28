/* Jai Mata di */
/* Sankatmochan ki Jai */
#include<bits/stdc++.h>
using namespace std;
#define int               long long int


int n,m;
vector<int>arr,seg;

void build(int id=1, int l=0, int r=n)
{
    if(r-l==1)
    {
        seg[id]=arr[l];
        return ;
    }
    int mid= (l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid,r);
    seg[id]=min(seg[id*2],seg[id*2+1]);
}

int query(int x, int y, int id=1, int l=0, int r=n)
{
    if(l>=x and r<=y)
    {
        return seg[id];
    }
    if(l>=y or r<=x)
    {
        return INT_MAX;
    }
    int mid= (l+r)/2;
    return min(query(x,y,2*id,l,mid), query(x,y,2*id+1,mid,r));    
}

void modify(int pos, int val, int id=1, int l=0, int r=n)
{
    if(r-l==1)
    {
        arr[pos]=val;
        seg[id]=val;
        return ;
    }
    int mid= (l+r)/2;
    if(pos<mid)
    {
        modify(pos,val,2*id,l,mid);
    }
    else
    {
        modify(pos,val,2*id+1,mid,r);
    }
    seg[id]=min(seg[id*2],seg[id*2+1]);
}
 
void solve(){
    
    cin>>n>>m;
    arr.resize(n);
    seg.resize(4*n+1);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build();
    while(m--)
    {
        int type;
        cin>>type;
        int x,y;
        cin>>x>>y;
    
        if(type==1)
        {
            modify(x,y);
        }
        else
        {
            cout<<query(x,y)<<"\n";
        }
    }
    
}

 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
        
}
