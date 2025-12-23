class Solution {
public:
    int n;
    int dp[2][100000];// (i, j=index)
    vector<int> next;
    int f(int i, int j, vector<vector<int>>& events){
        if (i>=2 || j>=n) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int v=events[j][2];
        int take=v+f(i+1, next[j], events);
        int skip=f(i, j+1, events);
        return dp[i][j]=max(take, skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        sort(events.begin(), events.end());
        next.resize(n);
        for(int j=0; j<n; j++)
            next[j]=upper_bound(events.begin()+j, events.end(), vector<int>{events[j][1], INT_MAX, INT_MAX})-events.begin();

        memset(dp, -1, sizeof(dp));
        return f(0, 0, events);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
};