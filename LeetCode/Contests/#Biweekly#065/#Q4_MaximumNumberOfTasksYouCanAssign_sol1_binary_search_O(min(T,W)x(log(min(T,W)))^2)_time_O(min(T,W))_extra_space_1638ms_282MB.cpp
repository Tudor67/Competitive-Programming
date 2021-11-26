class Solution {
private:
    bool isValid(vector<int>& tasks, vector<int>& workers, const int& MAX_TASKS, int pills, int strength){
        multiset<int> workersMultiset(workers.end() - MAX_TASKS, workers.end());
        for(int i = MAX_TASKS - 1; i >= 0; --i){
            auto it = workersMultiset.lower_bound(tasks[i]);
            if(it == workersMultiset.end()){
                pills -= 1;
                it = workersMultiset.lower_bound(tasks[i] - strength);
            }
            if(it == workersMultiset.end() || pills < 0){
                return false;
            }
            workersMultiset.erase(it);
        }
        return true;
    }
    
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        const int T = tasks.size();
        const int W = workers.size();
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int l = 0;
        int r = min(T, W);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(tasks, workers, mid, pills, strength)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};

/*
This is a nice problem which can be solved with binary search.

**Main ideas**
* Observation 1
    * Let's say that we have a method `isValid(k)` which returns true if the workers can complete k tasks
(such that all conditions of the problem are satisfied) and false otherwise.
    * The answer of the problem is the `maximum value k` such that `isValid(k)` is `true`.
We can **check all possible values** of k and return the maximum valid k.
Unfortunately this is **too slow**.

* Observation 2
    * If we know that workers can complete k tasks then for sure they can complete k - 1, k - 2, ..., 1 tasks.
If we know that workers cannot complete k tasks then for sure they cannot complete k + 1, k + 2, ... T tasks.
    * If we call `isValid(k)` for all k in range [0, T] then we will have a **sorted sequence** with prefix values `true` and
with suffix (possibly empty) values `false`: [true, true, true, ..., true, true, false, false, ..., false].
    * This means that we can **binary search** the `maximum value k` such that `isValid(k)` is `true`.
This should be **fast enough** to pass all test cases.

**Algorithm**
1. Sort `tasks` (we need this for `isValid(..)` method);
2. Sort `workers` (we need this for `isValid(..)` method);
3. Set the search space of the binary search: `[0, min(T, W)]`;
    * the maximum number of completed tasks is the minimum between number of tasks and number of workers;
    * remember that a worker can complete at most one task;
4. For each range `[l, r]` during the binary search:
    * set `mid =(l + r + 1) / 2`;
    * if `isValid(mid) == true` then we shrink the range to `[mid, r]`;
    else we shrink the range to `[l, mid - 1]`;
    * when we shrink the range `[l, r]` we maintain the following invariant:
         * the left border `l` of the next range satisfies the condition/invariant `isValid(l) == true`;
5. The binary search stops when the search range has a size equal to 1.
   * We can be sure that it represents the maximum number of tasks that can be completed by the workers.
   * Remember that we updated the ranges by moving to the right and maintaining the invariant `isValid(l) == true`.

The most interesting and difficult part of the problem is to implement the method `isValid(k)`. 
We can use the following greedy approach:
* Fix the `easiest k tasks` and `strongest k workers`;
    * this is why we sorted `tasks` and `workers` in the beginning;
    * we use a multiset with the strongest k workers (multiset allows fast search and erase operations);
* `For each task` from the easiest k tasks (starting `from the hardest` and moving `to the easiest`):
    * search the `weakest available worker` that can complete the task `without taking a pill`;
    * if we find such worker
        * complete the task and erase him from the multiset (he is not available anymore);
    * if we do not find such worker:
        * if we do not have any pills then `return false` (we cannot complete the current task);
        * search the `weakest available worker` that can complete the task when he `takes a pill`;
        * if such worker exists then he takes a pill and completes the task (he is erased from the multiset, he is not available anymore)
        otherwise `return false` (we cannot complete the current task);
* If we completed all k tasks then `return true`;

**Complexity analysis**
- Notation: T = tasks.size(), W = workers.size()
- **Time complexity:** `O(Tlog(T) + Wlog(W) + min(T, W) * (log(min(T, W))) ^ 2)`
    * `O(Tlog(T))` for `sort(tasks ..)`;
    * `O(Wlog(W))` for `sort(workers ..)`;
    * `O(min(T, W) * (log(min(T, W))) ^ 2)` for binary search;
        * `log(min(T, W))` calls of `isValid(..)` method;
        * each `isValid(..)` call is `O(min(T, W) * log(min(T, W)))`;
- **Extra-Space complexity:** `O(min(T, W)+log(T)+log(W))`
    * `O(min(T, W))` for `workersMultiset`;
    * `O(log(T))` for recursion stack of `sort(tasks ..)`;
    * `O(log(W))` for recursion stack of `sort(workers ..)`;
    * We modify the input vectors (`tasks` and `workers`) and do not include `O(T + W)` to the extra-space of the solution/algorithm.
*/