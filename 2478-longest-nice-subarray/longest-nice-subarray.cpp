class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size(), ans=0, l= 0;
        int B=0;
        for (int r=0 ; r<n; r++) {
            while (r<n && (B & nums[r])==0) {
                B|= nums[r++];
            }
            ans= max(ans, r-l);
            if (r==n) break;
            while (l<r && (B & nums[r])!= 0) 
                B^=nums[l++];
            B|=nums[r];
        }
        return ans;

    }
};