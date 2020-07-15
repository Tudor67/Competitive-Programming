class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binary_representation = bitset<32>(n).to_string();
        string reversed_binary_representation(binary_representation.rbegin(), binary_representation.rend());
        uint32_t answer = bitset<32>(reversed_binary_representation).to_ulong();
        return answer;
    }
};