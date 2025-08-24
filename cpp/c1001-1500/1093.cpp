class Solution {
    public:
        vector<double> sampleStats(vector<int>& count) {
            double min_val = -1.0;
            double max_val = -1.0;
            double total_sum = 0.0;
            long long total_count = 0;
            int mode = 0;
            int max_freq = 0;
    
            for(int i = 0; i < 256; i++){
                if(count[i] > 0){
                    if(min_val < 0) min_val = i;
                    max_val = i;
                    total_sum += (double)i * count[i];
                    total_count += count[i];
                    if(count[i] > max_freq){
                        max_freq = count[i];
                        mode = i;
                    }
                }
            }
            double mean = total_sum / total_count;
    
            double median = 0.0;
            long long mid1 = (total_count + 1) /2;
            long long mid2 = (total_count + 2) /2;
            long long cumulative = 0;
            int first_median_val = -1, second_median_val = -1;
            for(int i = 0; i < 256; i++){
                if(count[i] == 0) continue;
                cumulative += count[i];
                if(first_median_val == -1 && cumulative >= mid1){
                    first_median_val = i;
                }
    
                if(cumulative >= mid2){
                    second_median_val = i;
                    break;
                }
            }
            if(total_count % 2 == 0){
                median = (first_median_val + second_median_val) / 2.0;
            }else{
                median = first_median_val;
            }
    
            return {min_val, max_val, mean, median, (double)mode};
        }
    };