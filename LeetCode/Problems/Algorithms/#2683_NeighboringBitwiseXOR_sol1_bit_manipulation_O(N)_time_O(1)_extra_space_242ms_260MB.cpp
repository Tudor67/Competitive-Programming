class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        const int N = derived.size();
        
        int dXOR = 0;
        for(int d: derived){
            dXOR ^= d;
        }
        
        return (bool)(dXOR == 0);
    }
};