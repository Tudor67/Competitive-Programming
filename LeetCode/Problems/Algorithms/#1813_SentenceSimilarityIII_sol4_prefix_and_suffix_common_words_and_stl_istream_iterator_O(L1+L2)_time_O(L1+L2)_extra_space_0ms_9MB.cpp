class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream iss1(sentence1);
        istringstream iss2(sentence2);
        vector<string> words1(istream_iterator<string>{iss1}, istream_iterator<string>());
        vector<string> words2(istream_iterator<string>{iss2}, istream_iterator<string>());
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