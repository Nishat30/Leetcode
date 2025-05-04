class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> counts(100, 0);
        int result = 0;
        for (const auto& domino : dominoes) {
            int val1 = domino[0];
            int val2 = domino[1];
            int key = min(val1, val2) * 10 + max(val1, val2);
            result += counts[key];
            counts[key]++;
        }
        return result;
    }
};