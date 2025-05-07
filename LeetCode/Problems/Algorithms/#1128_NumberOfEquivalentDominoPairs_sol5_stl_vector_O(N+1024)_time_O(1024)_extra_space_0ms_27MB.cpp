class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int goodPairs = 0;
        vector<int> freq(1 << 10);
        for(vector<int>& domino: dominoes){
            int code = (1 << domino[0]) | (1 << domino[1]);
            goodPairs += freq[code];
            freq[code] += 1;
        }
        return goodPairs;
    }
};