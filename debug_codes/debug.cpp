
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
		
#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<lli , lli>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
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
#define endl '\n'
#define sq(a) (a)*(a)
#define yes  cout << "YES" << endl;
#define no  cout << "NO" << endl;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define inf 1e18


// DEBUG PARAMETERS

#define low 2
#define small_tst_debug_value  10000

#define high small_tst_debug_value
#define tests 10000000/small_tst_debug_value

#define elements_low 1
#define elements_high 100000


vi random_vector(int n)
{
	vi ans(n,0);
	int range_length = elements_high - elements_low + 1; 
	for(int i = 0 ; i < n ; i ++)
	{
		ans[i] = elements_low + (rand()%range_length);
	}
	return ans;
}



bool solve(int n , vi arr)
{
	int gg = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		gg = __gcd(gg , arr[i]);
	}
	
	int mini = INT_MAX;
	for(int i = 1 ; i < n ; i ++)
	{
		mini = min(mini , arr[i]);
	}
	return gg == mini;
}

bool bruteforce(int n , vi arr)
{
	for(int i = 0 ; i < n ; i ++)
	{
		bool flag = true;

		for(int j = 0 ; j < n ; j ++)
		{
			if(arr[j]%arr[i])
			{
				flag = false;
				break;
			}
		}

		if(flag) return true;
	}
	return false;
}


void debug(){

	bool flag = true;

	for(int n = low ; n <= high ; n ++)
	{
		for(int k = 0 ; k  < tests ; k ++)
		{
			vi array = random_vector(n);
			auto ans1 = solve(n , array);
			auto ans2 = bruteforce(n , array);

			if(ans1 != ans2)
			{
				cout << endl;
				cout << "TESTCASE "<<k<<" -> WA FAILED" << endl;
				cout << endl;
				cout << n << endl;
				print(array);
				cout << endl;
				cout << "EXPECTED : " << ans2 << endl;
				cout << "OUTPUT   : " << ans1 << endl;

				flag = false;
				break;
			}
		}

		if(!flag)
		{
			cout << endl;
			cout << "------EXECUTION COMPLETED------" << endl;
			cout << endl;
			break;
		}
		cout << n << "  done ..." << endl;
	}




}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	srand(time(0));
	debug();
	
	return 0;
}

