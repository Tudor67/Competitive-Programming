class Solution {
private:
    using Board = vector<vector<int>>;
    const int ROWS = 2;
    const int COLS = 3;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isInside(int row, int col){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

public:
    int slidingPuzzle(vector<vector<int>>& originalBoard) {
        int row0 = 0;
        int col0 = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(originalBoard[row][col] == 0){
                    row0 = row;
                    col0 = col;
                }
            }
        }

        Board targetBoard = {{1, 2, 3}, {4, 5, 0}};
        queue<tuple<Board, int, int>> q;
        set<Board> vis;
        q.push({originalBoard, row0, col0});
        vis.insert(originalBoard);
        int minMoves = 0;
        
        while(!q.empty()){
            if(vis.count(targetBoard)){
                return minMoves;
            }

            minMoves += 1;

            for(int i = q.size(); i >= 1; --i){
                Board currBoard = get<0>(q.front());
                int row = get<1>(q.front());
                int col = get<2>(q.front());
                q.pop();

                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(currBoard[row][col] == 0 && isInside(nextRow, nextCol)){
                        Board nextBoard = currBoard;
                        swap(nextBoard[row][col], nextBoard[nextRow][nextCol]);
                        if(!vis.count(nextBoard)){
                            q.push({nextBoard, nextRow, nextCol});
                            vis.insert(nextBoard);
                        }
                    }
                }
            }
        }

        return -1;
    }
};