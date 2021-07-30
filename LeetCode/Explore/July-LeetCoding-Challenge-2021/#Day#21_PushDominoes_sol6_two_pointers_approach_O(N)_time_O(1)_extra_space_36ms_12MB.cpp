class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        const int DOTS = count(dominoes.begin(), dominoes.end(), '.');
        if(DOTS == 0 || DOTS == N){
            // Special case: Dots == 0 || Dots == N => final state == initial state
        }else{
            int l = 0;
            while(l < N && dominoes[l] == '.'){
                l += 1;
            }
            if(dominoes[l] == 'L'){
                fill(dominoes.begin(), dominoes.begin() + l, 'L');
            }
            
            int r = N - 1;
            while(l < r && dominoes[r] == '.'){
                r -= 1;
            }
            if(dominoes[r] == 'R'){
                fill(dominoes.begin() + r, dominoes.end(), 'R');
            }
            
            for(int prevPos = l, pos = l + 1; pos <= r; ++pos){
                if(dominoes[pos] != '.'){
                    if(dominoes[prevPos] == 'R' && dominoes[pos] == 'L'){
                        fill(dominoes.begin() + prevPos, dominoes.begin() + (prevPos + pos + 1) / 2, 'R');
                        fill(dominoes.begin() + (prevPos + pos + 2) / 2, dominoes.begin() + pos, 'L');
                    }
                    if(dominoes[prevPos] == 'L' && dominoes[pos] == 'L'){
                        fill(dominoes.begin() + prevPos, dominoes.begin() + pos, 'L');
                    }
                    if(dominoes[prevPos] == 'R' && dominoes[pos] == 'R'){
                        fill(dominoes.begin() + prevPos, dominoes.begin() + pos, 'R');
                    }
                    prevPos = pos;
                }
            }
        }
        return dominoes;
    }
};