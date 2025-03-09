class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //space optimization
        int n=prices.size();
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> curr(2,0);
        for(int i=n-1;i>=0;i--){
            //buy
            curr[1] = max(-prices[i] + front1[0] , 0+ front1[1]);
            //sell
            curr[0]= max(prices[i] + front2[1] , 0+ front1[0]);  

            front2=front1;
            front1=curr;          
        }
        return curr[1];
    }
};