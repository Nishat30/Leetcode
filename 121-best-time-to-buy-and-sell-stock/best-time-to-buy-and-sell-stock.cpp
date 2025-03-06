class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        long right=1;
        int profit=0;
        while(right<prices.size()){
            if(prices[left]>prices[right]){
                left=right;
            }else{
                int diff=prices[right]-prices[left];
                profit=max(profit,diff);
            }
            right++;
        }
        return profit;
    }
};