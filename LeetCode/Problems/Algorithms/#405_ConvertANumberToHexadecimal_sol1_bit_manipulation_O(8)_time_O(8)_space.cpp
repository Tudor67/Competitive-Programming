class Solution {
public:
    string toHex(int num) {
        string binaryRepresentation;
        for(int blockIdx = 0; blockIdx < 8; ++blockIdx){
            int blockValue = (num >> (4 * blockIdx)) & 15;
            if(blockValue <= 9){
                binaryRepresentation += char('0' + blockValue);
            }else{
                binaryRepresentation += char('a' + blockValue - 10);
            }
        }
        
        while(binaryRepresentation.size() > 1 && binaryRepresentation.back() == '0'){
            binaryRepresentation.pop_back();
        }
        
        reverse(binaryRepresentation.begin(), binaryRepresentation.end());
        
        return binaryRepresentation;
    }
};