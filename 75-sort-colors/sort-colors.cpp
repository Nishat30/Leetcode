class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_cnt=0;
        int one_cnt=0;
        int two_cnt=0;
        for(int i:nums){
            if(i==0)zero_cnt++;
            else if(i==1)one_cnt++;
            else two_cnt++;
        }
        int i=0;
        while(i<nums.size()){
            while(zero_cnt)nums[i]=0,zero_cnt--,i++;
            while(one_cnt)nums[i]=1,one_cnt--,i++;
            while(two_cnt)nums[i]=2,two_cnt--,i++;
        }
    }
};