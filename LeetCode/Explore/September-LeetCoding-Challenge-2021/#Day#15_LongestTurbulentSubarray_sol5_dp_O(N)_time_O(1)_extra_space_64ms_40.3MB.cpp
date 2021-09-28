class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int N = arr.size();
        
        int maxLength = 1;
        int incLength = 1; // At step i: max length of turbulent array ending with arr[i] and arr[i - 1] < arr[i]
        int decLength = 1; // At step i: max length of turbulent array ending with arr[i] and arr[i - 1] > arr[i]
        
        for(int i = 1; i < N; ++i){
            if(arr[i - 1] < arr[i]){
                incLength = decLength + 1;
                decLength = 1;
                maxLength = max(maxLength, incLength);
            }else if(arr[i - 1] > arr[i]){
                decLength = incLength + 1;
                incLength = 1;
                maxLength = max(maxLength, decLength);
            }else{
                incLength = 1;
                decLength = 1;
            }
        }
        
        return maxLength;
    }
};