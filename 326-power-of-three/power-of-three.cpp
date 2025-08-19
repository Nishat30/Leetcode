class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPowerOf3 = 1162261467; // 3^19 is the largest power of 3 according to constraints
        return n > 0 && maxPowerOf3 % n == 0;
    }
};