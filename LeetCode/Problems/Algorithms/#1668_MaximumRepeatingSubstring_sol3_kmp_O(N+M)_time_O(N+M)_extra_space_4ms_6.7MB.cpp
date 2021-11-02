class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string S = sequence;
        string P = word;
        while(P.length() < S.length()){
            P += word;
        }
        
        const string PS = P + "$" + S;
        const int L = PS.length();
        
        vector<int> p(L, 0);
        for(int i = 1; i < L; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                p[i] = k + 1;
            }
        }
        
        int maxK = 0;
        for(int i = (int)P.length() + 1; i < L; ++i){
            maxK = max(maxK, p[i] / (int)word.length());
        }
        
        return maxK;
    }
};