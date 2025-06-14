/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    public:
        int dfs(int id,unordered_map<int, Employee*>& empMap){
            Employee* emp = empMap[id];
            int total = emp->importance;
            for(int subId : emp->subordinates){
                total += dfs(subId, empMap);
            }
            return total;
        }
    
        int getImportance(vector<Employee*> employees, int id) {
            unordered_map<int, Employee*> empMap;
            for(Employee* emp : employees){
                empMap[emp->id] = emp;
            }
            return dfs(id, empMap);
        }
    };