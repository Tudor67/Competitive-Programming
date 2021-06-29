class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        const int N = s.length();
        const int M = words.size();
        
        vector<vector<pair<int, int>>> buckets(26);
        for(int i = 0; i < M; ++i){
            buckets[words[i][0] - 'a'].emplace_back(i, 0);
        }
        
        int subsequencesCount = 0;
        for(char c: s){
            vector<pair<int, int>> currentBucket = buckets[c - 'a'];
            buckets[c - 'a'].clear();
            for(const pair<int, int>& P: currentBucket){
                int wordIdx = P.first;
                int charIdx = P.second;
                if((int)words[wordIdx].length() == charIdx + 1){
                    subsequencesCount += 1;
                }else{
                    buckets[words[wordIdx][charIdx + 1] - 'a'].emplace_back(wordIdx, charIdx + 1);
                }
            }
        }
        
        return subsequencesCount;
    }
};