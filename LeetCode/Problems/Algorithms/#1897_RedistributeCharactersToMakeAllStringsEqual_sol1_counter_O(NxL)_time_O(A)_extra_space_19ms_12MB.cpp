class Solution {
public:
    bool makeEqual(vector<string>& words) {
        const int N = words.size();
        const int A = 26;

        vector<int> freq(A);
        for(const string& WORD: words){
            for(char c: WORD){
                freq[c - 'a'] += 1;
            }
        }
        
        for(char c = 'a'; c <= 'z'; ++c){
            if(freq[c - 'a'] % N != 0){
                return false;
            }
        }

        return true;
    }
};