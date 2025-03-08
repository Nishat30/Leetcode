class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        for(int i=0;i<blocks.size()-k+1;i++){
            int idx=i;
            int j=0;
            int cnt=0;
            while(j!=k){
                if(blocks[idx]=='W'){
                    cnt++;
                }
                idx++;
                j++;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};