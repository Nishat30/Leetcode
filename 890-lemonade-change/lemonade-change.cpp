class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_cnt=0;
        int ten_cnt=0;
        int twenty_cnt=0;
        for(int i:bills){
            if(i==5)five_cnt++;
            else if(i==10){
                if(five_cnt==0)return false;
                else ten_cnt++,five_cnt--;
            }else{
                if(ten_cnt>=1 && five_cnt>=1){
                    ten_cnt--;
                    five_cnt--;
                }else if(five_cnt>=3){
                    five_cnt-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};