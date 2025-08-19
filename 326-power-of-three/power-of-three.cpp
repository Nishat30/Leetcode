class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int value = 1; 
        for (int i=0; i<=19;i++) {
            if (value==n) return true;
            value = (value<<1)+value;  // value*2 + value
        }
        return false;
    }
};