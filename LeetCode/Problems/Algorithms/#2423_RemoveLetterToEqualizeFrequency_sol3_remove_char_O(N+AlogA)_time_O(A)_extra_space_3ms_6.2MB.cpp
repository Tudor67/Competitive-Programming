class Solution {
public:
    bool equalFrequency(string word) {
        const int N = word.length();
        
        unordered_map<char, int> freqOf;
        for(char c: word){
            freqOf[c] += 1;
        }
        
        vector<int> freqs;
        for(const pair<char, int>& P: freqOf){
            int currentFreq = P.second;
            freqs.push_back(currentFreq);
        }
        
        const int F = freqs.size();
        sort(freqs.begin(), freqs.end());
        
        if(F == 1 && (freqs[0] == 1 || (int)freqOf.size() == 1)){
            return true;
        }
        if(F >= 2 && ((freqs[0] == 1 && freqs[1] == freqs[F - 1]) ||
                      (freqs[F - 2] == freqs[F - 1] - 1 && freqs[0] == freqs[F - 2]))){
            return true;
        }
        return false;
    }
};