class Solution {
public:
    vector<vector<int>> build(int n,vector<vector<int>>& rectangles,bool axis){
        vector<vector<int>> intervals;
        for(auto & points:rectangles){
            intervals.push_back(axis?vector<int>{points[0],points[2]}:vector<int>{points[1],points[3]});
        }
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> merged;
        if (intervals.empty()) return merged;

        vector<int> curr=intervals[0];
        for(size_t i=1; i<intervals.size();i++){
            vector<int> next=intervals[i];
            if(curr[1]>next[0]){
                curr[1]=max(curr[1],next[1]);
            }else{
                merged.push_back(curr);
                curr=next;
            }
        }
        merged.push_back(curr);
        return merged;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return false;
        vector<vector<int>> mergedX = build(n, rectangles, true);
        if(mergedX.size()>=3){
            return true;
        }
        vector<vector<int>> mergedY=build(n,rectangles,false);
        if(mergedY.size()>=3){
            return true;
        }
        return false;
    }
};