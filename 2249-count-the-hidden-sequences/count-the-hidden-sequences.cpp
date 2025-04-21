class Solution {
public:
    #define ll long long
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll sum = 0;
        ll maxi = 0, mini = 0;

        for (int i = 0; i < differences.size(); ++i) {
            sum += differences[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }

        // The range of valid starting points
        ll validLow = lower - mini;
        ll validHigh = upper - maxi;
        // Number of valid starting points within [lower, upper]
        return max(0LL, validHigh - validLow + 1);
    }
};