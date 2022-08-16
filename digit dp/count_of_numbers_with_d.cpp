#include<bits/stdc++.h>
using namespace std;
vector<int> digit_array(int n)
{
	vector<int> ans;
	while(n)
	{
		ans.push_back(n%10);
		n = n / 10;
	}
	return ans;
}

vector<int> t;


long int digit_dp( int index , int tight , int d , long int count)
{
	long int ans = 0;
	if(index == -1) return count;
	if(tight == 0)
	{
		// no restriction
		if(count == 1) return pow(10,index + 1);
		for(int i = 0 ; i <= 9 ; i ++)  ans += digit_dp(index-1,0,d,count|((i == d)?1:0));
		
		return ans;
	}
	else
	{
		// restriction
		int k = t[index];
		for(int i = 0 ; i < k ; i ++)ans += digit_dp(index-1,0,d,count|((i == d)?1:0));
		ans += digit_dp(index-1,1,d,count|((k == d)?1:0));
		
		return ans;
	}
}

int main()
{
	long int n ;int d;
	cin >> n >> d;
	t = digit_array(n);
	
	int sz = t.size();
	cout << digit_dp(sz - 1 , 1 , d , 0) << endl;
	return 0;
}