class Solution {
private:
    bool isSubsequence(const string& WORD, vector<vector<int>>& posOf){
        const int L = WORD.length();
        int currentPos = 0;
        for(char c: WORD){
            vector<int>& v = posOf[c - 'a'];
            auto it = lower_bound(v.begin(), v.end(), currentPos);
            if(it == v.end()){
                return false;
            }else{
                currentPos = *it + 1;
            }
        }
        return true;
    }
    
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        const int N = s.length();
        const int M = words.size();
        
        vector<vector<int>> posOf(26);
        for(int i = 0; i < N; ++i){
            posOf[s[i] - 'a'].push_back(i);
        }
        
        int subsequenceCount = 0;
        for(const string& WORD: words){
            subsequenceCount += isSubsequence(WORD, posOf);
        }
        
        return subsequenceCount;
    }
};