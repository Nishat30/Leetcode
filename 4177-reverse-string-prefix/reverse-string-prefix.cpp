class Solution {
public:
    string reversePrefix(string s, int k) {
        stack<char> st;
        for(int i=0;i<k;i++){
            st.push(s[i]);
        }
        for(int i=0;i<k;i++){
            s[i]=st.top();
            st.pop();
        }
        return s;
    }
};