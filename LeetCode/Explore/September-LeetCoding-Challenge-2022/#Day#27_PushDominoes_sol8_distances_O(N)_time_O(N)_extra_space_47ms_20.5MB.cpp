class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.size();
        const int INF = 1e9;
        
        // Step 1: move from left to right
        //         compute the min distance from the current domino ('.') to previous domino ('R')
        int prevPos = INF;
        vector<int> minDistToR(N, INF);
        for(int pos = 0; pos < N; ++pos){
            if(dominoes[pos] == '.'){
                if(prevPos != INF && dominoes[prevPos] == 'R'){
                    minDistToR[pos] = pos - prevPos;
                }
            }else{
                prevPos = pos;
            }
        }
        
        // Step 2: move from right to left
        //         compute the min distance from the current domino ('.') to previous domino ('L')
        prevPos = INF;
        vector<int> minDistToL(N, INF);
        for(int pos = N - 1; pos >= 0; --pos){
            if(dominoes[pos] == '.'){
                if(prevPos != INF && dominoes[prevPos] == 'L'){
                    minDistToL[pos] = prevPos - pos;
                }
            }else{
                prevPos = pos;
            }
        }
        
        // Step 3: compute the final state of dominoes
        //         if (minDistanceToL < minDistanceToR) then domino ('.') => domino ('L')
        //         if (minDistanceToR < minDistanceToL) then domino ('.') => domino ('R')
        for(int pos = 0; pos < N; ++pos){
            if(dominoes[pos] == '.'){
                if(minDistToL[pos] < minDistToR[pos]){
                    dominoes[pos] = 'L';
                }else if(minDistToR[pos] < minDistToL[pos]){
                    dominoes[pos] = 'R';
                }
            }
        }
        
        return dominoes;
    }
};