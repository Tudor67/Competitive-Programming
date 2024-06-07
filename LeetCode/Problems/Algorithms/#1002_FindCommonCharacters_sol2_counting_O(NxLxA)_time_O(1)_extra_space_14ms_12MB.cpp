class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        const int N = words.size();
        const int INF = 1e9;
        const int A = 26;

        vector<string> res;
        for(char targetChar = 'a'; targetChar <= 'z'; ++targetChar){
            int minFreq = INF;
            for(const string& WORD: words){
                minFreq = min(minFreq, (int)count(WORD.begin(), WORD.end(), targetChar));
            }
            if(minFreq != INF){
                res.resize(res.size() + minFreq, string(1, targetChar));
            }
        }

        return res;
    }
};