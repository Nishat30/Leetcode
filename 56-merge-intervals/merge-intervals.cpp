class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        vector<int> tempIntervals=intervals[0];
        int i=1;
        int n=intervals.size();
        while(i<n){
            if(intervals[i][0]<=tempIntervals[1]){
                tempIntervals[1]=max(intervals[i][1],tempIntervals[1]);
            }else{
                res.push_back(tempIntervals);
                tempIntervals=intervals[i];
            }
            i++;
        }
        res.push_back(tempIntervals);
        return res;
    }
};