class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();

        if(count(dominoes.begin(), dominoes.end(), '.') == N){
            return dominoes;
        }

        vector<int> fallingIndices;
        for(int i = 0; i < N; ++i){
            if(dominoes[i] != '.'){
                fallingIndices.push_back(i);
            }
        }

        if(dominoes[fallingIndices.front()] == 'L'){
            fill(dominoes.begin(), dominoes.begin() + fallingIndices.front(), 'L');
        }
        
        if(dominoes[fallingIndices.back()] == 'R'){
            fill(dominoes.begin() + fallingIndices.back(), dominoes.end(), 'R');
        }

        for(int i = 0; i + 1 < (int)fallingIndices.size(); ++i){
            int l = fallingIndices[i];
            int r = fallingIndices[i + 1];
            int len = r - l - 1;

            if(dominoes[l] == dominoes[r]){
                fill(dominoes.begin() + l, dominoes.begin() + r, dominoes[r]);
            }else if(dominoes[l] == 'R' && dominoes[r] == 'L'){
                fill(dominoes.begin() + l, dominoes.begin() + l + len / 2 + 1, 'R');
                fill(dominoes.begin() + r - len / 2, dominoes.begin() + r, 'L');
            }
        }

        return dominoes;
    }
};