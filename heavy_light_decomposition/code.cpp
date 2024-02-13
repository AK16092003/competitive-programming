// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

// CSES SUBMISSION: PATH QUERIES
		
#include <bits/stdc++.h>
using namespace std;
 
typedef long long lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<lli , lli>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<lli> vl;
typedef pair<lli,lli> pll;
typedef priority_queue<lli> pq;
typedef priority_queue<pair<lli,lli>> pqp;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define printarr(a , n) for(int i = 0 ; i < n  ;i ++) cout << a[i] << " "; cout << endl;
 
#define sq(a) (a)*(a)
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define inf 1e18
/*
	order_of_key(x) -> number of elements strictly smaller than x
	find_by_order(k) -> kth element 
*/
 
 
const int N = 2e5 + 5;
const int D = 19;
const int S = (1 << D);
 
int n, q, v[N];
vector<int> adj[N];
 
int sz[N], p[N], dep[N];
int st[S], id[N], tp[N];
 
struct segtree
{
	int size;
	vl sums;
	lli defval = 0;
 
	void init(int n)
	{
		size = 1;
		while(size < n) size*=2;
		sums.assign(2*size , defval);
	}
 
	void set(int i , lli v , int x , int  lx , int rx)
	{
		if(rx  - lx == 1)
		{
			sums[x] = v;
			return;
		}
 
		int m = (lx + rx)/2;
		if( i < m)
		{
			set(i , v , 2*x + 1 , lx , m);
		}
		else
		{
			set(i , v , 2*x + 2 , m , rx);
		}
		sums[x] = sums[2*x+1] + sums[2*x+2];
 
	}
	void set(int i , lli v)
	{
		set(i , v, 0 , 0 , size);
	}
	lli sum(int l , int r , int x , int lx , int rx)
	{
		if(lx >= r || l >= rx) return defval;
		if(l <= lx && r >= rx) return sums[x];
		int m = (lx + rx)/2;
		lli s1 = sum(l , r , 2*x+1 , lx , m);
		lli s2 = sum(l , r , 2*x+2 , m , rx);
		return s1 + s2;
	}
	lli sum(int l , int r)
	{
		return sum(l , r , 0 , 0 , size);
	}
};
 
// calculate subtree size, depth , parent node using dfs
 
int dfs_sz(int cur, int par) {
    sz[cur] = 1;
    p[cur] = par;
    for (auto chi : adj[cur]) 
    {
        if (chi == par)
        {
            continue;
        }
        dep[chi] = dep[cur] + 1;
        p[chi] = cur;
        sz[cur] += dfs_sz(chi, cur);
    }
    return sz[cur];
}
 
int ct = 1;     
// ct -> number of leaves filled in segtree
 
// break into chains and build segtree using HLD
 
void dfs_hld(int cur, int par, int top) {
 
    id[cur] = ct++;     // leaf number of node in segment tree
    tp[cur] = top;      // head node of chain
 
    int h_chi = -1, h_sz = -1;
 
    for (auto chi : adj[cur])  // find heavy child
    {
        if (chi == par) continue;
        if (sz[chi] > h_sz) {
            h_sz = sz[chi];
            h_chi = chi;
        }
    }
    
    if (h_chi == -1) return;    // leafnode, no need to proceed
    
    dfs_hld(h_chi, cur, top);   // heavy edge addition
 
    for (auto chi : adj[cur]) 
    {
        if (chi == par || chi == h_chi) continue;
        dfs_hld(chi, cur, chi);         // light edge addition
    }
}
 
int ancestor = -1;
segtree ss;
lli query(int a , int b)
{
	if(a>b)swap(a,b);
	return ss.sum(a,b+1);
}
 
lli path(int x, int y) 
{
    lli ret = 0;
    while (tp[x] != tp[y]) {    // both belong to different chains
 
        if (dep[tp[x]] < dep[tp[y]]) 
            swap(x, y);               // make x node more deeper than y
 
        ret += query(id[tp[x]], id[x]);  
        // range query from x to head of its chain
        
        x = p[tp[x]];           
        // move x higher to next chain
    }
 
    if (dep[x] > dep[y]) 
        swap(x, y);
 
    ancestor = x;
    // both x , y belong to same chain , just one range query is sufficient
    ret += query(id[x], id[y]);
    return ret;
}
 
int main() {
 
  
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w" , stdout);
    #endif
 
	int q;
    cin >> n >> q;
    ss.init(n+1);
    // input graph with weight values
 
    vl a(n);
    for(int i = 0 ; i < n ; i ++) cin >> a[i];
 
    for (int i = 0; i < n-1; i++) {
 
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs_sz(1, 1);
    dfs_hld(1, 1, 1);
 
    for(int i = 0 ; i < n ; i ++) ss.set(id[i+1] , a[i]);
 
 
    while (q--) {
    
    	int t;
    	cin >> t;
    	if(t == 1)
    	{
    		int u , c;
    		cin >> u >> c;
    		ss.set(id[u] , c);
    	}
    	else
    	{
    		int u;
    		cin >> u;
    		cout << path(1 , u) << endl;
 
    	}
    }
 
}
