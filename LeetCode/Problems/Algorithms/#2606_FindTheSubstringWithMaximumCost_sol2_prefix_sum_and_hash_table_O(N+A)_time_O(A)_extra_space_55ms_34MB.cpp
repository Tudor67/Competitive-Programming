class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> costOf;
        for(char c = 'a'; c <= 'z'; ++c){
            costOf[c] = c - 'a' + 1;
        }
        
        for(int i = 0; i < (int)chars.length(); ++i){
            costOf[chars[i]] = vals[i];
        }
        
        int res = 0;
        int minPrefixCost = 0;
        int prefixCost = 0;
        for(char c: s){
            prefixCost += costOf[c];
            res = max(res, prefixCost - minPrefixCost);
            minPrefixCost = min(minPrefixCost, prefixCost);
        }
        
        return res;
    }
};