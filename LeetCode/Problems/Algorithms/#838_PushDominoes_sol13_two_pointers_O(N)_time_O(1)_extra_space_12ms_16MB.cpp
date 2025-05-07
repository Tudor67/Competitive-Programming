class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();

        int l = 0;
        for(int r = 1; r < N; ++r){
            if(dominoes[r] == 'L'){
                if(dominoes[l] == 'R'){
                    int len = r - l - 1;
                    fill(dominoes.begin() + l, dominoes.begin() + l + len / 2 + 1, 'R');
                    fill(dominoes.begin() + r - len / 2, dominoes.begin() + r, 'L');
                }else{
                    fill(dominoes.begin() + l, dominoes.begin() + r, 'L');
                }
                l = r;
            }else if(dominoes[r] == 'R' || r == N - 1){
                if(dominoes[l] == 'R'){
                    fill(dominoes.begin() + l, dominoes.begin() + r + 1, 'R');
                }
                l = r;
            }
        }

        return dominoes;
    }
};