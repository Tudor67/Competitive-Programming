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
            int j = i + 1;
            int k = N - 1;
            while(j < k){
                if(arr[i] + arr[j] + arr[k] < target){
                    ++j;
                }else if(arr[i] + arr[j] + arr[k] > target){
                    --k;
                }else{
                    int l = 1;
                    while(j + l < N && arr[j] == arr[j + l]){
                        ++l;
                    }
                    int r = 1;
                    while(k - r > i && arr[k] == arr[k - r]){
                        ++r;
                    }
                    if(arr[j] == arr[k]){
                        tuples += (r * (r - 1)) / 2;
                        tuples %= MODULO;
                    }else{
                        tuples += (l * r);
                        tuples %= MODULO;
                    }
                    j += l;
                    k -= r;
                }
            }
        }
        
        return tuples;
    }
};