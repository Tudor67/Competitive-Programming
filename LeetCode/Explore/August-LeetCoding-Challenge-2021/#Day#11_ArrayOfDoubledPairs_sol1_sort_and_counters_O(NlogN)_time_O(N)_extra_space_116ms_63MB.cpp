class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        const int N = arr.size();
        
        unordered_map<int, int> count;
        for(int elem: arr){
            count[elem] += 1;
        }
        
        int zeros = 0;
        vector<int> arrPositives;
        vector<int> arrNegatives;
        for(int elem: arr){
            if(elem == 0){
                zeros += 1;
            }else if(elem > 0){
                arrPositives.push_back(elem);
            }else if(elem < 0){
                arrNegatives.push_back(elem);
            }
        }
        
        sort(arrPositives.begin(), arrPositives.end());
        sort(arrNegatives.rbegin(), arrNegatives.rend());
        
        if(zeros % 2 == 1){
            return false;
        }
        
        for(const vector<int> *ARR: {&arrPositives, &arrNegatives}){
            for(int elem: *ARR){
                if(count[elem] == 0){
                    continue;
                }
                if(count.find(2 * elem) != count.end() && count[2 * elem] >= 1){
                    count[2 * elem] -= 1;
                    count[elem] -= 1;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
};