class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3, -1);
        int ans = 0;
        for(int i=0; i<s.length(); i++) {
        last[(int)(s[i] - 'a')] = i;
            if(last[0] != -1 and last[1] != -1 and last[2] != -1) {
                int from = min(last[0], min(last[1], last[2]));
                ans += (from + 1);
            }
        }
        return ans;
    }
};