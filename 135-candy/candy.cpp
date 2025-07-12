class Solution {
public:
    int candy(vector<int>& ratings) {
        int n =ratings.size();
        vector<int> cnt(n,1); //cnt[1,1,1]
        //left neighbour check
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                cnt[i]=cnt[i-1]+1; 
            } 
        }
        //[1,1,2]
        
        //right neighbour check
        //cnt[1,1,2]
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                cnt[i]=max(cnt[i],cnt[i+1]+1);
            }
        }
        //cnt=[2,1,2]
        return accumulate(cnt.begin(),cnt.end(),0);
    }
};


