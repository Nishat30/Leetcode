class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int opr=0;
        for(int i:nums){
            if(i%3==0)continue;
            opr++;
        }
        return opr;
    }
};