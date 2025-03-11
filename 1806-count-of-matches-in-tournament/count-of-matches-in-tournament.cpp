class Solution {
public:
    int numberOfMatches(int n) {
        int cnt=0;
        while(n!=1){
            if(n%2==0){
                int match=n/2;
                cnt+=match;
                n=n-match;
            }else{
                int matches=(n-1)/2;
                cnt+=matches;
                n=n-matches;
            }
        }
        return cnt;
    }
};