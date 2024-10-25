class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);

        vector<int> sortedCapacities = capacity;
        sort(sortedCapacities.rbegin(), sortedCapacities.rend());
        
        int prefCapacity = 0;
        for(int i = 0; i < (int)sortedCapacities.size(); ++i){
            prefCapacity += sortedCapacities[i];
            if(totalApples <= prefCapacity){
                return i + 1;
            }
        }
        
        return -1;
    }
};