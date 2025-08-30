class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int> mp;
        while (n) {
            int digit = n % 10;
            mp[digit]++;
            n = n / 10;
        }
        
        int cnt = INT_MAX;
        int ans = INT_MAX;
        
        for (auto i : mp) {
            if (i.second < cnt || (i.second == cnt && i.first < ans)) {
                cnt = i.second;
                ans = i.first;
            }
        }
        
        return ans;
    }
};
