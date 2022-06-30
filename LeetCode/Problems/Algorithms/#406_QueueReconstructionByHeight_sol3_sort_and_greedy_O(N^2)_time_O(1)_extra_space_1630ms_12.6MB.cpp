class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int N = people.size();
        
        // sort in decreasing order of heights (in case of ties sort in increasing order of k)
        vector<vector<int>> res = people;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(res[i][0] < res[j][0] || (res[i][0] == res[j][0] && res[i][1] > res[j][1])){
                    swap(res[i], res[j]);
                }
            }
        }
        
        // move to left the current person only if his k is too large
        // this operation maintains the properties of left persons
        //                because the current height is less than or equal to the left heights
        for(int i = 1; i < N; ++i){
            int greaterOrEqual = 0;
            for(int j = 0; j < i; ++j){
                if(res[j][0] >= res[i][0]){
                    greaterOrEqual += 1;
                }
                if(greaterOrEqual == res[i][1] + 1){
                    res.insert(res.begin() + j, res[i]);
                    res.erase(res.begin() + i + 1);
                    break;
                }
            }
        }
        
        return res;
    }
};