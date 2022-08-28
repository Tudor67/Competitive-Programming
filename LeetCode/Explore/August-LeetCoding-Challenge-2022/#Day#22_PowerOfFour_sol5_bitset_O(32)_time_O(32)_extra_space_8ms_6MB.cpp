class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }
        
        if(n == 1){
            return true;
        }
        
        string binaryRepresentation = bitset<32>(n).to_string();
        int nonZeroBits = count(binaryRepresentation.begin(), binaryRepresentation.end(), '1');
        int trailingZeros = find(binaryRepresentation.rbegin(), binaryRepresentation.rend(), '1') - binaryRepresentation.rbegin();
        return (nonZeroBits == 1 && trailingZeros % 2 == 0);
    }
};