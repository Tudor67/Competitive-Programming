#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue{
private:
    stack<int> stack_newest_on_top;
    stack<int> stack_oldest_on_top;

    void update_stacks(){
        if(stack_oldest_on_top.empty()){
            while(!stack_newest_on_top.empty()){
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }
    }

public:
    void enqueue(const int& X){
        stack_newest_on_top.push(X);
    }

    void dequeue(){
        update_stacks();
        stack_oldest_on_top.pop();
    }

    int front(){
        update_stacks();
        return stack_oldest_on_top.top();
    }
};

int main() {
    int queries;
    cin >> queries;

    Queue q;
    for(int query = 1; query <= queries; ++query){
        int query_type, x;
        cin >> query_type;

        if(query_type == 1){
            cin >> x;
        }

        if(query_type == 1){
            q.enqueue(x);
        }else if(query_type == 2){
            q.dequeue();
        }else if(query_type == 3){
            cout << q.front() << "\n";
        }
    }

    return 0;
}