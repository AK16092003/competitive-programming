/*
	calculate sum of digits from 1 to n
	
	example : 
		n = 10
		
		ans = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + (1 + 0)
			= 46
	
	constraints :
		1 <= n <= 10^18
		
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> digit_array(int n)
{
	vector<int> ans;
	while(n)
	{
		ans.push_back(n%10);
		n = n/10;
	}
	return ans;
}


vector<int> t;

int digit_dp(int ind , int tight , int sum)
{
	int ans = 0;
	if(ind == -1) return sum;
	
	if (tight == 0)
	{
		// un restricted
		for(int i = 0 ; i  <= 9 ; i  ++)
		{
			ans += digit_dp( ind - 1 , 0 , sum + i);
		}
	}
	else{
		// restricted
		int k = t[ind];
		for(int i = 0 ; i < k ; i  ++)
		{
			ans += digit_dp( ind - 1 , 0 , sum + i); 
		}
		ans += digit_dp(ind - 1 , 1 , sum + k);
	}
	
	return ans;
}


int main()
{

	int n;
	cin >> n;
	t = digit_array(n);
	int sz = t.size();
	int ans = digit_dp(sz - 1 , 1 , 0);
		
	cout << "Sum of digits : " << ans << endl;

}