#include<bits/stdc++.h>
#define max_sz 5000001
#define lli long long int
using namespace std;


/*

t[i] = sum(A[j])  g(i) <= j <= i

*/

/*
A[i] is incremented by x
T[j] should be incremented by x whenever , A[i] is part of its sum
T[j] = sum(A[i]) g(j) <= i <= j
for all j such that g(j) <= i <= j
	increment T[j] by x;

*/

vector<lli> T(max_sz , 0);
int n , q;

void increase(int ind , lli x)
{
	int j = ind;
	
	while(j < n)
	{
		T[j] += x;
		j = j|(j+1);
	}
}



lli sum(int r)
{
	//cout << "sum " << r << endl;
	lli ans = 0;
	while(r >= 0)
	{
		ans += T[r];
	//	cout << r << endl;
		r = (r&(r+1)) - 1;
	}
	return ans;
}


int main()
{
	cin >> n >> q;
	lli arr[n];
	for(int i = 0 ; i < n ; i ++) {
		cin >> arr[i];
		increase(i , arr[i]);
	}
	/*
	cout << " T = ";
	for(int i = 0 ; i < n ; i ++)
	{
		cout << T[i] <<" ";
	}cout << endl;
	*/
	while(q -- )
	{
		int query;
		cin >> query;
		if(query == 0)
		{
			int p ; lli x;
			cin >> p >> x;
			increase( p , x);
		}
		else
		{
			int l , r;
			cin >> l >> r;
			lli ans = sum(r-1) - sum(l-1);
			cout << ans << endl;
		}
	}
	
	return 0;
}