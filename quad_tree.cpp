
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

struct node 
{
	struct node *NW,*NE,*SW,*SE;
	int data;
};

struct node *init(int n , int m)
{
	if(n == 0 || m == 0) return NULL;

	struct node *new_node = (struct node *) malloc(sizeof(struct node));

	if(n == 1 && m == 1)
	{
		new_node->NW = NULL;
		new_node->NE = NULL;
		new_node->SW = NULL;
		new_node->SE = NULL;
		new_node->data = 0;
		return new_node;
	}

	new_node->NW = init( n/2,        m/2);
	new_node->NE = init( n/2,    (m+1)/2);
	new_node->SW = init((n+1)/2,     m/2);
	new_node->SE = init((n+1)/2, (m+1)/2);
	new_node->data = 0;
	return new_node;
}

void set_value(int i , int j ,int v, int l , int r , struct node *root)
{
	if(root == NULL) return;

	if(l == 1 && r == 1)
	{
		root->data = v;
		return;
	}

	int mid1 = l/2;
	int mid2 = r/2;

	if(i <= mid1 && j <= mid2)
	{
		set_value(i , j , v , l/2 , r/2 , root->NW);
	}
	else if(i <= mid1 && j > mid2)
	{
		set_value(i , j-mid2 , v , l/2 , (r+1)/2 , root->NE);
	}
	else if(i > mid1 && j <= mid2)
	{
		set_value(i-mid1 , j , v , (l+1)/2 , r/2 , root->SW);
	}
	else if(i > mid1 && j > mid2)
	{
		set_value(i-mid1 , j-mid2 , v , (l+1)/2 , (r+1)/2 , root->SE);
	}

	root->data = 0;
	if(root->NW != NULL) root->data += root->NW->data;
	if(root->NE != NULL) root->data += root->NE->data;
	if(root->SW != NULL) root->data += root->SW->data;
	if(root->SE != NULL) root->data += root->SE->data;
}

void solve(){

	struct node *root = init(5,5);
	set_value(1,1,10,5,5,root);
	cout << root->data << endl;
	set_value(1,4,10,5,5,root);
	cout << root->data << endl;
	set_value(3,3,10,5,5,root);
	cout << root->data << endl;
	set_value(4,4,10,5,5,root);
	cout << root->data << endl;
	set_value(5,5,10,5,5,root);
	cout << root->data << endl;

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
