class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt=0;
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        int deduc=0;
        for(int i=0;i<nums.size()-1;i++){
            deduc+=nums[i];
            sum-=nums[i];
            if(abs(sum-deduc)%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};