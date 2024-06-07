class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        const int N = words.size();
        const int INF = 1e9;
        const int A = 26;

        vector<int> minFreq(A, INF);
        vector<int> currFreq(A);

        for(const string& WORD: words){
            fill(currFreq.begin(), currFreq.end(), 0);
            for(char c: WORD){
                currFreq[c - 'a'] += 1;
            }
            for(char c = 'a'; c <= 'z'; ++c){
                minFreq[c - 'a'] = min(minFreq[c - 'a'], currFreq[c - 'a']);
            }
        }

        vector<string> res;
        for(char c = 'a'; c <= 'z'; ++c){
            res.resize(res.size() + minFreq[c - 'a'], string(1, c));
        }

        return res;
    }
};