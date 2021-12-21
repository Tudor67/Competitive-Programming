class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        const int N = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int minDiff = arr[1] - arr[0];
        for(int i = 1; i < N; ++i){
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        
        vector<vector<int>> minPairs;
        for(int i = 1; i < N; ++i){
            if(arr[i] - arr[i - 1] == minDiff){
                minPairs.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return minPairs;
    }
};