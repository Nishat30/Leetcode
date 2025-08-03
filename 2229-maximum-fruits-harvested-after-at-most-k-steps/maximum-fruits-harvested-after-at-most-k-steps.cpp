class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = 2 * 100000 +1;

        vector<int> prefix(n);

        for(auto it: fruits){
            prefix[it[0]] = it[1];
        }
        for(int i = 1 ;i< prefix.size();i++)
            prefix[i] += prefix[i-1];

        int maxi =0;

        // go to right

        for(int i = startPos; i <= min(startPos+k , n-1);i++){
            int r = i;
            int x = i-startPos;
            int l = startPos - (k-2*x);
            l = min(l , startPos);
            int sum = prefix[r];
            if(l > 0){
                sum -= prefix[l-1];
            }
            maxi = max(maxi , sum);
        }

        //go to left
        for(int i = startPos; i >= max(startPos-k , 0);i--){
            int l = i;
            int x = startPos-i;
            int r = startPos + (k-2*x);
            r = max(min(n-1, r) , startPos);
            int sum = prefix[r];
            if(l > 0){
                sum -= prefix[l-1];
            }
            maxi = max(maxi , sum);
        }

        return maxi;
    }
};