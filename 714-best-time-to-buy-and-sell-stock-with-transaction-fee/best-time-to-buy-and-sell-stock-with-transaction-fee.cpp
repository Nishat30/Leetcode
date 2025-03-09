class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> prev(2,0),cur(2,0);
        prev[0]=0;
        prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                long profit=0;
                if(buy){
                    profit = max(-prices[i]-fee + prev[0] , 0+ prev[1]);
                }else{ 
                    profit= max(prices[i]+ prev[1] , 0+ prev[0]);
                }
                cur[buy]=profit;
            }
            prev=cur;
        }
        return prev[1];
    }
};