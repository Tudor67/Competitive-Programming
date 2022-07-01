class Solution {
private:
    double computeCollisionTime(vector<int>& car1, vector<int>& car2){
        double position1 = car1[0];
        double speed1 = car1[1];
        double position2 = car2[0];
        double speed2 = car2[1];
        return (position2 - position1) / (speed1 - speed2);
    }
    
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        const int N = cars.size();
        
        vector<double> answer(N, -1);
        vector<int> st(N);
        int k = -1;
        for(int i = N - 1; i >= 0; --i){
            while(k >= 0 && cars[i][1] <= cars[st[k]][1]){
                k -= 1;
            }
            while(k >= 1){
                if(computeCollisionTime(cars[i], cars[st[k]]) >= computeCollisionTime(cars[st[k]], cars[st[k - 1]])){
                    k -= 1;
                }else{
                    break;
                }
            }
            if(k >= 0){
                answer[i] = computeCollisionTime(cars[i], cars[st[k]]);
            }
            k += 1;
            st[k] = i;
        }
        
        return answer;
    }
};