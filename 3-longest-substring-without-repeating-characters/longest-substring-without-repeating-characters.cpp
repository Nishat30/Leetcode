class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int counter;
        int begin=0,end=0;
        int ans=0;
        while(end<s.length()){
            mp[s[end++]]++;

            while(mp[s[end-1]] > 1) {
                mp[s[begin++]]--;
            }

            ans = max(ans, end - begin);
        }

        return ans;
    }
};