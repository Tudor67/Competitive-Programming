class Solution {
public:
    int minimumDeletions(string word, int k) {
        const int N = word.length();
        const int A = 26;

        vector<int> f(A);
        for(char c: word){
            f[c - 'a'] += 1;
        }

        const int MIN_FREQ = *min_element(f.begin(), f.end());
        const int MAX_FREQ = *max_element(f.begin(), f.end());
        
        int minDeletions = N;

        for(int minFreq = MIN_FREQ; minFreq <= MAX_FREQ; ++minFreq){
            int deletions = 0;
            for(int currFreq: f){
                if(currFreq < minFreq){
                    deletions += currFreq;
                }else if(minFreq + k < currFreq){
                    deletions += currFreq - (minFreq + k);
                }
            }
            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};