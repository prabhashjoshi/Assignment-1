#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 1000005;

struct node
{
    ll mx;
}fake{0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.mx=max(a.mx,b.mx);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.mx=val;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].mx+=lazy[v];
        if(st!=en)
        {
            lazy[v<<1]+=lazy[v];
            lazy[v<<1 | 1]+=lazy[v];
        }
        lazy[v]=0;
        return ;
    }
    void buildTree(ll v,ll st,ll en)
    {
        lazy[v] = 0;
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
    {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            lazy[v]=val;
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

vector<int> v1[N],v2[N];

int dep1[N],dep2[N],in[N],out[N],cur=0;
bool good[N];
int ans = 0;

void dfs1(int s,int p)
{
    for(auto j:v1[s])
    {
        if(j!=p)
        {
            dep1[j] = dep1[s] + 1;
            dfs1(j,s);
        }
    }
}

void dfs2(int s,int p)
{
    in[s] = cur++;
    for(auto j:v2[s])
    {
        if(j!=p)
        {
            dep2[j] = dep2[s] + 1;
            dfs2(j,s);
        }
    }
    out[s] = cur-1;
}

void dfs3(int s,int p)
{
    if(good[s])
        seg.rupdate(1,0,cur-1,in[s],out[s],1);
    amax(ans,seg.query(1,0,cur-1,0,cur-1).mx);
    for(auto j:v1[s])
    {
        if(j!=p)
            dfs3(j,s);
    }
    if(good[s])
        seg.rupdate(1,0,cur-1,in[s],out[s],-1);
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    ans = 0;
    for(int i=0;i<=n;++i)
    {
        seg.a[i] = 0;
        v1[i].clear();
        v2[i].clear();
        good[i] = false;
    }
    cur = 0;
    int r1 = -1;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(x==-1)
            r1 = i;
        else
            v1[x].pb(i);
    }
    int r2 = -1;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(x == -1)
            r2 = i;
        else
            v2[x].pb(i);
    }
    dep1[r1] = dep2[r2] = 0;
    dfs1(r1,0),dfs2(r2,0);
    assert(cur == n);
    seg.buildTree(1,0,n-1);
    for(int i=1;i<=n;++i)
        good[i] = dep1[i] == dep2[i];
    dfs3(r1,0);
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}