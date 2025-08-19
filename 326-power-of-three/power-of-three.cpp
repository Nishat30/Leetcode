class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<0) return false;
        for(int i=0;i<=20;i++){
           if(pow(3,i)==n)return true;
        }
        return false;
    }
};