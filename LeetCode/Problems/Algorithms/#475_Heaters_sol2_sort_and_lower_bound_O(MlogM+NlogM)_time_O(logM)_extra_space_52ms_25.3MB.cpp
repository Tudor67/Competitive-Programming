class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int answer = 0;
        for(int house: houses){
            int minR = INT_MAX;
            vector<int>::iterator it = lower_bound(heaters.begin(), heaters.end(), house);
            if(it != heaters.end()){
                minR = min(abs(*it - house), minR);
            }
            if(it != heaters.begin()){
                minR = min(abs(*prev(it) - house), minR);
            }
            answer = max(minR, answer);
        }
        return answer;
    }
};