class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        const int F = flowers.size();
        const int P = persons.size();
        
        // newFlowerBloomsAt[t]: the number of new flower blooms at time t
        //                       negative values represent the end of flower blooms
        map<int, int> newFlowerBloomsAt;
        for(const vector<int>& V: flowers){
            int firstTime = V[0];
            int lastTime = V[1];
            newFlowerBloomsAt[firstTime] += 1;
            newFlowerBloomsAt[lastTime + 1] -= 1;
        }
        
        // sort person times in increasing order and keep their indices in the original vector
        // we will process person times from smallest to largest (with a pointer idx that moves from 0 to P - 1)
        vector<pair<int, int>> sortedPersonTimesWithIndices(P);
        for(int j = 0; j < P; ++j){
            sortedPersonTimesWithIndices[j] = {persons[j], j};
        }
        
        sort(sortedPersonTimesWithIndices.begin(), sortedPersonTimesWithIndices.end());
        
        // maintain the number of flowerBlooms in the range [prevTime, currentTime]
        // with a sweeping line technique (move from smallest time to the largest time from newFlowerBloomsAt map)
        // update answer for all persons with time <= currentTime using sortedPersonTimesWithIndices and pointer idx
        vector<int> answer(P);
        int idx = 0;
        int flowerBlooms = 0; // flower blooms in the range: [prevTime, currentTime]
        int prevTime = newFlowerBloomsAt.begin()->second;
        for(const pair<int, int>& TF: newFlowerBloomsAt){
            int currentTime = TF.first - 1;
            
            while(idx < P && sortedPersonTimesWithIndices[idx].first <= currentTime){
                if(prevTime <= sortedPersonTimesWithIndices[idx].first){
                    int j = sortedPersonTimesWithIndices[idx].second;
                    answer[j] = flowerBlooms;
                }
                idx += 1;
            }
            
            int newFlowerBlooms = TF.second;
            flowerBlooms += newFlowerBlooms;
            prevTime = currentTime + 1;
        }
        
        return answer;
    }
};