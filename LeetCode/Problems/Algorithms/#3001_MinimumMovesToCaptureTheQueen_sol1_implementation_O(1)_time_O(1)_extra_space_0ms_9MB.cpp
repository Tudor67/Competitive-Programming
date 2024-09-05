class Solution {
public:
    int minMovesToCaptureTheQueen(int rRow, int rCol, int bRow, int bCol, int qRow, int qCol) {
        if((rRow == qRow && !(rRow == bRow && min(rCol, qCol) < bCol && bCol < max(rCol, qCol))) ||
           (rCol == qCol && !(rCol == bCol && min(rRow, qRow) < bRow && bRow < max(rRow, qRow)))){
            return 1;
        }
        
        if((bRow + bCol == qRow + qCol && !(bRow + bCol == rRow + rCol && min(bRow, qRow) < rRow && rRow < max(bRow, qRow))) ||
           (bRow - bCol == qRow - qCol && !(bRow - bCol == rRow - rCol && min(bRow, qRow) < rRow && rRow < max(bRow, qRow)))){
            return 1;
        }
        
        return 2;
    }
};