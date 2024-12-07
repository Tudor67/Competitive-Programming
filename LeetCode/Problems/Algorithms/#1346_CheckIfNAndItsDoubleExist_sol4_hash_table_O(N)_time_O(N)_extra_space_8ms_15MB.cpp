class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if(count(arr.begin(), arr.end(), 0) >= 2){
            return true;
        }

        unordered_set<int> arrSet(arr.begin(), arr.end());
        arrSet.erase(0);
        for(int elem: arr){
            if(arrSet.count(elem * 2)){
                return true;
            }
        }

        return false;
    }
};