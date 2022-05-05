class Solution {
private:
    int getMappedValue(int num, vector<int>& mapping){
        string s = to_string(num);
        int res = 0;
        for(char c: s){
            res = res * 10 + mapping[c - '0'];
        }
        return res;
    }
    
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int N = nums.size();
        
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {getMappedValue(nums[i], mapping), i};
        }
        
        sort(v.begin(), v.end());
        
        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            res[i] = nums[v[i].second];
        }
        
        return res;
    }
};