class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int prefix[n],suffix[n];
        prefix[0]=height[0];
        for(int i=1;i<n;i++){
           prefix[i]=max(prefix[i-1],height[i]);
        }
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
           suffix[i]=max(suffix[i+1],height[i]);
        }
        int WT=0;
        for(int i=0;i<n;i++){
            WT+=min(prefix[i],suffix[i])-height[i];
        }
        return WT;
    }
};


/*
APPROACH 1:
   bruteForce 
    int trap(vector<int>& height) {
        int waterTrapped=0;
        for(int i=0;i<height.size();i++){
            int LM=0,RM=0;
            for(int j=i;j>=0;j--){
               LM=max(LM,height[j]);
            }
            for(int j=i;j<height.size();j++){
                RM=max(RM,height[j]);
            }
            waterTrapped+=min(LM,RM)-height[i];
        }
        return waterTrapped;
    }
    
APPROACH 2:
    BETTER

    
*/
