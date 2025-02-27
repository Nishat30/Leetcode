class Solution {
public:
    bool solve(int n,int k,string curr,int& cnt,string& result){
        if (curr.length() == n) {
            cnt++;
            if (cnt == k) {
                result = curr; 
                return true;
            }
            return false;
        }
        
        for (char i = 'a'; i <= 'c'; i++) {
            if (!curr.empty() && curr.back() == i) {
                continue;
            }
            if (solve(n, k, curr + i, cnt, result)) {
                return true; 
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        int cnt=0;
        string result = "";
        solve(n, k, "", cnt, result);
        return result;
    }
};