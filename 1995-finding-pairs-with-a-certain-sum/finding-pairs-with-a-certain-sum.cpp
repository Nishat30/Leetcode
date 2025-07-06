// Method - 01 
class FindSumPairs {
public:
    vector<int> a,b;
    unordered_map<int,int> uma, umb;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // a=nums1;
        b=nums2;

        for(auto& val:nums1){uma[val]++;}
        for(auto& val:b){umb[val]++;}
    }
    
    void add(int index, int val) {
        umb[b[index]]--;
        b[index] += val;
        umb[b[index]]++;
    }
    
    int count(int tot) {
        int pairs = 0;
        
        for(auto& [val,freq]:uma){
            int remain = tot - val;

            if(umb.count(remain)){
                int calc = freq * umb[remain];
                pairs += calc;
            }
        }

        return pairs;
    }
};