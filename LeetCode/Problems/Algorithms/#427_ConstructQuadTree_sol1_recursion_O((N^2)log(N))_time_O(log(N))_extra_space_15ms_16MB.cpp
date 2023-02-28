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
    bool sameValues(vector<vector<int>>& grid, int row1, int col1, int row2, int col2){
        int val = grid[row1][col1];
        for(int row = row1; row <= row2; ++row){
            for(int col = col1; col <= col2; ++col){
                if(grid[row][col] != val){
                    return false;
                }
            }
        }
        return true;
    }

    Node* construct(vector<vector<int>>& grid, int row1, int col1, int row2, int col2){
        if(sameValues(grid, row1, col1, row2, col2)){
            return new Node((bool)grid[row1][col1], true);
        }

        Node* root = new Node((bool)grid[row1][col1], false);
        int rowMid = (row1 + row2 + 1) / 2;
        int colMid = (col1 + col2 + 1) / 2;

        root->topLeft = construct(grid, row1, col1, rowMid - 1, colMid - 1);
        root->topRight = construct(grid, row1, colMid, rowMid - 1, col2);
        root->bottomLeft = construct(grid, rowMid, col1, row2, colMid - 1);
        root->bottomRight = construct(grid, rowMid, colMid, row2, col2);

        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        const int N = grid.size();
        return construct(grid, 0, 0, N - 1, N - 1);
    }
};