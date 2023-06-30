#define lli long long int
#define inf 1e5

class Solution {
public:

    lli p[35];
    lli v[35];
    lli dp[35][35][35];

    int n , mk;

    lli recur(int i , int j , int k)
    {

        int len = j - i + 1;

        lli psum = (p[j] - ((i-1>=0)?p[i-1]:0));
        if(k != mk) psum=0;

        if(k == mk)
        {
            if(len == 1) return 0;
            if(len < mk) return inf;
            if(len == mk)
            {
                return psum;
            }
        }

        if(k <= 0) return inf;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        lli ans = inf;

        for(int q = i ; q < j ; q ++)
        {
            if(k-1 == 1)
            {
                ans = min(ans , recur(i , q , mk) + recur(q+1 , j , mk) + psum);
            }
            else
            {
                ans = min(ans , recur(i , q , mk) + recur(q+1 , j , k-1) + psum);
            }
        }
        return dp[i][j][k] = ans;
    }

    int mergeStones(vector<int>& stones, int kk) 
    {
        mk = kk;
        n = stones.size();

        for(int i = 0 ; i < n; i ++)
        {
            v[i] = stones[i];
        }

        p[0] = v[0];

        for(int i = 1 ; i < n ; i ++)
        {
            p[i] = p[i-1] + v[i];
        }

        for(int i =0 ; i <= n ; i ++)
        {
            for(int j = 0 ; j <= n ; j ++)
            {
                for(int k = 0 ; k <= mk ; k ++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }

        int ans = recur(0,n-1,mk);
        if(ans >= inf) return -1;
        return ans;
    }
};
