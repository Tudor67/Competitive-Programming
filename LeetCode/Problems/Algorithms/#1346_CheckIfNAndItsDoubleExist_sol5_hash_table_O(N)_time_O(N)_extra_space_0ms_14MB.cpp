class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> vis;
        for(int elem: arr){
            if(vis.count(elem * 2)){
                return true;
            }
            if(elem % 2 == 0 && vis.count(elem / 2)){
                return true;
            }
            vis.insert(elem);
        }
        return false;
    }
};