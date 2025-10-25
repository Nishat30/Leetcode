class Solution {
public:
    int totalMoney(int n) {
        long long ans=0;
        int j=1;
        int c=n;
        while(c!=0){
            int cnt=0;
            int i=j;
            while(cnt<7 && c > 0){
                ans+=i;
                i++;
                cnt++;
                c--;
            }
            j++;
        }
        return ans;
    }
};