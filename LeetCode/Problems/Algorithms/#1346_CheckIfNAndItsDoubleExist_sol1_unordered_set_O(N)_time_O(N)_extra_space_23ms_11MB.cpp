class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Step 1: special case (at least two zeros)
        int zeros = count(arr.begin(), arr.end(), 0);
        if(zeros >= 2){
            return true;
        }
        
        // Step 2: for a given elem (!= 0) check if 2 * elem is in arrSet
        unordered_set<int> arrSet(arr.begin(), arr.end());
        for(int elem: arrSet){
            if(elem != 0 && arrSet.count(2 * elem)){
                return true;
            }
        }
        
        return false;
    }
};