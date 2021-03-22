class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> validSortedStrings;
        validSortedStrings.insert("1");
        int p = 1;
        for(int i = 1; i <= 30; ++i){
            p *= 2;
            string s = to_string(p);
            sort(s.begin(), s.end());
            validSortedStrings.insert(s);
        }
        
        string s = to_string(N);
        sort(s.begin(), s.end());
        bool isValid = validSortedStrings.count(s);
        
        return isValid;
    }
};