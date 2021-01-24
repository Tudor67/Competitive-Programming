class Solution {
private:
    unordered_map<string, vector<char>> candidates;
    unordered_set<string> visited;
    
    void back(string& colors, int pos1, int pos2, const vector<bool>& IS_ROW_END, bool& isValid){
        if(pos2 == colors.length()){
            isValid = true;
        }
        
        if(isValid){
            return;
        }
        
        string currentPair = colors.substr(pos1, 2);
        for(char candidate: candidates[currentPair]){
            colors[pos2] = candidate;
            if(IS_ROW_END[pos1 + 1]){
                string currentRow = colors.substr(pos1 + 2, pos2 - pos1 - 1);
                if(visited.count(currentRow)){
                    break;
                }else{
                    visited.insert(currentRow);
                }
            }
            back(colors, pos1 + 1 + IS_ROW_END[pos1 + 1], pos2 + 1, IS_ROW_END, isValid);
        }
    }
    
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Step 1: store the candidates
        visited.clear();
        candidates.clear();
        for(const string& T: allowed){
            candidates[T.substr(0, 2)].push_back(T[2]);
        }
        
        // Step 2: init colors and isRowEnd
        const int N = bottom.length();
        const int MAX_SIZE = N * (N + 1) / 2;
        
        string colors = bottom;
        colors.resize(MAX_SIZE);
        vector<bool> isRowEnd(MAX_SIZE, false);
        for(int rowSize = N, idx = 0; rowSize >= 1; rowSize -= 1){
            isRowEnd[idx + rowSize - 1] = true;
            idx += rowSize;
        }
        
        // Step 3: backtracking
        bool isValid = false;
        back(colors, 0, N, isRowEnd, isValid);
        
        return isValid;
    }
};