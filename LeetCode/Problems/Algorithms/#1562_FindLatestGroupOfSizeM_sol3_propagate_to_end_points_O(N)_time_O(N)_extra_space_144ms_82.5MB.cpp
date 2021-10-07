class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int N = arr.size();
        int answer = -1;
        
        vector<int> length(N + 2, 0);
        vector<int> count(N + 2, 0);
        for(int i = 0; i < N; ++i){
            int leftLength = length[arr[i] - 1];
            int rightLength = length[arr[i] + 1];
            int currentLength = leftLength + 1 + rightLength;
            
            count[leftLength] -= 1;
            count[rightLength] -= 1;
            length[arr[i]] = currentLength;
            count[currentLength] += 1;
            length[arr[i] - leftLength] = currentLength;
            length[arr[i] + rightLength] = currentLength;
            
            if(count[m] >= 1){
                answer = i + 1;
            }
        }
        
        return answer;
    }
};