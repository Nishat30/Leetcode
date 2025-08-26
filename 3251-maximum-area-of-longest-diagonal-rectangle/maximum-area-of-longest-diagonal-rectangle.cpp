class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi=1;
        int max_area=1;
        float max_dia=0;
        for(auto i:dimensions){
            float dia= 1LL*i[0]*i[0] + 1LL*i[1]*i[1];
            if(dia>max_dia){
                maxi=i[0]*i[1];
                max_dia=dia;
            }
            if(dia==max_dia){
                maxi=max(maxi,i[0]*i[1]);
            }
        }
        return maxi;
    }
};