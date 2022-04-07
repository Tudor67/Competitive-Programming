class Solution {
public:
    void reverseString(vector<char>& s) {
        const int N = s.size();
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            swap(s[i], s[j]);
        }
    }
};