#include <bits/stdc++.h>
using namespace std;


int rand(int l, int r){
 	static mt19937 
 	rng(chrono::steady_clock::now().time_since_epoch().count());
 	uniform_int_distribution<int> ludo(l, r); 
 	return ludo(rng);
}


void solve()
{
	// just write ur code here
	int n;
	cin >> n;
	cout << n+1 << endl;
}

void generate_testcase(int limit)
{
	// generate testcases
	int n;
	n = rand()%limit;
	cout<<n<<endl;
}


int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	// small cases 

	for(int i = 0 ; i <= 9 ; i ++)
	{	


		string inpfile = "input0";
		inpfile += to_string(i);
		inpfile += ".txt";


		#ifndef ONLINE_JUDGE
			freopen(inpfile.c_str() , "w" , stdout);
		#endif

		generate_testcase(100);
		cout.flush();

		string outfile = "output0";
		outfile += to_string(i);
		outfile += ".txt";

		#ifndef ONLINE_JUDGE
			freopen(inpfile.c_str() , "r" , stdin);
			freopen(outfile.c_str() ,  "w" , stdout);
		#endif

    	solve();
    	cout.flush();
	}	
	

	// large cases
	for(int i = 10 ; i <= 20 ; i ++)
	{	


		string inpfile = "input";
		inpfile += to_string(i);
		inpfile += ".txt";


		#ifndef ONLINE_JUDGE
			freopen(inpfile.c_str() , "w" , stdout);
		#endif

		generate_testcase(10000000);
		cout.flush();

		string outfile = "output";
		outfile += to_string(i);
		outfile += ".txt";

		#ifndef ONLINE_JUDGE
			freopen(inpfile.c_str() , "r" , stdin);
			freopen(outfile.c_str() ,  "w" , stdout);
		#endif

    	solve();
    	cout.flush();
	}	

	return 0;
}



