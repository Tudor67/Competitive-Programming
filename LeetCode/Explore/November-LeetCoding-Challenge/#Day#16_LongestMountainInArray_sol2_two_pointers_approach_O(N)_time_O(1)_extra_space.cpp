class Solution {
public:
    int longestMountain(vector<int>& A) {
        const int N = A.size();
        int answer = 0;
        
        int i = 0;
        while(i < N){
            int increasingSize = 0;
            while(i + increasingSize + 1 < N && A[i + increasingSize] < A[i + increasingSize + 1]){
                increasingSize += 1;
            }
            i += increasingSize;
            
            int decreasingSize = 0;
            while(i + decreasingSize + 1 < N && A[i + decreasingSize] > A[i + decreasingSize + 1]){
                decreasingSize += 1;
            }
            i += decreasingSize;
            
            if(increasingSize > 0 && decreasingSize > 0){
                answer = max(increasingSize + decreasingSize + 1, answer);
            }else if(increasingSize == 0 && decreasingSize == 0){
                i += 1;
            }
        }
        
        return answer;
    }
};