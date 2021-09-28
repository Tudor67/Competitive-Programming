class Solution {
private:
    int direction(const int& A, const int& B){
        if(A < B){
            return 1;
        }
        if(A > B){
            return -1;
        }
        return 0;
    }
    
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int N = arr.size();
        
        int maxLength = 1;
        int length = 1;
        for(int i = 1; i < N; ++i){
            if((i == 1 && direction(arr[i - 1], arr[i]) != 0) ||
               (i >= 2 && direction(arr[i - 2], arr[i - 1]) * direction(arr[i - 1], arr[i]) < 0)){
                length += 1;
                maxLength = max(maxLength, length);
            }else{
                length = 2;
            }
        }
        
        return maxLength;
    }
};