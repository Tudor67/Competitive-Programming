class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        const int N = arr.size();
        const int MEDIAN_IDX = (N - 1) / 2;
        
        nth_element(arr.begin(), arr.begin() + MEDIAN_IDX, arr.end());
        
        const int MEDIAN = arr[MEDIAN_IDX];
        
        nth_element(arr.begin(), arr.begin() + k, arr.end(),
                    [&](int lhs, int rhs){
                        int lhsDist = abs(lhs - MEDIAN);
                        int rhsDist = abs(rhs - MEDIAN);
                        return (lhsDist > rhsDist || (lhsDist == rhsDist && lhs > rhs));
                    });
        
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};