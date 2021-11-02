class Solution {
private:
    int getFirstMatchStart(const vector<int>& GROUP, const vector<int>& NUMS, int pos){
        const int C = GROUP.size();
        const int N = NUMS.size();
        
        // prefix function for GROUP
        static vector<int> p;
        p.assign(C, 0);
        for(int i = 1; i < C; ++i){
            int k = p[i - 1];
            while(k > 0 && GROUP[k] != GROUP[i]){
                k = p[k - 1];
            }
            if(GROUP[k] == GROUP[i]){
                p[i] = k + 1;
            }
        }
        
        // find first match of GROUP in NUMS[pos..]
        for(int j = pos; j < N; ++j){
            p.push_back(0);
            int i = (int)p.size() - 1;
            int k = p[i - 1];
            while(k > 0 && GROUP[k] != NUMS[j]){
                k = p[k - 1];
            }
            if(GROUP[k] == NUMS[j]){
                p[i] = k + 1;
            }
            if(p[i] == C){
                return j - C + 1;
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