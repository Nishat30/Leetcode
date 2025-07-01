class Solution {
public:
    int possibleStringCount(string word) {
        int count=0;
        for(int i=0;i<word.length()-1;i++){
            if(word[i]==word[i+1]){
                count++;
            }
        }
        int ans;
        ans=count+1;
        return ans;
    }
};