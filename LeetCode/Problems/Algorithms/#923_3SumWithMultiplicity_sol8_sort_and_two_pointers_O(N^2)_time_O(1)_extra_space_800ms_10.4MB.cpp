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
            int k = N - 1;
            int prevFreq = 0;
            for(int j = i + 1; j < N; ++j){
                if(i + 1 < j && arr[j - 1] == arr[j]){
                    prevFreq -= (int)(target - arr[i] - arr[j] == arr[j]);
                    tuples += prevFreq;
                    tuples %= MODULO;
                }else{
                    int remTarget = target - arr[i] - arr[j];
                    int freq = 0;
                    while(j < k && remTarget <= arr[k]){
                        if(remTarget == arr[k]){
                            freq += 1;
                        }
                        k -= 1;
                    }
                    tuples += freq;
                    tuples %= MODULO;
                    prevFreq = freq;
                }
            }
        }
        
        return tuples;
    }
};