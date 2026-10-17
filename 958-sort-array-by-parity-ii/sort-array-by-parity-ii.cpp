class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0;
        int j=1;
        int k=0;
        vector<int> ans(nums.size());
        while(k<nums.size()){
            if(nums[k]%2==0){
                ans[i]=nums[k];
                i=i+2;
            }else{
                ans[j]=nums[k];
                j=j+2;
            }
            k++;
        }
        return ans;
    }
};