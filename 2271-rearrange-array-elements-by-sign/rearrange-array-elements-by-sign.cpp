class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int i = 0, j = 0;  // i -> positive index, j -> negative index
        int k = 0;  // Final array index

        while (k < n) {
            if (k % 2 == 0) {  
                while (i < n && nums[i] < 0){
                    i++; 
                } 
                result[k] = nums[i++];
            } else {  
                while (j < n && nums[j] > 0){
                    j++;
                }
                result[k] = nums[j++];
            }
            k++;
        }
        return result;
    }
};
