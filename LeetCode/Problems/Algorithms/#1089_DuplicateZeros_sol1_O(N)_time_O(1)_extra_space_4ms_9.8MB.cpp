class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int N = arr.size();
        
        int pos = 0;
        int target_pos = -1;
        for(int i = 0; i <= N - 1; ++i){
            target_pos += 1;
            if(arr[i] == 0){
                target_pos += 1;
            }
            if(target_pos >= N - 1){
                pos = i;
                break;
            }
        }
        
        while(pos >= 0){
            if(target_pos <= N - 1 && arr[pos] == 0){
                arr[target_pos] = 0;
                target_pos -= 1;
            }
            target_pos = min(N - 1, target_pos);
            if(pos >= 0){
                arr[target_pos] = arr[pos];
                target_pos -= 1;
                pos -= 1;
            }
        }
    }
};