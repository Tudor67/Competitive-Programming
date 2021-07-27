class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char, int> count;
        for(char c: str){
            count[c] += 1;
        }
        
        string strSorted;
        const string FIXED_ORDER = order + str;
        for(char c: FIXED_ORDER){
            strSorted.append(count[c], c);
            count[c] = 0;
        }
        
        return strSorted;
    }
};