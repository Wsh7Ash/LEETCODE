#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct Patient {
    int patient_id;
    string patient_name;
    string conditions;
};

vector<Patient> findDiabeticPatients(vector<Patient> patients) {
    vector<Patient> result;
    
    // Regex pattern to match conditions starting with DIAB1 or containing space followed by DIAB1
    regex pattern("(^|.*\\s)DIAB1.*");
    
    for (const auto& patient : patients) {
        if (regex_match(patient.conditions, pattern)) {
            result.push_back(patient);
        }
    }
    
    return result;
}

// Alternative implementation using string methods
vector<Patient> findDiabeticPatientsStringMethod(vector<Patient> patients) {
    vector<Patient> result;
    
    for (const auto& patient : patients) {
        string conditions = patient.conditions;
        
        // Check if conditions start with DIAB1 or contain space followed by DIAB1
        if (conditions.find("DIAB1") == 0 || 
            conditions.find(" DIAB1") != string::npos) {
            result.push_back(patient);
        }
    }
    
    return result;
}

// Example usage
int main() {
    vector<Patient> patients = {
        {1, "Daniel", "DIAB1 YFEV COUGH"},
        {2, "Alice", "ACNE DIAB1"},
        {3, "Bob", "DIAB100"},
        {4, "George", "ACNE DIAB1 SUGAR"},
        {5, "Alain", "DIAB1"}
    };
    
    vector<Patient> diabeticPatients = findDiabeticPatients(patients);
    
    cout << "patient_id | patient_name | conditions" << endl;
    cout << "--------------------------------------" << endl;
    for (const auto& patient : diabeticPatients) {
        cout << patient.patient_id << " | " 
             << patient.patient_name << " | " 
             << patient.conditions << endl;
    }
    
    return 0;
}