class Solution {
public:
    double average(vector<int>& salary) {
        const int N = salary.size();
        int minSalary = *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());
        int salarySum = accumulate(salary.begin(), salary.end(), 0);
        return (salarySum - minSalary - maxSalary) / (N - 2.0);
    }
};