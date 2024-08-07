class Solution {
public:
    int minimumPushes(string word) {
        const int N = word.length();

        unordered_map<char, int> freq;
        for(char c: word){
            freq[c] += 1;
        }

        vector<pair<int, char>> fc;
        for(const pair<const char, int>& P: freq){
            char c = P.first;
            int f = P.second;
            fc.push_back({f, c});
        }

        sort(fc.rbegin(), fc.rend());

        int totalCost = 0;
        for(int i = 0; i < (int)fc.size(); ++i){
            int pushesPerChar = 1 + (i / 8);
            int charFreq = fc[i].first;
            int charCost = pushesPerChar * charFreq;
            totalCost += charCost;
        }

        return totalCost;
    }
};