class Solution {
public:
    int smallestNumber(int n) {
        int ans=0;
        int i=0;
        while(ans<n){
            ans+=pow(2,i);
            i++;
        }
        return ans;
    }
};