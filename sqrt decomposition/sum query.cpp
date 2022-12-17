#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<lli> vl;
typedef pair<lli,lli> pll;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define sq(a) (a)*(a)
#define yes  cout << "Yes" << endl;
#define no  cout << "No" << endl;

vi a(102400);
vi b(320);
int n , m;

void build(vi a)
{
	for(int i = 0 ; i <= m  ; i ++)
	{
		b[i] = 0; 
	}

	for(int i = 0 ; i <= n  ; i ++)
	{
		int block = i/m;
		b[block] += a[i];
	}
}

void printsqrt()
{

	for(int i = 0 ; i <= m ; i ++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}

void update(int x , int y)
{
	int block = x/m;
	b[block] = 0;
	a[x] = y;
	for(int i = block*m ; i < min(n,(block+1)*m) ; i ++)
	{
		b[block] += a[i];
	}
}
int range(int l , int r)
{
	int ans = 0;
	for(int i = l ;  i <= r ;)
	{
		if(i%m == 0  && i + m - 1 <= r)
		{
			ans += b[i/m];
			i += m;
		}
		else
		{
			ans += a[i];
			i++;
		}
	}
	return ans;
}

void solve(){

	cin >> n;
	m = sqrt(n);

	for(int i = 0 ; i < n ; i ++)
	{
		cin >> a[i];
	}
	
	
	build(a);
	printsqrt();

	int q;
	cin >> q;
	while(q--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			// update
			int x , y;
			cin >> x >> y; x--;
			update(x , y);
		}
		else
		{
			// calculate
			int l , r;cin >> l >> r;
			l--;
			r--;
			cout << range(l , r) << endl; 

		}
		printsqrt();
	}



}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

//	int t;cin>>t; while(t--)
    
    solve();
	
	return 0;
}
