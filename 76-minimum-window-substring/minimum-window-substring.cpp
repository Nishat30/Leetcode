class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int counter=t.length();
        int begin=0,end=0;
        int d=INT_MAX,head=0;
        //initialize the map
        for(auto i:t){
            mp[i]++;
        }
        while(end<s.length()){
            if(mp[s[end++]]-->0){
                counter--;
            }
            while(counter==0){
                if(end-begin<d) {
                    d=end-(head=begin);
                }
                if(mp[s[begin++]]++==0) counter++;
            }
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};