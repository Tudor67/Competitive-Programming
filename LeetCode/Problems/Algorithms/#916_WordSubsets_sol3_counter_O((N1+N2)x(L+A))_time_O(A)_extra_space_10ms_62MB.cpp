class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        const int N1 = words1.size();
        const int N2 = words2.size();
        const int A = 26;

        vector<int> maxFreq(A);
        vector<int> currFreq(A);
        for(string& word: words2){
            fill(currFreq.begin(), currFreq.end(), 0);
            for(char c: word){
                currFreq[c - 'a'] += 1;
            }
            for(char c = 'a'; c <= 'z'; ++c){
                maxFreq[c - 'a'] = max(maxFreq[c - 'a'], currFreq[c - 'a']);
            }
        }

        vector<string> res;
        for(string& word: words1){
            fill(currFreq.begin(), currFreq.end(), 0);
            for(char c: word){
                currFreq[c - 'a'] += 1;
            }
            bool isUniversal = true;
            for(char c = 'a'; c <= 'z'; ++c){
                if(currFreq[c - 'a'] < maxFreq[c - 'a']){
                    isUniversal = false;
                }
            }
            if(isUniversal){
                res.push_back(word);
            }
        }

        return res;
    }
};