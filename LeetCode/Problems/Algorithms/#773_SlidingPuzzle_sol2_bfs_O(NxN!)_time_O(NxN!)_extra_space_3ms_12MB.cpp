class Solution {
private:
    const vector<vector<int>> NEIGHBORS = {{1, 3}, {0, 2, 4}, {1, 5},
                                           {0, 4}, {1, 3, 5}, {2, 4}};
    
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string initialState;
        for(int row = 0; row < (int)board.size(); ++row){
            for(int col = 0; col < (int)board[0].size(); ++col){
                initialState += char('0' + board[row][col]);
            }
        }

        queue<pair<string, int>> q;
        unordered_set<string> vis;
        q.push({initialState, initialState.find('0')});
        vis.insert(initialState);
        int minMoves = 0;

        while(!q.empty()){
            if(vis.count("123450")){
                return minMoves;
            }

            minMoves += 1;

            for(int i = q.size(); i >= 1; --i){
                string state = q.front().first;
                int pos0 = q.front().second;
                q.pop();

                for(int nextPos0: NEIGHBORS[pos0]){
                    string nextState = state;
                    swap(nextState[nextPos0], nextState[pos0]);

                    if(!vis.count(nextState)){
                        q.push({nextState, nextPos0});
                        vis.insert(nextState);
                    }
                }
            }
        }

        return -1;
    }
};