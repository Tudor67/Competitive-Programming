class Solution {
public:
    int minimumDeletions(string word, int k) {
        const int N = word.length();
        const int A = 26;
        
        vector<int> f(A);
        for(char c: word){
            f[c - 'a'] += 1;
        }

        int minCost = N;
        for(int maxVal = N; maxVal >= 0; --maxVal){
            int minVal = maxVal - k;
            int cost = 0;
            for(int charFreq: f){
                if(maxVal < charFreq){
                    cost += (charFreq - maxVal);
                }else if(charFreq < minVal){
                    cost += charFreq;
                }
            }
            minCost = min(minCost, cost);
        }
        
        return minCost;
    }
};