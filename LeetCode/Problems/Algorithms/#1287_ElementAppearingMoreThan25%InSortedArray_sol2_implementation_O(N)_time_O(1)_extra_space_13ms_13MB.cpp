class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int N = arr.size();

        for(int i = 0; i + N / 4 < N; ++i){
            if(arr[i] == arr[i + N / 4]){
                return arr[i];
            }
        }

        return -1;
    }
};