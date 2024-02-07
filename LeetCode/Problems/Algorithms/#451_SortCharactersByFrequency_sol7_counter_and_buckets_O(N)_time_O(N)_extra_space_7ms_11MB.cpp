class Solution {
public:
    string frequencySort(string s) {
        const int N = s.length();

        unordered_map<char, int> charToFreq;
        for(char c: s){
            charToFreq[c] += 1;
        }

        unordered_map<int, vector<char>> freqToChars;
        for(const pair<const char, int>& P: charToFreq){
            char c = P.first;
            int charFreq = P.second;
            freqToChars[charFreq].push_back(c);
        }

        string res;
        res.reserve(N);
        for(int charFreq = N; charFreq >= 1; --charFreq){
            if(freqToChars.count(charFreq)){
                for(char c: freqToChars[charFreq]){
                    res.append(charFreq, c);
                }
            }
        }

        return res;
    }
};