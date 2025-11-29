class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        return sum%k;
    }
};