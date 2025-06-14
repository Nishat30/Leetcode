class Solution {
public:
    int reverseNumber(int num) {
        int reversed = 0;
        while (num != 0) {
           int digit = num % 10;
           reversed = reversed * 10 + digit;
           num /= 10;
        }
        return reversed;
    }
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
    }
};