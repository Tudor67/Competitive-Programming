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

    static bool incEnqueueTimeComp(const Task& LHS, const Task& RHS){
        return (LHS.enqueueTime < RHS.enqueueTime);
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

        vector<Task> sortedTasks;
        sortedTasks.reserve(N);
        for(int i = 0; i < N; ++i){
            sortedTasks.push_back(Task{tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end(), Task::incEnqueueTimeComp);

        vector<int> order;
        priority_queue<Task, vector<Task>, decltype(&Task::decProcessingTimeDecIndexComp)> minHeap{Task::decProcessingTimeDecIndexComp};

        int i = 0;
        long long currentTime = 0;
        while(i < N || !minHeap.empty()){
            if(minHeap.empty()){
                currentTime = max(currentTime, (long long)sortedTasks[i].enqueueTime);
            }
            while(i < N && sortedTasks[i].enqueueTime <= currentTime){
                minHeap.push(sortedTasks[i]);
                i += 1;
            }
            currentTime += minHeap.top().processingTime;
            order.push_back(minHeap.top().index);
            minHeap.pop();
        }

        return order;
    }
};