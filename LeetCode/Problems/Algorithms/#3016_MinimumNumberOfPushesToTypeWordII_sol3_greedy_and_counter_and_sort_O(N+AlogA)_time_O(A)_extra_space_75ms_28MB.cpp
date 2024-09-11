class Solution {
public:
    int minimumPushes(string word) {
        const int N = word.length();
        const int A = 26;
        
        vector<int> f(A);
        for(char c: word){
            f[c - 'a'] += 1;
        }
        
        sort(f.rbegin(), f.rend());
        
        int totalCost = 0;
        for(int i = 0; i < A; ++i){
            int opCost = (i / 8) + 1;
            totalCost += f[i] * opCost;
        }
        
        return totalCost;
    }
};