class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        const int N = nums.size();
        
        vector<vector<int>> a(N);
        for(int i = 0; i < N; ++i){
            if(nums[i] % 2 == 0){
                int x = nums[i];
                while(x % 2 == 0){
                    a[i].push_back(x);
                    x /= 2;
                }
                a[i].push_back(x);
                reverse(a[i].begin(), a[i].end());
            }else{
                a[i].push_back(nums[i]);
                a[i].push_back(nums[i] * 2);
            }
        }
        
        set<tuple<int, int, int>> tSet;
        for(int i = 0; i < N; ++i){
            tSet.emplace(a[i][0], i, 0);
        }
        
        int minDiff = get<0>(*prev(tSet.end())) - get<0>(*tSet.begin());
        while((int)tSet.size() == N && minDiff > 0){
            int diff = get<0>(*prev(tSet.end())) - get<0>(*tSet.begin());
            minDiff = min(minDiff, diff);
            
            int i = get<1>(*tSet.begin());
            int j = get<2>(*tSet.begin());
            tSet.erase(tSet.begin());
            
            if(j + 1 < (int)a[i].size()){
                tSet.emplace(a[i][j + 1], i, j + 1);
            }
        }
        
        return minDiff;
    }
};