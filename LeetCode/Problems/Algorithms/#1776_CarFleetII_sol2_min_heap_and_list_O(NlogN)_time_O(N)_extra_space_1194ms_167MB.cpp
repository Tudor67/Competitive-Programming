class Solution {
private:
    const double INF = 1e18;
    
    double computeCollisionTime(vector<int>& car1, vector<int>& car2){
        double position1 = car1[0];
        double speed1 = car1[1];
        double position2 = car2[0];
        double speed2 = car2[1];
        if(speed1 > speed2){
            return (position2 - position1) / (speed1 - speed2);
        }
        return INF;
    }
    
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        const int N = cars.size();
        
        using T3 = tuple<double, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        for(int i = 0; i + 1 < N; ++i){
            double collisionTime = computeCollisionTime(cars[i], cars[i + 1]);
            if(collisionTime != INF){
                minHeap.emplace(collisionTime, i, i + 1);
            }
        }
        
        list<int> waiting;
        vector<list<int>::iterator> iteratorOf(N);
        for(int i = 0; i + 1 < N; ++i){
            waiting.push_back(i);
            iteratorOf[i] = prev(waiting.end());
        }
        
        vector<double> answer(N, -1);
        while(!minHeap.empty()){
            double collisionTime = get<0>(minHeap.top());
            int i = get<1>(minHeap.top());
            int j = get<2>(minHeap.top());
            minHeap.pop();
            
            if(answer[i] == -1){
                answer[i] = collisionTime;
            }else{
                continue;
            }
            
            list<int>::iterator it = iteratorOf[i];
            if(it != waiting.begin()){
                int prevI = *prev(it);
                double nextCollisionTime = computeCollisionTime(cars[prevI], cars[j]);
                if(nextCollisionTime != INF){
                    minHeap.emplace(nextCollisionTime, prevI, j);
                }
            }
            
            waiting.erase(iteratorOf[i]);
        }
        
        return answer;
    }
};