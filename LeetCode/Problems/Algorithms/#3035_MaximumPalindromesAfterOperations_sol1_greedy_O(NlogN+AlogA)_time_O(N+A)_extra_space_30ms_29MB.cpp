class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        const int N = words.size();
        const int A = 26;
        
        vector<int> freq(A);
        vector<int> lengths;
        int oddLengths = 0;
        for(string& word: words){
            for(char c: word){
                freq[c - 'a'] += 1;
            }
            lengths.push_back(word.length());
            oddLengths += (word.length() % 2);
        }
        
        sort(lengths.begin(), lengths.end());
        
        int oddFreqs = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            oddFreqs += (freq[c - 'a'] % 2);
        }
        
        int res = N;
        while(oddLengths < oddFreqs){
            res -= 1;
            oddLengths -= (lengths.back() % 2);
            oddFreqs -= lengths.back();
            lengths.pop_back();
        }

        return res;
    }
};