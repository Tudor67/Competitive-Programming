class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int> cnt(1001, 0);
        for(int x: arr){
            ++cnt[x];
        }
        
        int ans = 0;
        for(int x = 0; x < 1000; ++x){
            if(cnt[x + 1]){
                ans += cnt[x];
            }
        }
        
        return ans;
    }
};