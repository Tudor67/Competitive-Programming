class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int N = arr.size();
        
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        vector<bool> vis(N + 1, false);
        int count = 0;
        for(int i = 0; i < N; ++i){
            count += 1;
            if(i == N - 1 || sortedArr[i] != sortedArr[i + 1]){
                if(vis[count]){
                    return false;
                }
                vis[count] = true;
                count = 0;
            }
        }
        
        return true;
    }
};