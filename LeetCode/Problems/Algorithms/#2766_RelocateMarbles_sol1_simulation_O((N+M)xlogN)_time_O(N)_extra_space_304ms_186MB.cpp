class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        const int N = nums.size();
        const int M = moveFrom.size();
        
        set<int> s(nums.begin(), nums.end());
        for(int i = 0; i < M; ++i){
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
        
        return vector<int>(s.begin(), s.end());
    }
};