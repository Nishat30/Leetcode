class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long count = 0, sum = 0;
        for (int num : nums) {
            if (num == 0) {
                count++;   
                sum += count;  
            } else {
                count = 0;  
            }
        }
        return sum;
    }
};