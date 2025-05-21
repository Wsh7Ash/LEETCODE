class Solution {
    public:
        int scheduleCourse(vector<vector<int>>& courses) {
            sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
                return a[1] < b[1];
            });
            priority_queue<int> maxHeap;
            int curTime = 0;
            for(auto& course : courses){
                int duration = course[0];
                int lastDay = course[1];
    
                if(curTime + duration <= lastDay){
                    curTime += duration;
                    maxHeap.push(duration);
                }else if(!maxHeap.empty() && maxHeap.top() > duration){
                    curTime += duration - maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(duration);
                }
            }
            return maxHeap.size();
        }
    };