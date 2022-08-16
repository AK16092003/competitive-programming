#include<bits/stdc++.h>
using namespace std;

int sz = 200001;

vector<int> parent(sz);

void make_set(int n)
{
	for(int i = 0 ; i < n ; i ++)
	{
		parent[i] = i;
	}
}

int find_set(int u)
{
	if(u == parent[u]) return u;
	// path compression
	parent[u] = find_set(parent[u]);
	return parent[u];
}


int main()
{
	int n , q;
	
	cin >> n >> q;
	make_set(n);
	
	while(q -- )
	{	
		int t , u , v;
		cin >> t >> u >> v;
		if(t == 0)
		{
			// add an edge
			// union the 2 sets
			
			int a = find_set(u);
			int b = find_set(v);
			/*
					u -> a
					v -> b
					
					a---->b
					|     |
					u     v				
			*/
			parent[a] = b;
		}	
		else
		{
			// find whether both lie in same component
			int a = find_set(u);
			int b = find_set(v);
			
			if(a == b)
			{
				cout << 1 << endl;	
			}	
			else
			{
				cout << 0 << endl;
			}
		}
	}
	return  0;
}