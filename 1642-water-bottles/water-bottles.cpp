class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=numBottles+(numBottles/numExchange); //31
        int left=(numBottles%numExchange)+(numBottles/numExchange); //1+6=7
        while(left>=numExchange){ //7>=4
            cnt++; //32->33
            left=left-numExchange; //7-4=3
            left++;//4
        }
        return cnt;
    }
};