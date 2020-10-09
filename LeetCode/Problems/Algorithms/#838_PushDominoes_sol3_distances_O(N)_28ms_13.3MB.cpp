class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        
        vector<int> rDist(N);
        char lastDir = '.';
        for(int i = 0; i < N; ++i){
            if(dominoes[i] == '.' && lastDir == 'R'){
                rDist[i] = 1 + rDist[i - 1];
            }
            if(dominoes[i] != '.'){
                lastDir = dominoes[i];
            }
        }
        
        vector<int> lDist(N);
        lastDir = '.';
        for(int i = N - 1; i >= 0; --i){
            if(dominoes[i] == '.' && lastDir == 'L'){
                lDist[i] = 1 + lDist[i + 1];
            }
            if(dominoes[i] != '.'){
                lastDir = dominoes[i];
            }
        }
        
        for(int i = 0; i < N; ++i){
            if(dominoes[i] == '.'){
                if(rDist[i] > 0 && (rDist[i] < lDist[i] || lDist[i] == 0)){
                    dominoes[i] = 'R';
                }else if(lDist[i] > 0 && (lDist[i] < rDist[i] || rDist[i] == 0)){
                    dominoes[i] = 'L';
                }
            }
        }
        
        return dominoes;
    }
};