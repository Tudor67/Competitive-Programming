class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        const int N = arr.size();
        
        int zeros = 0;
        map<int, int> countPositives;
        map<int, int> countNegatives;
        for(int elem: arr){
            if(elem == 0){
                zeros += 1;
            }else if(elem > 0){
                countPositives[elem] += 1;
            }else if(elem < 0){
                countNegatives[elem] += 1;
            }
        }
        
        if(zeros % 2 == 1){
            return false;
        }
        
        for(map<int, int>::iterator it = countPositives.begin(); it != countPositives.end(); ++it){
            int elem = it->first;
            if(countPositives[elem] == 0){
                continue;
            }
            if(countPositives.count(2 * elem) && countPositives[elem] <= countPositives[2 * elem]){
                countPositives[2 * elem] -= countPositives[elem];
            }else{
                return false;
            }
        }
        
        for(map<int, int>::reverse_iterator it = countNegatives.rbegin(); it != countNegatives.rend(); ++it){
            int elem = it->first;
            if(countNegatives[elem] == 0){
                continue;
            }
            if(countNegatives.count(2 * elem) && countNegatives[elem] <= countNegatives[2 * elem]){
                countNegatives[2 * elem] -= countNegatives[elem];
                countNegatives[elem] = 0;
            }else{
                return false;
            }
        }
        
        return true;
    }
};