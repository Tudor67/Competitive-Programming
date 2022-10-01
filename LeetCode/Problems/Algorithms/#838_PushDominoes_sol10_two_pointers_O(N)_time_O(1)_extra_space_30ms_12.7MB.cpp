class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.size();
        
        int i = 0;
        for(int j = 0; j < N; ++j){
            if(dominoes[j] != '.'){
                if(dominoes[i] == dominoes[j] || (dominoes[i] == '.' && dominoes[j] == 'L')){
                    fill(dominoes.begin() + i, dominoes.begin() + j, dominoes[j]);
                }else if(dominoes[i] == 'R' && dominoes[j] == 'L'){
                    int len = j - i - 1;
                    fill(dominoes.begin() + i, dominoes.begin() + i + 1 + len / 2, 'R');
                    fill(dominoes.begin() + i + 1 + (len + 1) / 2, dominoes.begin() + j, 'L');
                }
                i = j;
            }
        }
        
        if(dominoes[i] == 'R'){
            fill(dominoes.begin() + i + 1, dominoes.end(), 'R');
        }
        
        return dominoes;
    }
};