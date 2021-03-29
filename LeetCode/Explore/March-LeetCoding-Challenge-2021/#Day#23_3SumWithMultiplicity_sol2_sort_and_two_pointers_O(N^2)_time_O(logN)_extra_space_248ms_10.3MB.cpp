class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MODULO = 1e9 + 7;
        const int N = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            int j = i + 1;
            int k = N - 1;
            while(j < k){
                int currentSum = arr[i] + arr[j] + arr[k];
                if(currentSum == target){
                    int initialJ = j;
                    while(j < k && arr[initialJ] == arr[j]){
                        j += 1;
                    }
                    int initialK = k;
                    while(j <= k && arr[k] == arr[initialK]){
                        k -= 1;
                    }
                    if(arr[initialJ] == arr[initialK]){
                        int c = initialK - initialJ + 1;
                        answer += (c - 1) * c / 2;
                        answer %= MODULO;
                    }else{
                        answer += (j - initialJ) * (initialK - k);
                        answer %= MODULO;
                    }
                }else if(currentSum < target){
                    j += 1;
                }else if(currentSum > target){
                    k -= 1;
                }
            }
        }
        
        return answer;
    }
};