class Solution {
public:
    int findLUSlength(string a, string b) {
        int maxLength = -1;
        if(a != b){
            maxLength = max(a.length(), b.length());
        }
        return maxLength;
    }
};