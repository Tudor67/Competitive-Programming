class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int N = strs.size();
        const int L = strs[0].length();
        
        for(int length = 1; length <= L; ++length){
            for(int i = 1; i < N; ++i){
                if(length - 1 >= (int)strs[i - 1].length() ||
                   length - 1 >= (int)strs[i].length() ||
                   strs[i - 1][length - 1] != strs[i][length - 1]){
                    return strs[0].substr(0, length - 1);
                }
            }
        }
        
        return strs[0].substr(0, L);
    }
};