class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        
        vector<int> sizes = {v[2] - v[1] - 1, v[1] - v[0] - 1};
        
        int minMoves = 2;
        if(sizes[0] == 0 && sizes[1] == 0){
            minMoves = 0;
        }else if(sizes[0] <= 1 || sizes[1] <= 1){
            minMoves = 1;
        }
        int maxMoves = sizes[0] + sizes[1];
        
        return {minMoves, maxMoves};
    }
};