class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        const int MAX_VAL = 100;
        
        vector<int> pos(MAX_VAL + 1, -1);
        for(int i = 0; i < pieces.size(); ++i){
            pos[pieces[i][0]] = i;
        }
        
        vector<bool> vis(pieces.size(), false);
        vector<int> arrConcat;
        for(int elem: arr){
            if(pos[elem] >= 0 && !vis[pos[elem]]){
                for(int j = 0; j < pieces[pos[elem]].size(); ++j){
                    arrConcat.push_back(pieces[pos[elem]][j]);
                }
                vis[pos[elem]] = true;
            }
        }
        
        return (arr == arrConcat);
    }
};