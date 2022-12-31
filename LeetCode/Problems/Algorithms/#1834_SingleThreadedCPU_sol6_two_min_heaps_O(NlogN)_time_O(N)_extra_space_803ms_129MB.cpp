class Task{
public:
    int enqueueTime;
    int processingTime;
    int index;

public:
    Task(int enqueueTime, int processingTime, int index){
        this->enqueueTime = enqueueTime;
        this->processingTime = processingTime;
        this->index = index;
    }

    static bool decEnqueueTimeComp(const Task& LHS, const Task& RHS){
        return (LHS.enqueueTime > RHS.enqueueTime);
    }

    static bool decProcessingTimeDecIndexComp(const Task& LHS, const Task& RHS){
        return (pair<int, int>{LHS.processingTime, LHS.index} >
                pair<int, int>{RHS.processingTime, RHS.index});
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int N = tasks.size();

        priority_queue<Task, vector<Task>, decltype(&Task::decEnqueueTimeComp)> unavail{Task::decEnqueueTimeComp};
        priority_queue<Task, vector<Task>, decltype(&Task::decProcessingTimeDecIndexComp)> avail{Task::decProcessingTimeDecIndexComp};

        for(int i = 0; i < N; ++i){
            unavail.push(Task{tasks[i][0], tasks[i][1], i});
        }

        int i = 0;
        long long currentTime = 0;
        vector<int> order;
        while(!unavail.empty() || !avail.empty()){
            if(avail.empty()){
                currentTime = max(currentTime, (long long)unavail.top().enqueueTime);
            }
            while(!unavail.empty() && unavail.top().enqueueTime <= currentTime){
                avail.push(unavail.top());
                unavail.pop();
            }
            currentTime += avail.top().processingTime;
            order.push_back(avail.top().index);
            avail.pop();
        }

        return order;
    }
};