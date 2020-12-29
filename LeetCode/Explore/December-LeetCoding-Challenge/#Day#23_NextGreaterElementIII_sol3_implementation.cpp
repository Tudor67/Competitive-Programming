class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        int idxOfMaxDigit = (int)s.length() - 1;
        for(int i = (int)s.length() - 2; i >= 0; --i){
            if(s[i] >= s[idxOfMaxDigit]){
                idxOfMaxDigit = i;
            }else{
                int minIdx = -1;
                for(int j = i + 1; j < s.length(); ++j){
                    if(s[i] < s[j] && (minIdx == -1 || s[j] <= s[minIdx])){
                        minIdx = j;
                    }
                }
                swap(s[i], s[minIdx]);
                reverse(s.begin() + i + 1, s.end());
                break;
            }
        }
        
        if(to_string(n) >= s || (s.length() == to_string(INT_MAX).length() && s > to_string(INT_MAX))){
            s = "-1";
        }
        
        return stoi(s);
    }
};