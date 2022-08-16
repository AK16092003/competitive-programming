/*

sum of numbers in a given range

*/



#include<bits/stdc++.h>
using namespace std;


vector<int> digit_array(int n)
{
	vector<int> ans;
	while(n)
	{
		ans.push_back(n%10);
		n=n/10;
	}
	return ans;
}

vector<int> t;
int digit_dp( int ind , int tight , int sum)
{
	int ans = 0;
	if(ind == -1) return sum;
	if(tight == 0)
	{
		return (45)*(ind + 1)*((int)pow(10 , ind)) + (sum*((int)pow(10 , ind+1)));
	}
	else
	{
		int k = t[ind];
		for(int i = 0 ; i < k ; i ++)
		{
			ans += digit_dp(ind - 1 , 0 , sum + i);
		}
		ans += digit_dp(ind - 1 , 1 , sum + k );
		return ans;
	}
}

int main()
{
	int test_case;
	cin >> test_case;
	while(test_case-- )
	{
		int a,b;
		cin >> a >> b;
		int ans = 0;
		t = digit_array(a-1);
		ans -= digit_dp(t.size() - 1, 1 , 0);
		
		t = digit_array(b);
		ans += digit_dp(t.size() - 1, 1 , 0);
		cout << ans << endl;
	}
}