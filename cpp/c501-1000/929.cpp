class Solution {
    public:
        int numUniqueEmails(vector<string>& emails) {
            unordered_set<string> uniqueEmails;
            for(const string& email : emails){
                size_t atPos = email.find('@');
                string localName = email.substr(0, atPos);
                string domainName = email.substr(atPos + 1);
    
                string processedLocal = "";
    
                for(char c : localName){
                    if(c == '+'){
                        break;
                    }
                    if(c != '.'){
                        processedLocal += c;
                    }
                }
    
                string normalizedEmail = processedLocal + '@' + domainName;
                uniqueEmails.insert(normalizedEmail);
            }
            return uniqueEmails.size();
        }
    };