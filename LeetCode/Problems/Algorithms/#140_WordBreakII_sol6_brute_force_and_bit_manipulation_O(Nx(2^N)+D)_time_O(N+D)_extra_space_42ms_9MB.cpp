class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;

        vector<string> res;
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());

        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if(!((mask >> (N - 1)) & 1)){
                continue;
            }
            string sentence;
            string word;
            for(int bit = 0; bit < N; ++bit){
                word += s[bit];
                if((mask >> bit) & 1){
                    if(wordDictSet.count(word)){
                        sentence += word;
                        sentence += " ";
                        word.clear();
                    }else{
                        sentence.clear();
                        break;
                    }
                }
            }

            if(!sentence.empty()){
                sentence.pop_back();
                res.push_back(sentence);
            }
        }

        return res;
    }
};