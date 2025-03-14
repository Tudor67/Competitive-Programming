class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();

        int validSubstrings = 0;
        unordered_map<char, int> freq;

        int l = 0;
        for(int r = 0; r < N; ++r){
            freq[s[r]] += 1;
            
            while(freq[s[l]] >= 2){
                freq[s[l]] -= 1;
                l += 1;
            }

            if((int)freq.size() == 3){
                validSubstrings += (l + 1);
            }
        }

        return validSubstrings;
    }
};