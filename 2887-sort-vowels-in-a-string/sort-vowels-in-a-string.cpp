class Solution {
public:
    bool is_vowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string sortVowels(string s) {
        string vow;
        string t;
        for(char i:s){
            if(is_vowel(i)){
                vow.push_back(i);
                t.push_back('/');
            }else if(isalpha(i)){
                t.push_back(i);
            }
        }
        sort(vow.begin(),vow.end());
        int k=0;
        for(char &i:t){
            if(i=='/'){
                i=vow[k];
                k++;
            }
        }
        return t;
    }
};