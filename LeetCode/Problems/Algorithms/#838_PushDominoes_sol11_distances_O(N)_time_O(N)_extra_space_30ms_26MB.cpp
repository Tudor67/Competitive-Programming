class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        const int INF = 1e9;

        vector<int> lDist(N, INF);
        for(int i = N - 1; i >= 0; --i){
            if(dominoes[i] == 'L'){
                lDist[i] = 0;
            }else if(dominoes[i] == 'R'){
                lDist[i] = INF;
            }else if(i + 1 < N){
                lDist[i] = min(INF, 1 + lDist[i + 1]);
            }
        }

        vector<int> rDist(N, INF);
        for(int i = 0; i < N; ++i){
            if(dominoes[i] == 'L'){
                rDist[i] = INF;
            }else if(dominoes[i] == 'R'){
                rDist[i] = 0;
            }else if(i - 1 >= 0){
                rDist[i] = min(INF, 1 + rDist[i - 1]);
            }
        }

        string res(N, '.');
        for(int i = 0; i < N; ++i){
            if(lDist[i] < rDist[i]){
                res[i] = 'L';
            }else if(lDist[i] > rDist[i]){
                res[i] = 'R';
            }
        }

        return res;
    }
};