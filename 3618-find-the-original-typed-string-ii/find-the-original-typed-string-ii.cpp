class Solution {
public:
    int M= 1e9+7;
    int solve(int i,int cnt,vector<int>&freq, int k,vector<vector<int>> dp){
        if(i>=freq.size()){
            if(cnt<k){
                return 1;// found inavlid string
            }
            return 0;
        }
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        long long result=0;
        for(int take=1;take<=freq[i];take++){
            if(cnt+take<k){
                result=(result+solve(i+1,cnt+take,freq,k,dp))%M;
            }
            else{
                break;
            }
        }
        return dp[i][cnt]=result;
    }
    int possibleStringCount(string word, int k) {
        if(k> word.length()) return 0;
        vector<int> freq;
        int cnt=1;
        for(int i=1;i<word.length();i++){
            if(word[i]==word[i-1]){
                cnt++;
            }else{
                freq.push_back(cnt);
                cnt=1;
            }
        }
        freq.push_back(cnt);

        long long P=1;
        for(int &f: freq){
            P=(P*f)%M;
        }
        if(freq.size()>=k){
            return P;
        }
        int n=freq.size();
        // vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        // long long invalidCount= solve(0,0,freq,k,dp);
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int cnt=k-1;cnt>=0;cnt--){
            dp[n][cnt]=1;
        }
        for(int i=n-1;i>=0;i--){
            vector<int> pref(k+1,0);
            for(int h=1;h<=k;h++){
                pref[h]=(pref[h-1]+dp[i+1][h-1])%M;
            }
            for(int cnt=k-1;cnt>=0;cnt--){
                int l=cnt+1;
                int r=cnt+freq[i];
                if(r+1>k){
                    r=k-1;
                }
                if(l<=r){
                    dp[i][cnt]=(pref[r+1]-pref[l]+M)%M;
                }
            }
        }
        long long invalidCount=dp[0][0];
        return (P-invalidCount+M) %M; //negative se bachne k tarika
    }
};