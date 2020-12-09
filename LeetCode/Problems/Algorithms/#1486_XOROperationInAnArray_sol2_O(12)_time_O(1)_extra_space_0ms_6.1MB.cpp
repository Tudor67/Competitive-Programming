class Solution {
private:
    int countBits1(int x, int bitPos){
        int blockSize = (2 << bitPos);
        int blocks = (x + 1) / blockSize;
        return blocks * (blockSize / 2) + max(0, (x + 1) % blockSize - blockSize / 2);
    }
    
public:
    int xorOperation(int n, int start) {
        // O(12) time and O(1) space solution
        // Observations:
        // (1) start ^ (start + 2) ^ (start + 4) ^ (start + 6) ^ ... ^ (start + 2 * (n - 1))
        //       =
        //      2 * (start/2 ^ (start/2 + 1) ^ (start/2 + 2) ^ (start/2 + 3) ^ ... ^ (start/2 + n - 1)) + (start % 2 == 1) * (n % 2 == 1)
        //      
        // (2) x ^ (x + 1) ^ (x + 2) ^ .... ^ (x + k) can be computed easily using binary representations of x, x + 1, .... x + k
        //     The main idea is that each bit is periodic:
        //     num      bit position
        //              3210
        //      0:      0000
        //      1:      0001
        //      2:      0010
        //      3:      0011
        //      4:      0100
        //      5:      0101
        //      6:      0110
        //      7:      0111
        //      bit sequence for (0th position, i.e., first  column of 'bit position'): 0,1,0,1,0,1,0,1,0,1,0,1,....
        //      bit sequence for (1st position, i.e., second column of 'bit position'): 0,0,1,1,0,0,1,1,0,0,1,1,....
        //      bit sequence for (2nd position, i.e., third  column of 'bit position'): 0,0,0,0,1,1,1,1,0,0,0,0,....
        
        int answer = 0;
        int x1 = start / 2;
        int x2 = start / 2 + n - 1;
        for(int bitPos = 0; bitPos <= 12; ++bitPos){
            answer |= ((countBits1(x2, bitPos) - countBits1(x1 - 1, bitPos)) % 2) << bitPos;
        }
        
        answer = 2 * answer + (start % 2) * (n % 2);
        
        return answer;
    }
};