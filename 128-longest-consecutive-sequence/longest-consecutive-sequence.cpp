class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for (int num : s) {
            if (s.find(num - 1) == s.end()) {  
                int currentNum = num;
                int cnt = 1;
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};