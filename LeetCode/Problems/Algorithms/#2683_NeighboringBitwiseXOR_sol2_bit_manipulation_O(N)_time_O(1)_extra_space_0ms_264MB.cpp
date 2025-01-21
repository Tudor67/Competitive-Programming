class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int derivedXOR = 0;
        for(int elem: derived){
            derivedXOR ^= elem;
        }
        return (derivedXOR == 0);
    }
};