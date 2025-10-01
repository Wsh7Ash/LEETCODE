#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

struct Student {
    int id;
    std::string name;
};

struct ExamRecord {
    int student_id;
    std::string subject_name;
};

struct ExamAttendance {
    int student_id;
    std::string student_name;
    std::string subject_name;
    int attended_count;
};

std::vector<ExamAttendance> generateExamReport(
    const std::vector<Student>& students,
    const std::vector<std::string>& subjects,
    const std::vector<ExamRecord>& exams) {
    
    std::vector<ExamAttendance> report;
    
    // Count exams per student per subject
    std::map<std::pair<int, std::string>, int> examCounts;
    for (const auto& exam : exams) {
        examCounts[{exam.student_id, exam.subject_name}]++;
    }
    
    // Generate all combinations (like CROSS JOIN)
    for (const auto& student : students) {
        for (const auto& subject : subjects) {
            ExamAttendance attendance;
            attendance.student_id = student.id;
            attendance.student_name = student.name;
            attendance.subject_name = subject;
            
            // Get count or 0 if no exams (like COALESCE)
            auto key = std::make_pair(student.id, subject);
            attendance.attended_count = examCounts.count(key) ? examCounts[key] : 0;
            
            report.push_back(attendance);
        }
    }
    
    // Sort by student_id, subject_name (like ORDER BY)
    std::sort(report.begin(), report.end(), 
        [](const ExamAttendance& a, const ExamAttendance& b) {
            if (a.student_id != b.student_id) 
                return a.student_id < b.student_id;
            return a.subject_name < b.subject_name;
        });
    
    return report;
}

// Example usage
int main() {
    std::vector<Student> students = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
    std::vector<std::string> subjects = {"Math", "Physics", "Chemistry"};
    std::vector<ExamRecord> exams = {
        {1, "Math"}, {1, "Math"}, {1, "Physics"},
        {2, "Math"}, {3, "Chemistry"}
    };
    
    auto report = generateExamReport(students, subjects, exams);
    
    for (const auto& record : report) {
        std::cout << "Student: " << record.student_name 
                  << " (" << record.student_id << "), "
                  << "Subject: " << record.subject_name
                  << ", Exams Attended: " << record.attended_count << std::endl;
    }
    
    return 0;
}