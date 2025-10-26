class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt=0;
        int cnt=0;
        for(int i:nums){
            if(i==1){
                cnt++;
            }else{
                max_cnt=max(cnt,max_cnt);
                cnt=0;
            }
        }
        max_cnt=max(cnt,max_cnt);
        return max_cnt;
    }
};