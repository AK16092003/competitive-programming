#include<stdio.h>
#include<bits/stdc++.h>
#define sz 5000001
using namespace std;

// BIT / FENWICK TREE
int T[sz];
int arr[sz];


int n , q;

int g(int i) {return i&(i+1);}
int h(int i) {return i|(i+1);}

int find_min(int l , int r)
{
	int ans = INT_MAX;
	cout << l << " "<< r << endl;
	while(g(r) >= l && r >= 0)
	{
		ans = min( ans , T[r]);
		r = g(r) - 1;
		cout << r << endl;
	}
	cout << r <<" "<<l<<endl;
	for(int i = r ; i >= l ; i -- ) ans = min(ans , arr[i]);
	return ans;
	
}
void update_min(int index , int x)
{
	int j = index;
	while(j < n)
	{
		T[j] = min(T[j] , x);
		j = h(j);
	}	
}



int main()
{
	for(int i = 0 ; i < sz ; i ++) T[i] = INT_MAX;
	cin >> n >> q;
	for(int i = 0 ; i  < n ; i ++)
	{
		cin >> arr[i];
		update_min( i , arr[i]);
	}
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			// update an element
			int pos , x;
			cin >> pos >> x;
			update_min( pos , x);
		}
		else{
			// find minimum
			int l , r;
			cin >> l >> r;
			int ans = find_min(l , r);
			cout << ans << endl;
		}
	}
	
	
	return 0;
}