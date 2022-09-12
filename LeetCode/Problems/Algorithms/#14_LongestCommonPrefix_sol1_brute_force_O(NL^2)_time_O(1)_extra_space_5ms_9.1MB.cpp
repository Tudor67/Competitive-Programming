class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int N = strs.size();
        
        int minLength = strs[0].length();
        for(const string& S: strs){
            minLength = min(minLength, (int)S.length());
        }
        
        for(int length = 1; length <= minLength; ++length){
            for(int i = 1; i < N; ++i){
                if(strs[i - 1].compare(0, length, strs[i], 0, length) != 0){
                    return strs[0].substr(0, length - 1);
                }
            }
        }
        
        return strs[0].substr(0, minLength);
    }
};