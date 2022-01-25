class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        const int N = arr.size();
        
        vector<int> v;
        int totalSizeOfLIS = 0;
        for(int startPos = 0; startPos < k; ++startPos){
            v.clear();
            for(int i = startPos; i < N; i += k){
                int j = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
                v.resize(max((int)v.size(), j + 1));
                v[j] = arr[i];
            }
            totalSizeOfLIS += v.size();
        }
        
        return N - totalSizeOfLIS;
    }
};