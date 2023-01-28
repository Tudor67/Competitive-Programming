class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int N = board.size();
        const int INF = 1e9;

        int currentNode = 1;
        vector<int> rowOf(N * N + 1);
        vector<int> colOf(N * N + 1);
        for(int row = N - 1; row >= 0; --row){
            if(row % 2 == (N - 1) % 2){
                for(int col = 0; col < N; ++col){
                    rowOf[currentNode] = row;
                    colOf[currentNode] = col;
                    currentNode += 1;
                }
            }else{
                for(int col = N - 1; col >= 0; --col){
                    rowOf[currentNode] = row;
                    colOf[currentNode] = col;
                    currentNode += 1;
                }
            }
        }

        vector<int> minMoves(N * N + 1, INF);
        queue<int> q;
        minMoves[1] = 0;
        q.push(1);

        while(!q.empty() && minMoves[N * N] == INF){
            int node = q.front();
            q.pop();

            for(int nextNode = node + 1; nextNode <= min(node + 6, N * N); ++nextNode){
                int nextRow = rowOf[nextNode];
                int nextCol = colOf[nextNode];

                if(board[nextRow][nextCol] == -1){
                    if(minMoves[nextNode] == INF){
                        minMoves[nextNode] = minMoves[node] + 1;
                        q.push(nextNode);
                    }
                }else{
                    int nextNextNode = board[nextRow][nextCol];
                    if(minMoves[nextNextNode] == INF){
                        minMoves[nextNextNode] = minMoves[node] + 1;
                        q.push(nextNextNode);
                    }
                }
            }
        }

        int res = minMoves[N * N];
        if(res == INF){
            res = -1;
        }
        
        return res;
    }
};