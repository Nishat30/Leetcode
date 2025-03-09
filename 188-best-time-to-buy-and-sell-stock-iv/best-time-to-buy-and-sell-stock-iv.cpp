class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> next(2*k+1,0),curr(2*k+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int trans=0;trans<2*k;trans++){
                long profit=0;
                if(trans%2==0){ //buy wala case
                    profit=max(-prices[idx]+next[trans+1], 0+next[trans]);
                }else{//sell wala case
                    profit=max(prices[idx]+next[trans+1], 0+next[trans]);
                }
                curr[trans]=profit;
            }
            next=curr;
        }
        return next[0];
    }
};