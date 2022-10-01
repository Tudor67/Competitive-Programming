class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.size();
        const int INF = 1e9;
        
        vector<int> dist(N, INF);
        queue<int> q;
        for(int pos = 0; pos < N; ++pos){
            if(dominoes[pos] != '.'){
                q.push(pos);
                dist[pos] = 0;
            }
        }
        
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            
            int nextPos = (dominoes[pos] == 'L' ? pos - 1 : pos + 1);
            if(0 <= nextPos && nextPos < N){
                if(dist[pos] + 1 < dist[nextPos]){
                    q.push(nextPos);
                    dist[nextPos] = dist[pos] + 1;
                    dominoes[nextPos] = dominoes[pos];
                }else if(dist[pos] + 1 == dist[nextPos]){
                    dominoes[nextPos] = '.';
                }
            }
        }
        
        return dominoes;
    }
};