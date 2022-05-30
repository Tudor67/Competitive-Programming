class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        return count_if(words.begin(), words.end(),
                        [&](const string& WORD){
                            return (s.compare(0, WORD.length(), WORD) == 0);
                        });
    }
};