class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        const int INF = 1e8;
        
        queue<int> q;
        vector<int> d(N, INF);
        for(int i = 0; i < N; ++i){
            if(dominoes[i] != '.'){
                d[i] = 0;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            
            int nextPos = pos - 1;
            if(dominoes[pos] == 'R'){
                nextPos = pos + 1;
            }
            
            if(0 <= nextPos && nextPos < N){
                if(d[pos] + 1 < d[nextPos]){
                    d[nextPos] = d[pos] + 1;
                    q.push(nextPos);
                    dominoes[nextPos] = dominoes[pos];
                }else if(d[pos] + 1 == d[nextPos]){
                    dominoes[nextPos] = '.';
                }
            }
        }
        
        return dominoes;
    }
};