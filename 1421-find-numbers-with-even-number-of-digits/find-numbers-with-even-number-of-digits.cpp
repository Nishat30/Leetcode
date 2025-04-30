class Solution {
public:
    int count_digits(int c){
        int cnt=0;
        while(c){
            cnt++;
            c/=10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i:nums){
            if(count_digits(i)%2==0) ans++;
        }
        return ans;
    }
};