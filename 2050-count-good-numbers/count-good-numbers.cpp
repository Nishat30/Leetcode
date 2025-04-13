class Solution {
public:
    int mod=1e9+7;
    long long power(long long base, long long exp) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odd = (n + 1) / 2;   // positions for even digits (5 choices)
        long long even = n / 2;       // positions for prime digits (4 choices)
        return (int)((power(5, odd) * power(4, even)) % mod);
    }
};