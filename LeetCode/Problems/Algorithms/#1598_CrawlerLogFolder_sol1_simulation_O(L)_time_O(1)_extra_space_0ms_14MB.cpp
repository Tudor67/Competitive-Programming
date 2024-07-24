class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(const string& LOG: logs){
            if(LOG == "./"){
                // ignore
            }else if(LOG == "../"){
                depth = max(depth - 1, 0);
            }else{
                depth = depth + 1;
            }
        }
        return depth;
    }
};