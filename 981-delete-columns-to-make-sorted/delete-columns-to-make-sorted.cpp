class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int j=0;
        int n=strs.size();
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<n-1;j++){
                if(strs[j][i]-'a'>strs[j+1][i]-'a'){
                    ans++;
                    break;
                }
            }
        }
        // if(strs[0].length()==1){
        //     for(int i=0;i<n-1;i++){
        //         if(strs[i][0]>strs[i+1][0])
        //     }
        // }
        return ans;
    }
};