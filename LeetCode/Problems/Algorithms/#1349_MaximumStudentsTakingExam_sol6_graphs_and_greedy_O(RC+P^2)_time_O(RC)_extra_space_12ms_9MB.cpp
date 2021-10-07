class Solution {
private:
    int getNodeIdx(int row, int col, const int& COLS){
        return row * COLS + col;
    }
    
    int computeMaxValidNodes(const int& START_IDX, vector<int>& nodesForPersons, vector<vector<int>>& g){
        const int P = nodesForPersons.size();
        unordered_set<int> taken;
        for(int idx = START_IDX; idx < START_IDX + P; ++idx){
            int node = nodesForPersons[idx % P];
            if(!taken.count(node)){
                bool isValid = true;
                for(int nextNode: g[node]){
                    if(taken.count(nextNode)){
                        isValid = false;
                    }
                }
                if(isValid){
                    taken.insert(node);
                }
            }
        }
        return taken.size();
    }
    
public:
    int maxStudents(vector<vector<char>>& seats) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {0, -1}, {0, 1}, {-1, 1}};
        const int ROWS = seats.size();
        const int COLS = seats[0].size();
        
        const int N = ROWS * COLS;
        vector<vector<int>> g(N);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(seats[row][col] == '.'){
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int nextRow = row + DIRECTION.first;
                        int nextCol = col + DIRECTION.second;
                        if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && seats[nextRow][nextCol] == '.'){
                            int node = getNodeIdx(row, col, COLS);
                            int nextNode = getNodeIdx(nextRow, nextCol, COLS);
                            g[node].push_back(nextNode);
                            g[nextNode].push_back(node);
                        }
                    }
                }
            }
        }
        
        vector<int> nodesForPersons;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(seats[row][col] == '.'){
                    nodesForPersons.push_back(getNodeIdx(row, col, COLS));
                }
            }
        }
        
        int maxPersons = 0;
        for(int startIdx = 0; startIdx < (int)nodesForPersons.size(); ++startIdx){
            int persons = computeMaxValidNodes(startIdx, nodesForPersons, g);
            maxPersons = max(maxPersons, persons);
        }
        
        return maxPersons;
    }
};

/*
   Solution: Graphs & Greedy
            (inspired from https://leetcode.com/problems/maximum-students-taking-exam/discuss/833729/Python-Greedy-Graph-3-Steps)
   This looks like a graph coloring problem;
   
   Time Complexity: O(ROWS * COLS + P ^ 2), where P is the number of empty seats (i.e., seats[row][col] == '.')
   Space Complexity: O(ROWS * COLS), space required by the graph g (each node can have at most 4 neighbors)
   
   --- Graph ---
   1.) The seats matrix can be represented with a graph;
       seats[row][col] is the node with the index equal to row * COLS + col;
       cell       => node
       (row, col) => (row * COLS + col);
       
   2.) We are interested only in empty seats;
       we add an edge between 2 nodes only if they are `neighbors` (i.e., sitting next to the left, right, upper left or upper right)
       and both represent empty seats;
       
   3.) At this point we have a graph g on empty seats;
   
   --- Greedy ---
   4.) Starting from a fixed node / empty seat and moving from left to right,
       try to put a person in each node / empty seat only if there is no other person in `neighborhood`;
       save the number of persons which took an empty seat without conflicts;
       
   5.) Run 4.) for all possible starting nodes and update the answer;
   
   6.) Why does this greedy approach works?
       Well, the general idea is that running step 4.) P times with all possible starting nodes is equivalent to:
         - first fill the first empty seat and later try to fill the remaining seats (i.e., 1,2,3,4, ..., P)
         - first fill the second empty seat and later try to fill the remaining seats (i.e., 2,3,4,5, ..., 1);
         - first fill the third empty seat and later try to fill the remaining seats (i.e., 3,4,5, ..., 1, 2);
           ...
         - first fill the Pth empty seat and later try to fill the remainig seats (i.e., P, 1, 2, 3, ..., P - 1);
       Starting from all possible empty seats, we greedily compute the maximum number of persons that can take an empty seat
       without conflicts;
*/

/*
[[".","#","#","."],[".",".",".","."]]
[["#","#","#",".","#"],[".",".","#",".","."],["#",".","#",".","#"],[".",".",".",".","."],[".",".",".","#","."]]
[[".",".","."]]
[["#",".",".",".","#"],[".","#",".",".","#"],[".","#","#",".","."],[".",".","#","#","#"]]
[["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]
[[".","#"],["#","#"],["#","."],["#","#"],[".","#"]]
[["#",".",".",".","#"],[".","#",".","#","."],[".",".","#",".","."],[".","#",".","#","."],["#",".",".",".","#"]]
[[".",".","#",".","."],[".",".",".",".","#"],[".","#","#","#","."],[".","#","#","#","."]]
[[".",".",".",".","#",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".","#","."],[".",".",".",".",".",".",".","."],[".",".","#",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","#",".",".","#","."]]
*/