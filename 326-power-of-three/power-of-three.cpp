class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int x = round(log(n)/log(3));
        return (n==pow(3,x));
    }
};