#define lli long long int


lli to_lli(string s)
{
    // convert string to number
    lli ans = 0;
    for(char c : s)
    {
        ans = ans *10 + (c - '0');
    }
    return ans;
}

lli full(lli num , lli len)
{

    // aim of this func is : given first half as input, return complete number , 
    // ans = str(half) + str(reverse(half))
    // be careful  at corner testcases, odd length are handled here

    string s = "";
    while(to_string(num).length()*2 < len) len--;

    for(int i = 0 ; i < len ; i ++) s += ' ';

    int j = 0;
    for(char c : to_string(num))
    {
        s[j] = c;
        s[len-j-1] = c;
        j++;
        if(len-j-1 < j)break;
    }

    return to_lli(s);
}

class Solution {
public:

    string nearestPalindromic(string n) {

        int k = n.length();
        lli num = to_lli(n);
    
        vector<lli> numbers;

        lli half = to_lli(to_string(num).substr(0,(k+1)/2));

        // either increment or decrement half , or keep first half as it is

        numbers.push_back(full(half , k));
        numbers.push_back(full(half+1 , k));
        numbers.push_back(full(half-1 , k));
        
        // corner cases
        numbers.push_back(pow(10,k-1)-1);
        numbers.push_back(pow(10,k)+1);

        pair<lli,lli> mini = {1e10 , 1e18};

        // mini.first -> distance
        // mini.second -> value of palindrome number    

        // numbers vector contains all possible valid numbers which needs to be checked

        for(lli p : numbers)
        {
            if(p != num)
            {
                // if condition satisfy..
                // take number with min distance
                
                mini = min(mini  , {abs(num-p), p});
            }
        }

        return to_string(mini.second);
    }
};
