class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int N = arr.size();

        for(int i = 0; i < N; i += max(1, N / 4)){
            int freq = upper_bound(arr.begin(), arr.end(), arr[i]) -
                       lower_bound(arr.begin(), arr.end(), arr[i]);
            if(freq > N / 4){
                return arr[i];
            }
        }

        return -1;
    }
};