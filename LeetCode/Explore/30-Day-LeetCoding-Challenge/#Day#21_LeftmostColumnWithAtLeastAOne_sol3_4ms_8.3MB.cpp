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
        
        int answer = m - 1;
        bool found_one = false;
        for(int line = 0; line < n; ++line){
            for(int col = answer; col >= 0; --col){                
                if(binaryMatrix.get(line, col) == 1){
                    --answer;
                    found_one = true;
                }else{
                    break;
                }
            }
        }
        
        if(found_one){
            ++answer;
        }else{
            answer = -1;
        }
        
        return answer;
    }
};