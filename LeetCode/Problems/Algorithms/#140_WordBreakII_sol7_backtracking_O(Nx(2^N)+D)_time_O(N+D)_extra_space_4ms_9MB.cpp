class Solution {
private:
    void back(int startIndex, vector<int>& st, string& s, unordered_set<string>& wordDictSet,
              vector<string>& res){
        if(startIndex == (int)s.length()){
            string sentence;
            for(int i = 1; i < (int)st.size(); ++i){
                sentence.append(s, st[i - 1] + 1, st[i] - st[i - 1]);
                sentence.append(" ");
            }
            sentence.pop_back();
            res.push_back(sentence);
        }else{
            string currWord;
            for(int i = startIndex; i < (int)s.length(); ++i){
                currWord += s[i];
                if(wordDictSet.count(currWord)){
                    st.push_back(i);
                    back(i + 1, st, s, wordDictSet, res);
                    st.pop_back();
                }
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        const int N = s.length();

        vector<int> st = {-1};
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<string> res;
        
        back(0, st, s, wordDictSet, res);

        return res;
    }
};