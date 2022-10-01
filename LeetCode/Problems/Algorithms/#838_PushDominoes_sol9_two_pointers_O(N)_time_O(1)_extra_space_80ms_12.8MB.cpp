class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.size();
        
        int prevPos = -1;
        for(int pos = 0; pos < N; ++pos){
            if(dominoes[pos] != '.'){
                if(dominoes[pos] == 'L'){
                    if(prevPos >= 0 && dominoes[prevPos] == 'R'){
                        int len = pos - prevPos - 1;
                        fill(dominoes.begin() + prevPos + 1, dominoes.begin() + prevPos + 1 + len / 2, 'R');
                        fill(dominoes.begin() + prevPos + 1 + (len + 1) / 2, dominoes.begin() + pos, 'L');
                    }else{
                        fill(dominoes.begin() + prevPos + 1, dominoes.begin() + pos, 'L');
                    }
                }
                if(dominoes[pos] == 'R'){
                    if(prevPos >= 0 && dominoes[prevPos] == 'R'){
                        fill(dominoes.begin() + prevPos + 1, dominoes.begin() + pos, 'R');
                    }
                }
                prevPos = pos;
            }
        }
        
        if(prevPos >= 0 && dominoes[prevPos] == 'R'){
            fill(dominoes.begin() + prevPos + 1, dominoes.end(), 'R');
        }
        
        return dominoes;
    }
};