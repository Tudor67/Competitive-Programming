class Solution {
private:
    void concatenate(vector<string>& words, string& res){
        res.clear();
        for(string& word: words){
            res += word;
        }
    }
    
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        string s2;
        
        concatenate(word1, s1);
        concatenate(word2, s2);
        
        return (s1 == s2);
    }
};