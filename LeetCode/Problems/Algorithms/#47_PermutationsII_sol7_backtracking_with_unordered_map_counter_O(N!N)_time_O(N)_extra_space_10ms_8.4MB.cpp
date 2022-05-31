class Solution {
private:
    void back(int level, const int& N, vector<int>& st, unordered_map<int, int>& count, vector<vector<int>>& res){
        if(level == N){
            res.push_back(st);
        }else{
            for(const pair<int, int>& P: count){
                int num = P.first;
                if(count[num] > 0){
                    st[level] = num;
                    count[num] -= 1;
                    back(level + 1, N, st, count, res);
                    count[num] += 1;
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        
        vector<int> st(N);
        vector<vector<int>> res;
        back(0, N, st, count, res);
        
        return res;
    }
};