class Solution {
public:
    bool check(int a){
        while (a > 0) {
            if (a % 10 == 0) return false; 
            a /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a=1;
        int b=n-a;
        while(!check(b) || !check(a)){
            a++;
            b=n-a;
        }
        return {a,b};
    }
};