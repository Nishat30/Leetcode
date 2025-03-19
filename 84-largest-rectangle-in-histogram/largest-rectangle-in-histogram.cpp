class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele=st.top(); //backtrack kro kyuki nse and pse mil gya haii uss element k
                st.pop();
                int nse=i;//jo element abhi mila hai chota hai n vo issiliye whi nse haii
                int pse=st.empty()?-1:st.top();// the top most element of the stack
                maxArea=max(maxArea,(heights[ele]*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){ //agr stack mein kuch bach jaye toh 
            int nse=n;
            int ele=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,(heights[ele]*(nse-pse-1)));
        }
        return maxArea;
    }
};