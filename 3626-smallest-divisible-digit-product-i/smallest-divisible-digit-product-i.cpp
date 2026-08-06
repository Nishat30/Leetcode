class Solution {
public:
    bool check(int n,int t){
        int prod=1;
        int temp=n;
        while(temp!=0){
            int dig=temp%10;
            prod*=dig;
            temp/=10;
        }
        if(prod==0)return true;
        if(prod%t==0)return true;
        else return false;
    }
    int smallestNumber(int n, int t) {
        while(!check(n,t)){
            n=n+1;
        }
        return n;
    }
};