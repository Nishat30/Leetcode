class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg_count=0;
        int pos_count=0;
        int ans=0;
        for(int i:nums){
            if(i<0){
                neg_count++;
                ans=max(neg_count,ans);
            }else if(i!=0){
                pos_count++;
                ans=max(pos_count,ans);
            }
        }
        return ans;
    }
};