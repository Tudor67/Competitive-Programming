class Solution {
public:
    int takeCharacters(string s, int k) {
        const int N = s.length();

        // Step 1: counter
        unordered_map<char, int> count;
        for(char c: s){
            count[c] += 1;
        }

        // Step 2: special case
        if(count['a'] < k || count['b'] < k || count['c'] < k){
            return -1;
        }

        // Step 3: remove max redundant substring
        int maxRemove = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            count[s[r]] -= 1;
            while(count[s[r]] < k){
                count[s[l]] += 1;
                l += 1;
            }
            maxRemove = max(maxRemove, r - l + 1);
        }

        return N - maxRemove;
    }
};