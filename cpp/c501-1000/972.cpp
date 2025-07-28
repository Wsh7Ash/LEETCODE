#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Solution {
public:
    bool isRationalEqual(string s, string t) {
        auto parse = [](const string& num) -> double {
            size_t dot_pos = num.find('.');
            size_t open_par = num.find('(');
            size_t close_par = num.find(')');

            string integer_part;
            string non_repeating;
            string repeating;

            if (dot_pos == string::npos) {
                integer_part = num;
            } else {
                integer_part = num.substr(0, dot_pos);
                if (open_par == string::npos) {
                    non_repeating = num.substr(dot_pos + 1);
                } else {
                    non_repeating = num.substr(dot_pos + 1, open_par - dot_pos - 1);
                    repeating = num.substr(open_par + 1, close_par - open_par - 1);
                }
            }

            double value = stod(integer_part);

            if (!non_repeating.empty()) {
                string frac_str = "0." + non_repeating;
                double frac = stod(frac_str);
                value += frac;
            }

            if (!repeating.empty()) {
                string rep_str = repeating;
                double rep_value = stod(rep_str);
                int m = rep_str.size();
                double denominator = pow(10, m) - 1;
                double repeating_part = rep_value / denominator;
                int n = non_repeating.size();
                repeating_part /= pow(10, n);
                value += repeating_part;
            }

            return value;
        };

        double s_val = parse(s);
        double t_val = parse(t);

        const double eps = 1e-12;
        return abs(s_val - t_val) < eps;
    }
};