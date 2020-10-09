class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        
        vector<int> rDist(N, INT_MAX);
        char lastDir = '.';
        for(int i = 0; i < N; ++i){
            if(dominoes[i] == '.' && lastDir == 'R'){
                rDist[i] = 1 + rDist[i - 1];
            }
            if(dominoes[i] != '.'){
                lastDir = dominoes[i];
                rDist[i] = (dominoes[i] == 'R' ? 0 : INT_MAX);
            }
        }
        
        vector<int> lDist(N, INT_MAX);
        lastDir = '.';
        for(int i = N - 1; i >= 0; --i){
            if(dominoes[i] == '.' && lastDir == 'L'){
                lDist[i] = 1 + lDist[i + 1];
            }
            if(dominoes[i] != '.'){
                lastDir = dominoes[i];
                lDist[i] = (dominoes[i] == 'L' ? 0 : INT_MAX);
            }
        }
        
        for(int i = 0; i < N; ++i){
            if(dominoes[i] == '.'){
                if(rDist[i] < lDist[i]){
                    dominoes[i] = 'R';
                }else if(lDist[i] < rDist[i]){
                    dominoes[i] = 'L';
                }
            }
        }
        
        return dominoes;
    }
};