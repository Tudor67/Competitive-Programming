class Solution {
private:
    bool isValid(vector<string>& strs, int length){
        const int N = strs.size();
        for(int i = 1; i < N; ++i){
            if(strs[i - 1].compare(0, length, strs[i], 0, length) != 0){
                return false;
            }
        }
        return true;
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int N = strs.size();
        
        int minLength = strs[0].length();
        for(const string& S: strs){
            minLength = min(minLength, (int)S.length());
        }
        
        int l = 0;
        int r = minLength;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(strs, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return strs[0].substr(0, r);
    }
};