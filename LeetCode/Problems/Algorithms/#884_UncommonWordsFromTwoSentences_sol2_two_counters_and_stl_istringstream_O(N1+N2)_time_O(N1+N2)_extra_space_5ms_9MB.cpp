class Solution {
private:
    using Counter = unordered_map<string, int>;

    void collectWords(string& s, Counter& freq){
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
        for(auto& [f1, f2]: vector<pair<Counter*, Counter*>>{{&freq1, &freq2}, {&freq2, &freq1}}){
            for(auto& [WORD, WORD_FREQ]: *f1){
                if(WORD_FREQ == 1 && !(*f2).count(WORD)){
                    res.push_back(WORD);
                }
            }
        }

        return res;
    }
};