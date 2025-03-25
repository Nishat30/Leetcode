class Solution {
public:
    double myPow(double x, int n) {
        bool ifNegative = (n < 0);
        if (n == 0) {
            return 1;
        }
        
        double ans = 1;
        
        if (n == INT_MIN) {
            if (abs(x) > 1) {
                return 0;
            }
            return abs(x);
        }
        
        int num = abs(n);
        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
                x *= x;
            } else {
                num--;
                ans *= x;
            }
        }
        
        return ifNegative ? 1 / ans : ans;
    }
};