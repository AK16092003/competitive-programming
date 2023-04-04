
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
		
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


#define maxsz 100005
vi adjlst[maxsz];
lli ans[maxsz];

struct info
{
	map<lli , lli> frq;
	lli count_max;
	lli sum;

	info(lli color)
	{
		frq[color]++;
		count_max = 1;
		sum = color;
	}
};

info *ptr[maxsz];

info* merge(info *a , info *b)
{
	if(a->frq.size() < b->frq.size())
	{
		swap(a , b);
	}

	for(auto k:b->frq)
	{
		int color = k.first;
		int occr = k.second;
		
		if(occr + a->frq[color] == a->count_max)
		{
			a->sum += color;
			a->frq[color] += occr;
		}
		else if(occr + a->frq[color] < a->count_max)
		{
			a->frq[color] += occr;
		}
		else
		{
			a->frq[color] += occr;
			a->count_max = a->frq[color];
			a->sum = color;
		}
	}

	return a;

}
 
void dfs(int u , int p)
{
	for(int v : adjlst[u])
	{
		if(v!=p)
		{
			dfs(v , u);
			ptr[u] = merge(ptr[u] , ptr[v]);
		}
	}
	ans[u] = ptr[u]->sum;
}



void solve(){

	lli n;
	cin >> n;
	vl a(n);

	for(int i = 0 ; i <= n; i  ++)
	{
		adjlst[i].clear();
		ans[i] = 0;
	}
	
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> a[i];
		ptr[i+1] = new info(a[i]);
	}

	for(int i = 0 ; i < n-1 ; i ++)
	{
		int u , v;
		cin >> u >> v;
		adjlst[u].pb(v);
		adjlst[v].pb(u);
	}

	dfs(1 , 0);

	for(int i = 1 ; i <= n ; i ++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;


}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	//int t;cin>>t; while(t--)
    
    solve();
	
	return 0;
}
