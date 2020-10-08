class Solution {
public:
    int bitwiseComplement(int N) {
        int complement;
        if(N == 0){
            complement = 1;
        }else{
            string binaryRepresentation = bitset<30>(N).to_string();
            binaryRepresentation = binaryRepresentation.substr(binaryRepresentation.find('1'));
            complement = (1 << binaryRepresentation.length()) - 1 - N;
        }
        return complement;
    }
};