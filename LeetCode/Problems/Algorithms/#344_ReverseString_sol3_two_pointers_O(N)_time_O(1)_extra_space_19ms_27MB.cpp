class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = (int)s.size() - 1;
        while(i < j){
            swap(s[i], s[j]);
            i += 1;
            j -= 1;
        }
    }
};