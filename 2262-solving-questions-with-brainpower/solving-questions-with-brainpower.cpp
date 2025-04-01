class Solution {
public:
    long long solve(int idx, int n, vector<long long>& dp, vector<vector<int>>& questions) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        long long take = questions[idx][0]; 
        int nextIdx = idx + questions[idx][1] + 1; 
        if (nextIdx < n) {
            take += solve(nextIdx, n, dp, questions);
        }

        long long not_take = solve(idx + 1, n, dp, questions); 
        return dp[idx] = max(take, not_take);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(0, n, dp, questions);
    }
};
