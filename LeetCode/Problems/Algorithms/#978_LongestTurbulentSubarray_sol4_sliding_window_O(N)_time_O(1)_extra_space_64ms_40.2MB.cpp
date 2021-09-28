class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int N = arr.size();
        
        int maxLength = 1;
        int i = 0;
        int j = 1;
        while(j < N){
            if(((j == 1 || arr[j - 2] < arr[j - 1]) && arr[j - 1] > arr[j]) ||
               ((j == 1 || arr[j - 2] > arr[j - 1]) && arr[j - 1] < arr[j])){
                maxLength = max(maxLength, j - i + 1);
            }else{
                i = j - 1;
            }
            j += 1;
        }
        
        return maxLength;
    }
};