class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while((int)s.length() < k){
            int len = s.length();
            for(int i = 0; i < len; ++i){
                char c = 'a' + (s[i] - 'a' + 1) % 26;
                s.push_back(c);
            }
        }
        return s[k - 1];
    }
};