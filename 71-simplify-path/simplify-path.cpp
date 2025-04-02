class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int i = 0; i < path.size(); i++){
            if (path[i] == '/') continue; 
            string dir = "";
            while (i < path.size() && path[i] != '/') {
                dir += path[i];
                i++;
            }
            if (dir == ".") continue; 
            else if (dir == "..") {
                if (!st.empty()) st.pop(); // Move up one directory
            } 
            else {
                st.push(dir); // Valid directory name
            }
        }
        string ans;
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};