class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        size_t i = s.find('6');
        if(i != string::npos){
            s[i] = '9';
        }
        return stoi(s);
    }
};