class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int N = arr.size();
        const int MODULO = 1e9 + 7;
        
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
            }
        }
        
        int tuples = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int remTarget = target - arr[i] - arr[j];
                vector<int>::iterator it1 = lower_bound(arr.begin() + j + 1, arr.end(), remTarget);
                vector<int>::iterator it2 = upper_bound(arr.begin() + j + 1, arr.end(), remTarget);
                tuples += (it2 - it1);
                tuples %= MODULO;
            }
        }
        
        return tuples;
    }
};