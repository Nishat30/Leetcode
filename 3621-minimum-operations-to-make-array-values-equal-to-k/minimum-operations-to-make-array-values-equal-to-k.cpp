class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<101> hasX=0;
        for(int x: nums){
            if (x<k) return -1;
            hasX[x]=1;
        }
        return hasX.count()-hasX[k];
    }
};