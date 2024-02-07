class Solution {
public:
    int firstUniqChar(string s) {
        const int N = s.length();
        const int A = 26;
        
        vector<int> freq(A);
        for(int i = 0; i < N; ++i){
            freq[s[i] - 'a'] += 1;
        }

        for(int i = 0; i < N; ++i){
            if(freq[s[i] - 'a'] == 1){
                return i;
            }
        }

        return -1;
    }
};