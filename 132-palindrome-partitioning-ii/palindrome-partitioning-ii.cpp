class Solution {
public:
    bool isPalindrome(int left, int right, string &s)
    {
        while(left < right)
        {
            if(s[left] != s[right])return false;
            left++;
            right--;
        }
        return true;
    }
    int solve(string s, int left, int right, vector<int>&dp)
    {
        int sz = (int)s.size();
        
        if(right == sz - 1)return 0;
        if(dp[right] != -1)return dp[right];
        
        
        int op = 0;
        int temp = INT_MAX - 1;
        for(int i = sz - 1; i > right; i--)
        {
          
            if(isPalindrome(right + 1, i, s))
            {
                temp = min(temp, 1 + solve(s, right + 1, i, dp));
            }
        }
        op = temp;
        return dp[right] = op;
    }
    int minCut(string s) {
        int sz = (int)s.size();
        vector<int>dp(sz + 1, -1);
        int ans = INT_MAX;
      
        for(int i = sz - 1; i >= 0; i--)
        {
            if(isPalindrome(0, i, s))
            {
                ans = min(ans, solve(s, 0, i, dp));
            }
        }
        return ans;
    }
};