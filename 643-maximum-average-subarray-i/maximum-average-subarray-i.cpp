class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=nums[i];
        }
        double max_ans=(double)ans/k;
        for(int i=1;i<=nums.size()-k;i++){
            ans=ans-nums[i-1]+nums[i+k-1];
            max_ans=max(max_ans,(double)ans/k);
        }
        return max_ans;
    }
};