class Solution {    
public:
    bool checkIfExist(vector<int>& arr) {
        const int N = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int j = 0;
        for(int i = 0; i < N; ++i){
            while(j < N && arr[j] < 2 * arr[i]){
                j += 1;
            }
            if(j < N && j != i && arr[j] == 2 * arr[i]){
                return true;
            }
        }
        
        return false;
    }
};