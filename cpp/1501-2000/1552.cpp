class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1; 
        int right = position.back() -  position[0];

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canPlaceBalls(position, m, mid)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }

private:
    bool canPlaceBalls(vector<int>& position, int m, int midDistance){
        int count = 1;
        int lastPosition = position[0];

        for(int i = 1; i < position.size(); i++){
            if(position[i] - lastPosition >= midDistance){
                count++;
                lastPosition = position[i];
                if(count >= m){
                    return true;
                }
            }
        }
        return count >= m;
    }
};