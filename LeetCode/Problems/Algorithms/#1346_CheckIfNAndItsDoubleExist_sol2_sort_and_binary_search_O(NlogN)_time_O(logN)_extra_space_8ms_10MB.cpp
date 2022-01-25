class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const int N = arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < N; ++i){
            int j = lower_bound(arr.begin(), arr.end(), 2 * arr[i]) - arr.begin();
            if(j < N && j != i && arr[j] == 2 * arr[i]){
                return true;
            }
        }
        
        return false;
    }
};