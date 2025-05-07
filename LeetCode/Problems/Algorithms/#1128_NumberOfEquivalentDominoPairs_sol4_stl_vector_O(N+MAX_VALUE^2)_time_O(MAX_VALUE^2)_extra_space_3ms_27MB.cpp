class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        const int N = dominoes.size();
        
        int maxVal = 0;
        for(vector<int>& domino: dominoes){
            maxVal = max(maxVal, max(domino[0], domino[1]));
        }

        int goodPairs = 0;
        vector<int> freq(maxVal * (maxVal + 1) + maxVal + 1);

        for(vector<int>& domino: dominoes){
            int a = domino[0];
            int b = domino[1];

            if(a > b){
                swap(a, b);
            }

            int code = a * (maxVal + 1) + b;

            goodPairs += freq[code];

            freq[code] += 1;
        }

        return goodPairs;
    }
};