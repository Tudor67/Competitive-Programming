class Solution {
public:
    int minDeletions(string s) {
        const int N = s.length();

        unordered_map<char, int> freqOf;
        for(char c: s){
            freqOf[c] += 1;
        }

        vector<int> sortedFreqs;
        for(const pair<char, int>& P: freqOf){
            int charFreq = P.second;
            sortedFreqs.push_back(charFreq);
        }

        sort(sortedFreqs.begin(), sortedFreqs.end());

        int totalOps = 0;
        for(int i = (int)sortedFreqs.size() - 2; i >= 0; --i){
            if(sortedFreqs[i] >= sortedFreqs[i + 1]){
                int ops = sortedFreqs[i] - max(0, sortedFreqs[i + 1] - 1);
                sortedFreqs[i] -= ops;
                totalOps += ops;
            }
        }

        return totalOps;
    }
};