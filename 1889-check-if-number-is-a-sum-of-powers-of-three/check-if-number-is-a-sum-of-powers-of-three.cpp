class Solution {
public:
    bool solve(int i,int target){
        if(target==0) return true; //tada!! mil gya
        if(pow(3,i)>target)return false;
        bool not_pick=solve(i+1,target);
        bool pick=solve(i+1,target-pow(3,i));
        return not_pick || pick;
    }
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            int rem = n % 3; // Get remainder when divided by 3
            if (rem == 2) return false; // If remainder is 2, we can't represent using 0s and 1s
            n /= 3; // Reduce n for the next iteration
        }
        return true;
    }
};