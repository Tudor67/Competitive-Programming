class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        for(int i = 0; i < N; ++i){
            if(dominoes[i] == 'L'){
                int prevPos = -1;
                for(int j = i - 1; j >= 0; --j){
                    if(dominoes[j] == '.'){
                        dominoes[j] = 'L';
                    }else{
                        prevPos = j;
                        break;
                    }
                }
                if(prevPos >= 0 && dominoes[prevPos] == 'R'){
                    int cnt = (i - prevPos - 1);
                    for(int j = prevPos + 1; j <= prevPos + cnt / 2; ++j){
                        dominoes[j] = 'R';
                    }
                    if(cnt % 2 == 1){
                        dominoes[prevPos + cnt / 2 + 1] = '.';
                    }
                }
            }else if(dominoes[i] == 'R'){
                int nextPos = N;
                for(int j = i + 1; j < N; ++j){
                    if(dominoes[j] == '.'){
                        dominoes[j] = 'R';
                    }else{
                        nextPos = j;
                        break;
                    }
                }
                if(nextPos < N && dominoes[nextPos] == 'L'){
                    int cnt = (nextPos - i - 1);
                    for(int j = i + cnt / 2 + 1; j <= nextPos - 1; ++j){
                        dominoes[j] = 'L';
                    }
                    if(cnt % 2 == 1){
                        dominoes[i + cnt / 2 + 1] = '.';
                    }
                }
            }
        }
        return dominoes;
    }
};