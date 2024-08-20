// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
		
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<ll , ll>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef priority_queue<ll> pq;
typedef priority_queue<pair<ll,ll>> pqp;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define printarr(a , n) for(int i = 0 ; i < n  ;i ++) cout << a[i] << " "; cout << endl;
#define endl '\n'
#define sq(a) (a)*(a)
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define inf 1e18
 
int rand(int l, int r){
 	static mt19937 
 	rng(chrono::steady_clock::now().time_since_epoch().count());
 	uniform_int_distribution<int> ludo(l, r); 
 	return ludo(rng);
}
 
char inp[5005][5005];
int n;
bool used[5005];
int mt[5005];
// edges only from left to right
vector<int> adjlst[5005];
 
// edges orientation changed for dfs MVC
vector<int> adjnew[5005][2];
int visited[5005][2];
 
// maintain matching status of left set.
// after performing maximal matching algo
int match[5005];
 
bool kuhn(int u){
    if(used[u]) return false;
    used[u] = true;
    
    for(int v : adjlst[u]){
        if(mt[v] == -1 || kuhn(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}
 
// konig's theorem application
void dfsmvc(int u , int grp){
    visited[u][grp] = 1;
    for(int v : adjnew[u][grp]){
        if(!visited[v][grp^1]){
            dfsmvc(v , grp^1);
        }
    }
}
 
 
void solve()
{
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n ; i ++) mt[i] = -1;
    
    for(int i = 0 ; i < n; i ++){
        string s;
        cin >> s;
        for(int j = 0 ; j < n ; j ++){
            inp[i][j] = s[j];
            if(s[j] == 'o'){
                adjlst[i].pb(j);
            }
        }
    }
    
    for(int i = 0 ; i < n;  i ++) mt[i] = -1;
    
    for(int u = 0 ; u < n ; u ++){
        for(int j = 0 ; j < n ; j ++) used[j] = 0;
        kuhn(u);
    }
    
    
    
    
    for(int i = 0 ; i < n ; i ++){
        for(int j : adjlst[i]){
            if(mt[j] == i){
                match[i] = 1;
                adjnew[j][1].pb(i);
            }
            else{
                adjnew[i][0].pb(j);
            }
        }
    }
    
    for(int i = 0 ; i < n ; i ++){
        if(!match[i]){
            dfsmvc(i , 0);
        }
    }
    
    vpll ans;
    
    for(int i = 0 ; i < n ; i ++){
        if(!visited[i][0]) ans.pb({1 , i+1});
    }
    for(int i = 0 ; i < n ; i ++){
        if(visited[i][1]) ans.pb({2 , i+1});
    }
    
    cout << ans.size() << endl;
    for(auto kk : ans)
    {
        cout << kk.first << " " << kk.second << endl;
    }
}
int main(){
 
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
 
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r" , stdin);
	// 	freopen("output.txt", "w" , stdout);
	// #endif
 
    int t = 1;
 
	for(int i = 1 ; i <= t ; i ++)
	{
    	solve();
	}	
	return 0;
}
 
