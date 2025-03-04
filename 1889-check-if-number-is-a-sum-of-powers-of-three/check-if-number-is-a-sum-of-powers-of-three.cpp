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
        return solve(0,n);
    }
};