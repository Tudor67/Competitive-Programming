class Spreadsheet {
private:
    unordered_map<string, int> cellToValue;

public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        cellToValue[cell] = value;
    }
    
    void resetCell(string cell) {
        cellToValue.erase(cell);
    }
    
    int getValue(string formula) {
        int plusIndex = formula.find('+');
        string aStr = formula.substr(1, plusIndex - 1);
        string bStr = formula.substr(plusIndex + 1);
        int aValue = (isdigit(aStr[0]) ? stoi(aStr) : cellToValue[aStr]);
        int bValue = (isdigit(bStr[0]) ? stoi(bStr) : cellToValue[bStr]);
        return (aValue + bValue);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */