class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i = find(s.begin(), s.end(), '6') - s.begin();
        if(i < (int)s.length()){
            s[i] = '9';
        }
        return stoi(s);
    }
};