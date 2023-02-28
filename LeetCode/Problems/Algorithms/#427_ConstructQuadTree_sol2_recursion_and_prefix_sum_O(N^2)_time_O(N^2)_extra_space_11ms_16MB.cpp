/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool sameValues(int row1, int col1, int row2, int col2, vector<vector<int>>& prefSum){
        int sum = prefSum[row2][col2] - prefSum[row2][col1 - 1] - prefSum[row1 - 1][col2] + prefSum[row1 - 1][col1 - 1];
        return (sum == 0) || (sum == (row2 - row1 + 1) * (col2 - col1 + 1));
    }

    Node* construct(vector<vector<int>>& grid, int row1, int col1, int row2, int col2, vector<vector<int>>& prefSum){
        if(sameValues(row1 + 1, col1 + 1, row2 + 1, col2 + 1, prefSum)){
            return new Node((bool)grid[row1][col1], true);
        }

        Node* root = new Node((bool)grid[row1][col1], false);
        int rowMid = (row1 + row2 + 1) / 2;
        int colMid = (col1 + col2 + 1) / 2;

        root->topLeft = construct(grid, row1, col1, rowMid - 1, colMid - 1, prefSum);
        root->topRight = construct(grid, row1, colMid, rowMid - 1, col2, prefSum);
        root->bottomLeft = construct(grid, rowMid, col1, row2, colMid - 1, prefSum);
        root->bottomRight = construct(grid, rowMid, colMid, row2, col2, prefSum);

        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        const int N = grid.size();

        vector<vector<int>> prefSum(N + 1, vector<int>(N + 1));
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= N; ++col){
                prefSum[row][col] = grid[row - 1][col - 1] + prefSum[row][col - 1] +
                                                             prefSum[row - 1][col] -
                                                             prefSum[row - 1][col - 1];
            }
        }

        return construct(grid, 0, 0, N - 1, N - 1, prefSum);
    }
};