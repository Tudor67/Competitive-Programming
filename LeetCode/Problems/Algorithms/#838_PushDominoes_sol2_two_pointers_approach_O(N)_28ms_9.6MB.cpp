class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        for(int i = 0, j = 1; j < N; ++j){
            if(dominoes[j] == 'L'){
                if(dominoes[i] == 'R'){
                    int cnt = (j - i - 1);
                    fill(dominoes.begin() + i, dominoes.begin() + i + cnt / 2 + 1, 'R');
                    fill(dominoes.begin() + i + cnt / 2 + 1 + (cnt % 2), dominoes.begin() + j, 'L');
                }else{
                    fill(dominoes.begin() + i, dominoes.begin() + j, 'L');
                }
                i = j;
            }else if(dominoes[j] == 'R' || j == N - 1){
                if(dominoes[i] == 'R'){
                    fill(dominoes.begin() + i + 1, dominoes.begin() + j + 1, 'R');
                }
                i = j;
            }
        }
        return dominoes;
    }
};