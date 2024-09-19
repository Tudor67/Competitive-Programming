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
        
        int oddFreqs = 0;
        int evenFreqs = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            oddFreqs += (freq[c - 'a'] % 2);
            evenFreqs += (freq[c - 'a'] / 2) * 2;
        }

        int res = 0;
        for(int len: lengths){
            if(len % 2 == 0){
                if(len <= evenFreqs){
                    evenFreqs -= len;
                    res += 1;
                }
            }else{
                if(oddFreqs == 0){
                    evenFreqs -= 2;
                    oddFreqs += 2;
                }
                if(len - 1 <= evenFreqs){
                    oddFreqs -= 1;
                    evenFreqs -= (len - 1);
                    res += 1;
                }
            }
        }

        return res;
    }
};