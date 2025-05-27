class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divi=0;
        int not_divi=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                not_divi+=i;
            }else{
                divi+=i;
            }
        }
        return not_divi-divi;
    }
};