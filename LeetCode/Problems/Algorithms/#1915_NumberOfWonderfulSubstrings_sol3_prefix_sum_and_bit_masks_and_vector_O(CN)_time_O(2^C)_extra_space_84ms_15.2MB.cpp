class Solution {
public:
    long long wonderfulSubstrings(string word) {
        const int N = word.length();
        const char MIN_CHAR = *min_element(word.begin(), word.end());
        const char MAX_CHAR = *max_element(word.begin(), word.end());
        
        vector<bool> vis(MAX_CHAR + 1, false);
        for(char c: word){
            vis[c] = true;
        }
        
        vector<int> idxOf(MAX_CHAR + 1);
        int idx = -1;
        for(char c = MIN_CHAR; c <= MAX_CHAR; ++c){
            if(vis[c]){
                idx += 1;
                idxOf[c] = idx;
            }
        }
        
        const int C = idx + 1;
        const int FULL_MASK = (1 << C) - 1;
        
        long long totalCount = 0;
        vector<long long> count(FULL_MASK + 1);
        int prefixMask = 0;
        count[0] = 1;
        for(char c: word){
            prefixMask ^= (1 << idxOf[c]);
            totalCount += count[prefixMask];
            for(int bit = 0; bit < C; ++bit){
                totalCount += count[prefixMask ^ (1 << bit)];
            }
            count[prefixMask] += 1;
        }
        
        return totalCount;
    }
};