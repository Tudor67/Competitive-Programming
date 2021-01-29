class Solution {
private:
    vector<int> getFrequencyValues(const string& S){
        vector<int> freqOf(26, 0);
        for(char c: S){
            freqOf[c - 'a'] += 1;
        }
        vector<int> freq;
        for(int elem = 0; elem < freqOf.size(); ++elem){
            if(freqOf[elem] > 0){
                freq.push_back(freqOf[elem]);
            }
        }
        return freq;
    }
    
public:
    bool closeStrings(string word1, string word2) {
        vector<int> frequencies1 = getFrequencyValues(word1);
        vector<int> frequencies2 = getFrequencyValues(word2);
        sort(frequencies1.begin(), frequencies1.end());
        sort(frequencies2.begin(), frequencies2.end());
        bool sameFrequencyValues = (frequencies1 == frequencies2);
        bool sameElements = (set<char>(word1.begin(), word1.end()) == set<char>(word2.begin(), word2.end()));
        return (sameElements && sameFrequencyValues);
    }
};