class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        const int N = arr.size();
        
        int idx1 = 0;
        int idx2 = 0;
        for(int i = N - 2; i >= 0; --i){
            if(arr[i] > arr[i + 1]){
                idx1 = i;
                idx2 = i + 1;
                while(idx2 + 1 < N && arr[idx1] > arr[idx2 + 1]){
                    idx2 += 1;
                }
                while(idx2 - 1 >= 0 && arr[idx2 - 1] == arr[idx2]){
                    idx2 -= 1;
                }
                break;
            }
        }
        
        vector<int> res = arr;
        swap(res[idx1], res[idx2]);
        
        return res;
    }
};