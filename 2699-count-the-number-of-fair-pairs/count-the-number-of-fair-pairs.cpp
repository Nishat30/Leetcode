class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        deque<int>vc;
        sort(nums.begin(),nums.end());
        for(auto i:nums) vc.push_back(i);
        long long int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            vc.pop_front();
            int low=lower-nums[i],up=upper-nums[i];
            auto left=lower_bound(vc.begin(),vc.end(),low);
            auto right=upper_bound(vc.begin(),vc.end(),up);
            ans+=(right-left);
        }
        return ans;
    }
};
