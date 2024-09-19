class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        const int N = words.size();
        const int A = 26;
        
        vector<int> freq(A);
        vector<int> lengths;
        for(string& word: words){
            for(char c: word){
                freq[c - 'a'] += 1;
            }
            lengths.push_back(word.length());
        }
        
        sort(lengths.begin(), lengths.end());
        
        int pairs = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            pairs += (freq[c - 'a'] / 2);
        }

        int res = 0;
        for(int len: lengths){
            pairs -= len / 2;
            if(pairs >= 0){
                res += 1;
            }
        }

        return res;
    }
};