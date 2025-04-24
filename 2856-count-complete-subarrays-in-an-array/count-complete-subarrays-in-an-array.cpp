class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> totalFreq;
        for (int num : nums) {
            totalFreq[num]++;
        }
        int totalDistinct = totalFreq.size();
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> freq;
            int distinctCount = 0;

            for (int j = i; j < nums.size(); j++) {
                if (++freq[nums[j]] == 1) {
                    distinctCount++;
                }
                if (distinctCount == totalDistinct) {
                    count++;
                }
            }
        }
        return count;
    }
};
