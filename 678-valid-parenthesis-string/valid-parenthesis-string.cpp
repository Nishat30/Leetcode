class Solution {
public:
    bool checkValidString(string s) {
        //greedy approach
        int min=0; 
        int max=0;
        for(char i:s){
            if(i=='('){
               min=min+1;
               max=max+1; 
            }
            else if(i==')'){
                min=min-1;
                max=max-1;
            }else{
                min=min-1;
                max=max+1;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        return (min==0);
        //t.c=O(n) 
        //s.c=O(1)
    }
};