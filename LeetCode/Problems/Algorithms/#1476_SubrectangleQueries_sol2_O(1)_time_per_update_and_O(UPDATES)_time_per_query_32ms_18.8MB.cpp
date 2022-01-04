class SubrectangleQueries {
private:
    vector<vector<int>> rectangle;
    vector<tuple<int, int, int, int, int>> updates;
    
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rectangle = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.emplace_back(row1, col1, row2, col2, newValue);
    }
    
    int getValue(int row, int col) {
        for(int i = (int)updates.size() - 1; i >= 0; --i){
            int row1, col1, row2, col2, val;
            tie(row1, col1, row2, col2, val) = updates[i];
            if(row1 <= row && row <= row2 && col1 <= col && col <= col2){
                return val;
            }
        }
        return rectangle[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */