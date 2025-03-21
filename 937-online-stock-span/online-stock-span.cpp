class StockSpanner {
public:
    stack<pair<int, int>> st; // Stores {price, span}
    StockSpanner() {}
    
    int next(int price) {    
        int cnt = 1;
        
        // Pop elements from stack while price is greater or equal
        while (!st.empty() && st.top().first <= price) {
            cnt += st.top().second;
            st.pop();
        }

        st.push({price, cnt}); // Push current price with calculated span
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */