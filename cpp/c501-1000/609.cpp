class Solution {
    public:
        vector<vector<string>> findDuplicate(vector<string>& paths) {
            unordered_map<string, vector<string>> content_map;
    
            for(string& path : paths){
                size_t space_pos = path.find(' ');
                string dir = path.substr(0, space_pos);
                string files_part = path.substr(space_pos + 1);
    
                size_t start = 0;
                while(start < files_part.length()){
                    size_t left_par = files_part.find('(', start);
                    string file_name = files_part.substr(start, left_par - start);
                    size_t right_par = files_part.find(')', left_par);
                    string content = files_part.substr(left_par + 1, right_par - left_par - 1);
                    string full_path = dir + "/" + file_name;
                    content_map[content].push_back(full_path);
                    start = right_par + 2;
                }
            }
            vector<vector<string>> res;
            for(auto& pair : content_map){
                if(pair.second.size() >= 2){
                    res.push_back(pair.second);
                }
            }
            return res;
        }
    };