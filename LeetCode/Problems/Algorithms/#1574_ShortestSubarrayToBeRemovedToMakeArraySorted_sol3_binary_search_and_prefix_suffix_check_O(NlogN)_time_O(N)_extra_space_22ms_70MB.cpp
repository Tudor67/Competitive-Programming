class Solution {
private:
    bool isPossible(vector<int>& arr, vector<bool>& isIncPrefix, vector<bool>& isIncSuffix, int maxRemovals){
        const int N = arr.size();

        if(maxRemovals == 0){
            return is_sorted(arr.begin(), arr.end());
        }

        if(maxRemovals == N){
            return true;
        }

        for(int i = 0; i + maxRemovals - 1 < N; ++i){
            int l = i;
            int r = i + maxRemovals - 1;
            if(l - 1 >= 0 && !isIncPrefix[l - 1]){
                continue;
            }
            if(r + 1 < N && !isIncSuffix[r + 1]){
                continue;
            }
            if(l - 1 >= 0 && r + 1 < N && arr[l - 1] > arr[r + 1]){
                continue;
            }
            return true;
        }

        return false;
    }

public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int N = arr.size();

        vector<bool> isIncPrefix(N);
        isIncPrefix[0] = true;
        for(int i = 1; i < N; ++i){
            isIncPrefix[i] = isIncPrefix[i - 1] && (arr[i - 1] <= arr[i]);
        }

        vector<bool> isIncSuffix(N);
        isIncSuffix[N - 1] = true;
        for(int i = N - 2; i >= 0; --i){
            isIncSuffix[i] = (arr[i] <= arr[i + 1]) && isIncSuffix[i + 1];
        }

        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(arr, isIncPrefix, isIncSuffix, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};