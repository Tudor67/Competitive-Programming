class Solution {
private:
    int getFirstMatchStart(const vector<int>& GROUP, const vector<int>& NUMS, int pos){
        const int C = GROUP.size();
        const int N = NUMS.size();
        while(pos + C - 1 < N){
            if(equal(GROUP.begin(), GROUP.end(), NUMS.begin() + pos)){
                return pos;
            }else{
                pos += 1;
            }
        }
        return N;
    }
    
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        const int R = groups.size();
        const int N = nums.size();
        int pos = 0;
        for(int i = 0; i < R; ++i){
            pos = getFirstMatchStart(groups[i], nums, pos) + (int)groups[i].size();
            if(pos > N || (pos == N && i < R - 1)){
                return false;
            }
        }
        return true;
    }
};