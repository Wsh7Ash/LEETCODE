class Solution {
    public:
        vector<int> threeEqualParts(vector<int>& arr) {
            int n = arr.size();
            int count_ones = 0;
            
            for(int num : arr) {
                if(num == 1) count_ones++;
            }
            
            if(count_ones % 3 != 0) return {-1, -1};
            
            int ones_per_part = count_ones / 3;
            
            if(ones_per_part == 0) return {0, n - 1};
            
            int first_start = -1, second_start = -1, third_start = -1;
            int ones_seen = 0;
            
            for(int i = 0; i < n; i++) {
                if(arr[i] == 1) {
                    ones_seen++;
                    if(ones_seen == 1) {
                        first_start = i;
                    } else if(ones_seen == ones_per_part + 1) {
                        second_start = i;
                    } else if(ones_seen == 2 * ones_per_part + 1) {
                        third_start = i;
                        break;
                    }
                }
            }
            
            int trailing_zeros = 0;
            for(int i = n - 1; i >= 0 && arr[i] == 0; i--) {
                trailing_zeros++;
            }
            
            int first_end = first_start + ones_per_part - 1;
            int second_end = second_start + ones_per_part - 1;
            
            while(first_end + 1 < n && arr[first_end + 1] == 0) first_end++;
            while(second_end + 1 < n && arr[second_end + 1] == 0) second_end++;
            
            int third_length = n - third_start;
            
            if(first_start + third_length > second_start || 
               second_start + third_length > third_start) {
                return {-1, -1};
            }
            
            for(int i = 0; i < third_length; i++) {
                if(arr[first_start + i] != arr[third_start + i] ||
                   arr[second_start + i] != arr[third_start + i]) {
                    return {-1, -1};
                }
            }
            
            return {first_start + third_length - 1, second_start + third_length};
        }
    };