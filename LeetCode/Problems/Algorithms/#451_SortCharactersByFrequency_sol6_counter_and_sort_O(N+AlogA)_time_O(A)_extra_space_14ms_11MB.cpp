class Solution {
public:
    string frequencySort(string s) {
        const int N = s.length();

        unordered_map<char, int> freq;
        for(char c: s){
            freq[c] += 1;
        }

        vector<pair<int, char>> freqChar;
        for(const pair<const char, int>& P: freq){
            freqChar.push_back({P.second, P.first});
        }

        sort(freqChar.rbegin(), freqChar.rend());

        string res;
        res.reserve(N);
        for(const pair<int, char>& P: freqChar){
            res.append(P.first, P.second);
        }

        return res;
    }
};