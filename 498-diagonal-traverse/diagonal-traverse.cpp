class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        ans.reserve(n * m);

        for (int d = 0; d < n + m - 1; d++) {
            int r = (d < m ? 0 : d - m + 1);
            int c = (d < m ? d : m - 1);

            vector<int> temp;
            while (r < n && c >= 0) {
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }

            if (d % 2 == 0) reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};
