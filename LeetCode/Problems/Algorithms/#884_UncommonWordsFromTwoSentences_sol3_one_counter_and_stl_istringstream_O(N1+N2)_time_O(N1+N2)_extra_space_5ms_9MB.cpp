class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        istringstream iss(s1 + " " + s2);
        string word;
        while(iss >> word){
            freq[word] += 1;
        }

        vector<string> res;
        for(const pair<const string, int>& P: freq){
            const string& word = P.first;
            int wordFreq = P.second;
            if(wordFreq == 1){
                res.push_back(word);
            }
        }

        return res;
    }
};