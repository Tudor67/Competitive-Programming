/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const int n = binaryMatrix.dimensions()[0];
        const int m = binaryMatrix.dimensions()[1];
        
        int answer = m;
        int l = 0;
        int r = m - 1;
        for(int line = 0; line < n; ++line){
            // binary search
            // left = 0, right = previous right
            l = 0;
            while(l != r){
                int mid = (l + r) / 2;
                if(binaryMatrix.get(line, mid) == 1){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            
            if(binaryMatrix.get(line, r) == 1){
                answer = min(r, answer);
            }
        }
        
        if(answer == m){
            answer = -1;
        }
        
        return answer;
    }
};