class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        
        // sort by x, then by y
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        int cnt = 0;
        
        // check all pairs (not just i<j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                // allow equal x/y (line cases)
                if (x1 <= x2 && y1 >= y2) {
                    bool valid = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int x = points[k][0], y = points[k][1];
                        if (x >= x1 && x <= x2 && y >= y2 && y <= y1) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) cnt++;
                }
            }
        }
        
        return cnt;
    }
};
