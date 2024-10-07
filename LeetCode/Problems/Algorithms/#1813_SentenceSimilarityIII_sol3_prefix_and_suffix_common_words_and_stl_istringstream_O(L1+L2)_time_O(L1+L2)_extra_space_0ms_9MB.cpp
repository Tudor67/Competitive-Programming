class Solution {
private:
    vector<string> extractWords(const string& SENTENCE){
        vector<string> words;
        istringstream iss(SENTENCE);
        string word;
        while(iss >> word){
            words.push_back(word);
        }
        return words;
    }
    
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = extractWords(sentence1);
        vector<string> words2 = extractWords(sentence2);
        if(words1.size() > words2.size()){
            swap(words1, words2);
        }

        const int N1 = words1.size();
        const int N2 = words2.size();

        int maxPrefixMatch = 0;
        while(maxPrefixMatch < N1 && words1[maxPrefixMatch] == words2[maxPrefixMatch]){
            maxPrefixMatch += 1;
        }

        int maxSuffixMatch = 0;
        while(maxSuffixMatch < N1 && words1[N1 - 1 - maxSuffixMatch] == words2[N2 - 1 - maxSuffixMatch]){
            maxSuffixMatch += 1;
        }

        return (maxPrefixMatch + maxSuffixMatch >= N1);
    }
};