class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        long long result=0;
        unordered_map<int,int> mp;
        long long cnt=0;
        while(j<n){
            // Count how many new pairs we get by adding nums[j]
            cnt += mp[nums[j]];
            mp[nums[j]]++;

            // Shrink the window from the left while we have enough pairs
            while (cnt >= k) {
                result += (n - j); // All subarrays starting at i to n-1 and ending at j are valid
                cnt -= (mp[nums[i]] - 1);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return result;
    }
};