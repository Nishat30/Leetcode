class Solution {
public:
    pair<int, int> countZerosOnes(const string &s) {
    int zeros = 0, ones = 0;
    for (char c : s) {
        if (c == '0') zeros++;
        else if (c == '1') ones++;
    }
    return {zeros, ones};
}

// Recursive helper function
int helper(vector<pair<int, int>> &counts, int index, int m, int n, vector<vector<vector<int>>> &dp) {
    // Base case: all strings processed
    if (index == counts.size()) return 0;

    // If already computed, return memoized result
    if (dp[index][m][n] != -1)
        return dp[index][m][n];

    int zeros = counts[index].first;
    int ones = counts[index].second;

    // Option 1: skip current string
    int notTake = helper(counts, index + 1, m, n, dp);

    // Option 2: take current string (if possible)
    int take = 0;
    if (zeros <= m && ones <= n) {
        take = 1 + helper(counts, index + 1, m - zeros, n - ones, dp);
    }

    // Store and return max of both choices
    return dp[index][m][n] = max(take, notTake);
}

int findMaxForm(vector<string> &strs, int m, int n) {
    vector<pair<int, int>> counts;
    for (auto &s : strs)
        counts.push_back(countZerosOnes(s));

    // Initialize DP array with -1
    int len = strs.size();
    vector<vector<vector<int>>> dp(len + 1,
        vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

    return helper(counts, 0, m, n, dp);
}
};