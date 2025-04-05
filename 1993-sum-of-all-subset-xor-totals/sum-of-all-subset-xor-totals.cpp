class Solution {
public:
    int find_xor(int i,vector<int>& nums,int x){
        if(i==nums.size()) return x;
        int take=find_xor(i+1,nums,x^nums[i]);
        int not_take=find_xor(i+1,nums,x);
        return take+not_take;
    }
    int subsetXORSum(vector<int>& nums) {
        return find_xor(0,nums,0);
    }
};