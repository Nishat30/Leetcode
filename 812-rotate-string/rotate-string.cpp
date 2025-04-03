class Solution {
public:
    bool rotateString(string s, string goal) {
        string ans;
        for(char c:s){
            ans.push_back(c);
        }
        for(char c:s){
            ans.push_back(c);
        }
        return s.length()==goal.length() && ans.find(goal) != std::string::npos;
    }
};