class Solution {
private:
    void collectWords(string& s, unordered_map<string, int>& freq){
        istringstream iss(s);
        string word;
        while(iss >> word){
            freq[word] += 1;
        }
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq1;
        unordered_map<string, int> freq2;

        collectWords(s1, freq1);
        collectWords(s2, freq2);

        vector<string> res;
        for(const pair<const string, int>& P: freq1){
            const string& WORD = P.first;
            const int WORD_FREQ = P.second;
            if(WORD_FREQ == 1 && !freq2.count(WORD)){
                res.push_back(WORD);
            }
        }

        for(const pair<const string, int>& P: freq2){
            const string& WORD = P.first;
            const int WORD_FREQ = P.second;
            if(WORD_FREQ == 1 && !freq1.count(WORD)){
                res.push_back(WORD);
            }
        }

        return res;
    }
};