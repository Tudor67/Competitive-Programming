class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        const int N = dominoes.size();

        int goodPairs = 0;
        map<pair<int, int>, int> freq;

        for(vector<int>& domino: dominoes){
            int a = domino[0];
            int b = domino[1];

            if(a > b){
                swap(a, b);
            }

            goodPairs += freq[{a, b}];

            freq[{a, b}] += 1;
        }

        return goodPairs;
    }
};