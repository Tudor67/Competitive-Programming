class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = (int)s.size() - 1; i < j; ++i, --j){
            swap(s[i], s[j]);
        }
    }
};