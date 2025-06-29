class Solution {
public:
    int minimumDeletions(string word, int k) {
        const int N = word.length();
        const int A = 26;

        vector<int> f(A);
        for(char c: word){
            f[c - 'a'] += 1;
        }

        sort(f.begin(), f.end());

        int minDeletions = N;
        int wSum = 0;
        int l = 0;
        int r = 0;
        for(int minFreq = f.front(); minFreq <= f.back(); ++minFreq){
            while(l < A && f[l] < minFreq){
                wSum -= f[l];
                l += 1;
            }
            while(r < A && minFreq + k >= f[r]){
                wSum += f[r];
                r += 1;
            }
            int keep = wSum + (A - r) * (minFreq + k);
            minDeletions = min(minDeletions, N - keep);
        }

        return minDeletions;
    }
};