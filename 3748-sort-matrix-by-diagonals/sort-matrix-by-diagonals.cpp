class Solution {
public:
    void make_output_arr(vector<vector<int>>& output,vector<vector<int>>& ans,int n){
        int r=0;
        int c=n-1;
        int j=0;
        for(int i=0;i<2*n-1;i++){
            int size=ans[j].size();
            int row=r;
            int col=c;
            int k=0;
            while(row>=0 && col>=0 && col<n && row<n && k<size){
                output[row][col]=ans[j][k];
                k++;
                col++;
                row++;
            } 
            if(i<(2*n-1)/2){
                r=0;
                c--;
            }else{
                r++;
                c=0; 
            }
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        bool flag =true;
        int r=0;
        int c=n-1;
        vector<vector<int>> ans;
        for(int i=0;i<2*n-1;i++){
            vector<int> temp;
            int col=c;
            int row=r;
            while(row>=0 && col>=0 && col<n && row<n){
                temp.push_back(grid[row][col]);
                col++;
                row++;
            } 
            if(i<(2*n-1)/2){
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
                r=0;
                c--;
            }else{
                sort(temp.begin(),temp.end());
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                r++;
                c=0; 
            }
        }
        vector<vector<int>> output(n, vector<int>(n, 0)); 
        make_output_arr(output,ans,n);
        return output;
    }
};