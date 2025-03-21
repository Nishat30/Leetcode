class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(auto &supply : supplies) {
            mp[supply] = 1;
        }
        int n=recipes.size();
        vector<int> check(n,0);
        while(n--){
            for(int i=0;i<recipes.size();i++){
                if(check[i]){
                   continue;
                }
                bool can_create=true;
                for(int j=0; j<ingredients[i].size();j++){
                    if(mp.find(ingredients[i][j])==mp.end()){
                        can_create=false;
                        break;
                    }
                }
                if(can_create){
                    ans.push_back(recipes[i]);
                    check[i]=1;
                    mp[recipes[i]]++;
                }
            }
        }
        return ans;
    }
};