class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        vector<int> sortedCapacities = capacity;
        sort(sortedCapacities.rbegin(), sortedCapacities.rend());

        int remApples = accumulate(apple.begin(), apple.end(), 0);
        for(int i = 0; i < (int)sortedCapacities.size(); ++i){
            remApples -= sortedCapacities[i];
            if(remApples <= 0){
                return i + 1;
            }
        }

        return -1;
    }
};