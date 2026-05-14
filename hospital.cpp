#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

// Base class for all persons in the hospital
class Person {
protected:
    int id;
    string name;
    int age;
    string gender;
    string phone;
    string address;

public:
    Person() : id(0), age(0) {}
    
    Person(int id, string name, int age, string gender, string phone, string address)
        : id(id), name(name), age(age), gender(gender), phone(phone), address(address) {}

    // Virtual destructor for proper inheritance
    virtual ~Person() {}

    // Pure virtual functions making this an abstract class
    virtual void displayInfo() const = 0;
    virtual string toFileString() const = 0;
    virtual void fromFileString(const string& data) = 0;

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getPhone() const { return phone; }
    string getAddress() const { return address; }

    // Setters
    void setId(int id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGender(const string& gender) { this->gender = gender; }
    void setPhone(const string& phone) { this->phone = phone; }
    void setAddress(const string& address) { this->address = address; }
};

// Patient class inheriting from Person
class Patient : public Person {
private:
    string medicalHistory;
    string currentSymptoms;
    string assignedDoctor;
    string admissionDate;
    bool isAdmitted;

public:
    Patient() : Person(), isAdmitted(false) {}
    
    Patient(int id, string name, int age, string gender, string phone, string address,
            string medicalHistory, string currentSymptoms, string assignedDoctor, 
            string admissionDate, bool isAdmitted)
        : Person(id, name, age, gender, phone, address), 
          medicalHistory(medicalHistory), currentSymptoms(currentSymptoms),
          assignedDoctor(assignedDoctor), admissionDate(admissionDate), 
          isAdmitted(isAdmitted) {}

    // Override virtual functions
    void displayInfo() const override {
        cout << "\n=== PATIENT INFORMATION ===" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Current Symptoms: " << currentSymptoms << endl;
        cout << "Assigned Doctor: " << assignedDoctor << endl;
        cout << "Admission Date: " << admissionDate << endl;
        cout << "Status: " << (isAdmitted ? "Admitted" : "Outpatient") << endl;
        cout << "=========================" << endl;
    }

    string toFileString() const override {
        return to_string(id) + "," + name + "," + to_string(age) + "," + gender + "," +
               phone + "," + address + "," + medicalHistory + "," + currentSymptoms + "," +
               assignedDoctor + "," + admissionDate + "," + (isAdmitted ? "1" : "0");
    }

    void fromFileString(const string& data) override {
        stringstream ss(data);
        string item;
        
        getline(ss, item, ','); id = stoi(item);
        getline(ss, name, ',');
        getline(ss, item, ','); age = stoi(item);
        getline(ss, gender, ',');
        getline(ss, phone, ',');
        getline(ss, address, ',');
        getline(ss, medicalHistory, ',');
        getline(ss, currentSymptoms, ',');
        getline(ss, assignedDoctor, ',');
        getline(ss, admissionDate, ',');
        getline(ss, item, ','); isAdmitted = (item == "1");
    }

    // Patient-specific methods
    void setMedicalHistory(const string& history) { medicalHistory = history; }
    void setCurrentSymptoms(const string& symptoms) { currentSymptoms = symptoms; }
    void setAssignedDoctor(const string& doctor) { assignedDoctor = doctor; }
    void setAdmissionDate(const string& date) { admissionDate = date; }
    void setAdmissionStatus(bool status) { isAdmitted = status; }

    string getMedicalHistory() const { return medicalHistory; }
    string getCurrentSymptoms() const { return currentSymptoms; }
    string getAssignedDoctor() const { return assignedDoctor; }
    string getAdmissionDate() const { return admissionDate; }
    bool getAdmissionStatus() const { return isAdmitted; }
};

// Doctor class inheriting from Person
class Doctor : public Person {
private:
    string specialization;
    string degree;
    int experience;
    string department;
    double consultationFee;
    string schedule;

public:
    Doctor() : Person(), experience(0), consultationFee(0.0) {}
    
    Doctor(int id, string name, int age, string gender, string phone, string address,
           string specialization, string degree, int experience, string department,
           double consultationFee, string schedule)
        : Person(id, name, age, gender, phone, address),
          specialization(specialization), degree(degree), experience(experience),
          department(department), consultationFee(consultationFee), schedule(schedule) {}

    void displayInfo() const override {
        cout << "\n=== DOCTOR INFORMATION ===" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: Dr. " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Degree: " << degree << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Department: " << department << endl;
        cout << "Consultation Fee: $" << fixed << setprecision(2) << consultationFee << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "========================" << endl;
    }

    string toFileString() const override {
        return to_string(id) + "," + name + "," + to_string(age) + "," + gender + "," +
               phone + "," + address + "," + specialization + "," + degree + "," +
               to_string(experience) + "," + department + "," + to_string(consultationFee) + "," + schedule;
    }

    void fromFileString(const string& data) override {
        stringstream ss(data);
        string item;
        
        getline(ss, item, ','); id = stoi(item);
        getline(ss, name, ',');
        getline(ss, item, ','); age = stoi(item);
        getline(ss, gender, ',');
        getline(ss, phone, ',');
        getline(ss, address, ',');
        getline(ss, specialization, ',');
        getline(ss, degree, ',');
        getline(ss, item, ','); experience = stoi(item);
        getline(ss, department, ',');
        getline(ss, item, ','); consultationFee = stod(item);
        getline(ss, schedule, ',');
    }

    // Doctor-specific getters and setters
    string getSpecialization() const { return specialization; }
    string getDegree() const { return degree; }
    int getExperience() const { return experience; }
    string getDepartment() const { return department; }
    double getConsultationFee() const { return consultationFee; }
    string getSchedule() const { return schedule; }
};

// Staff class inheriting from Person
class Staff : public Person {
private:
    string position;
    string department;
    double salary;
    string joiningDate;
    string shift;

public:
    Staff() : Person(), salary(0.0) {}
    
    Staff(int id, string name, int age, string gender, string phone, string address,
          string position, string department, double salary, string joiningDate, string shift)
        : Person(id, name, age, gender, phone, address),
          position(position), department(department), salary(salary),
          joiningDate(joiningDate), shift(shift) {}

    void displayInfo() const override {
        cout << "\n=== STAFF INFORMATION ===" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
        cout << "Joining Date: " << joiningDate << endl;
        cout << "Shift: " << shift << endl;
        cout << "========================" << endl;
    }

    string toFileString() const override {
        return to_string(id) + "," + name + "," + to_string(age) + "," + gender + "," +
               phone + "," + address + "," + position + "," + department + "," +
               to_string(salary) + "," + joiningDate + "," + shift;
    }

    void fromFileString(const string& data) override {
        stringstream ss(data);
        string item;
        
        getline(ss, item, ','); id = stoi(item);
        getline(ss, name, ',');
        getline(ss, item, ','); age = stoi(item);
        getline(ss, gender, ',');
        getline(ss, phone, ',');
        getline(ss, address, ',');
        getline(ss, position, ',');
        getline(ss, department, ',');
        getline(ss, item, ','); salary = stod(item);
        getline(ss, joiningDate, ',');
        getline(ss, shift, ',');
    }

    // Staff-specific getters
    string getPosition() const { return position; }
    string getDepartment() const { return department; }
    double getSalary() const { return salary; }
    string getJoiningDate() const { return joiningDate; }
    string getShift() const { return shift; }
};

// Appointment class
class Appointment {
private:
    int appointmentId;
    int patientId;
    int doctorId;
    string date;
    string time;
    string status;
    string purpose;

public:
    Appointment() : appointmentId(0), patientId(0), doctorId(0) {}
    
    Appointment(int appointmentId, int patientId, int doctorId, string date, 
                string time, string status, string purpose)
        : appointmentId(appointmentId), patientId(patientId), doctorId(doctorId),
          date(date), time(time), status(status), purpose(purpose) {}

    void displayInfo() const {
        cout << "\n=== APPOINTMENT INFORMATION ===" << endl;
        cout << "Appointment ID: " << appointmentId << endl;
        cout << "Patient ID: " << patientId << endl;
        cout << "Doctor ID: " << doctorId << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Status: " << status << endl;
        cout << "Purpose: " << purpose << endl;
        cout << "==============================" << endl;
    }

    string toFileString() const {
        return to_string(appointmentId) + "," + to_string(patientId) + "," + 
               to_string(doctorId) + "," + date + "," + time + "," + status + "," + purpose;
    }

    void fromFileString(const string& data) {
        stringstream ss(data);
        string item;
        
        getline(ss, item, ','); appointmentId = stoi(item);
        getline(ss, item, ','); patientId = stoi(item);
        getline(ss, item, ','); doctorId = stoi(item);
        getline(ss, date, ',');
        getline(ss, time, ',');
        getline(ss, status, ',');
        getline(ss, purpose, ',');
    }

    // Getters
    int getAppointmentId() const { return appointmentId; }
    int getPatientId() const { return patientId; }
    int getDoctorId() const { return doctorId; }
    string getDate() const { return date; }
    string getTime() const { return time; }
    string getStatus() const { return status; }
    string getPurpose() const { return purpose; }

    // Setters
    void setStatus(const string& newStatus) { status = newStatus; }
};

// Template class for file operations (Generic Programming)
template<typename T>
class FileManager {
private:
    string filename;

public:
    FileManager(const string& filename) : filename(filename) {}

    // Save data to file
    bool saveToFile(const vector<T>& data) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Cannot open file " << filename << " for writing." << endl;
            return false;
        }

        for (const auto& item : data) {
            file << item.toFileString() << endl;
        }
        file.close();
        return true;
    }

    // Load data from file
    bool loadFromFile(vector<T>& data) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Warning: Cannot open file " << filename << " for reading. File may not exist." << endl;
            return false;
        }

        data.clear();
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                T item;
                item.fromFileString(line);
                data.push_back(item);
            }
        }
        file.close();
        return true;
    }
};

// Hospital Management System class (Composition and Aggregation)
class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Staff> staff;
    vector<Appointment> appointments;
    
    // File managers for each type
    FileManager<Patient> patientFileManager;
    FileManager<Doctor> doctorFileManager;
    FileManager<Staff> staffFileManager;
    FileManager<Appointment> appointmentFileManager;

public:
    HospitalManagementSystem() 
        : patientFileManager("patients.txt"),
          doctorFileManager("doctors.txt"),
          staffFileManager("staff.txt"),
          appointmentFileManager("appointments.txt") {
        loadAllData();
    }

    ~HospitalManagementSystem() {
        saveAllData();
    }

    // Load all data from files
    void loadAllData() {
        patientFileManager.loadFromFile(patients);
        doctorFileManager.loadFromFile(doctors);
        staffFileManager.loadFromFile(staff);
        appointmentFileManager.loadFromFile(appointments);
    }

    // Save all data to files
    void saveAllData() {
        patientFileManager.saveToFile(patients);
        doctorFileManager.saveToFile(doctors);
        staffFileManager.saveToFile(staff);
        appointmentFileManager.saveToFile(appointments);
    }

    // Patient CRUD operations
    void addPatient() {
        Patient patient;
        int id, age;
        string name, gender, phone, address, medicalHistory, symptoms, doctor, date;
        bool admitted;
        
        cout << "\n=== ADD NEW PATIENT ===" << endl;
        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();
        
        // Check if ID already exists
        for (const auto& p : patients) {
            if (p.getId() == id) {
                cout << "Error: Patient with ID " << id << " already exists!" << endl;
                return;
            }
        }
        
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Medical History: ";
        getline(cin, medicalHistory);
        cout << "Enter Current Symptoms: ";
        getline(cin, symptoms);
        cout << "Enter Assigned Doctor: ";
        getline(cin, doctor);
        cout << "Enter Admission Date: ";
        getline(cin, date);
        cout << "Is patient admitted? (1 for Yes, 0 for No): ";
        cin >> admitted;
        
        Patient newPatient(id, name, age, gender, phone, address, 
                          medicalHistory, symptoms, doctor, date, admitted);
        patients.push_back(newPatient);
        
        cout << "Patient added successfully!" << endl;
        saveAllData();
    }

    void viewAllPatients() {
        if (patients.empty()) {
            cout << "No patients found." << endl;
            return;
        }
        
        cout << "\n=== ALL PATIENTS ===" << endl;
        for (const auto& patient : patients) {
            patient.displayInfo();
        }
    }

    void searchPatient() {
        if (patients.empty()) {
            cout << "No patients found." << endl;
            return;
        }
        
        int id;
        cout << "Enter Patient ID to search: ";
        cin >> id;
        
        auto it = find_if(patients.begin(), patients.end(),
                         [id](const Patient& p) { return p.getId() == id; });
        
        if (it != patients.end()) {
            it->displayInfo();
        } else {
            cout << "Patient with ID " << id << " not found." << endl;
        }
    }

    void updatePatient() {
        if (patients.empty()) {
            cout << "No patients found." << endl;
            return;
        }
        
        int id;
        cout << "Enter Patient ID to update: ";
        cin >> id;
        cin.ignore();
        
        auto it = find_if(patients.begin(), patients.end(),
                         [id](const Patient& p) { return p.getId() == id; });
        
        if (it != patients.end()) {
            string symptoms, doctor;
            bool admitted;
            
            cout << "Current patient information:" << endl;
            it->displayInfo();
            
            cout << "\nEnter new symptoms: ";
            getline(cin, symptoms);
            cout << "Enter assigned doctor: ";
            getline(cin, doctor);
            cout << "Is patient admitted? (1 for Yes, 0 for No): ";
            cin >> admitted;
            
            it->setCurrentSymptoms(symptoms);
            it->setAssignedDoctor(doctor);
            it->setAdmissionStatus(admitted);
            
            cout << "Patient updated successfully!" << endl;
            saveAllData();
        } else {
            cout << "Patient with ID " << id << " not found." << endl;
        }
    }

    void deletePatient() {
        if (patients.empty()) {
            cout << "No patients found." << endl;
            return;
        }
        
        int id;
        cout << "Enter Patient ID to delete: ";
        cin >> id;
        
        auto it = find_if(patients.begin(), patients.end(),
                         [id](const Patient& p) { return p.getId() == id; });
        
        if (it != patients.end()) {
            cout << "Patient found:" << endl;
            it->displayInfo();
            
            char confirm;
            cout << "Are you sure you want to delete this patient? (y/n): ";
            cin >> confirm;
            
            if (confirm == 'y' || confirm == 'Y') {
                patients.erase(it);
                cout << "Patient deleted successfully!" << endl;
                saveAllData();
            } else {
                cout << "Deletion cancelled." << endl;
            }
        } else {
            cout << "Patient with ID " << id << " not found." << endl;
        }
    }

    // Doctor CRUD operations
    void addDoctor() {
        Doctor doctor;
        int id, age, experience;
        string name, gender, phone, address, specialization, degree, department, schedule;
        double fee;
        
        cout << "\n=== ADD NEW DOCTOR ===" << endl;
        cout << "Enter Doctor ID: ";
        cin >> id;
        cin.ignore();
        
        // Check if ID already exists
        for (const auto& d : doctors) {
            if (d.getId() == id) {
                cout << "Error: Doctor with ID " << id << " already exists!" << endl;
                return;
            }
        }
        
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        cout << "Enter Degree: ";
        getline(cin, degree);
        cout << "Enter Experience (years): ";
        cin >> experience;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Consultation Fee: ";
        cin >> fee;
        cin.ignore();
        cout << "Enter Schedule: ";
        getline(cin, schedule);
        
        Doctor newDoctor(id, name, age, gender, phone, address, 
                        specialization, degree, experience, department, fee, schedule);
        doctors.push_back(newDoctor);
        
        cout << "Doctor added successfully!" << endl;
        saveAllData();
    }

    void viewAllDoctors() {
        if (doctors.empty()) {
            cout << "No doctors found." << endl;
            return;
        }
        
        cout << "\n=== ALL DOCTORS ===" << endl;
        for (const auto& doctor : doctors) {
            doctor.displayInfo();
        }
    }

    // Staff CRUD operations
    void addStaff() {
        Staff staffMember;
        int id, age;
        string name, gender, phone, address, position, department, joiningDate, shift;
        double salary;
        
        cout << "\n=== ADD NEW STAFF ===" << endl;
        cout << "Enter Staff ID: ";
        cin >> id;
        cin.ignore();
        
        // Check if ID already exists
        for (const auto& s : staff) {
            if (s.getId() == id) {
                cout << "Error: Staff with ID " << id << " already exists!" << endl;
                return;
            }
        }
        
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Position: ";
        getline(cin, position);
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore();
        cout << "Enter Joining Date: ";
        getline(cin, joiningDate);
        cout << "Enter Shift: ";
        getline(cin, shift);
        
        Staff newStaff(id, name, age, gender, phone, address, 
                      position, department, salary, joiningDate, shift);
        staff.push_back(newStaff);
        
        cout << "Staff member added successfully!" << endl;
        saveAllData();
    }

    void viewAllStaff() {
        if (staff.empty()) {
            cout << "No staff members found." << endl;
            return;
        }
        
        cout << "\n=== ALL STAFF ===" << endl;
        for (const auto& staffMember : staff) {
            staffMember.displayInfo();
        }
    }

    // Appointment management
    void scheduleAppointment() {
        int appointmentId, patientId, doctorId;
        string date, time, purpose;
        
        cout << "\n=== SCHEDULE APPOINTMENT ===" << endl;
        cout << "Enter Appointment ID: ";
        cin >> appointmentId;
        cin.ignore();
        
        cout << "Enter Patient ID: ";
        cin >> patientId;
        cout << "Enter Doctor ID: ";
        cin >> doctorId;
        cin.ignore();
        
        // Verify patient and doctor exist
        bool patientExists = any_of(patients.begin(), patients.end(),
                                   [patientId](const Patient& p) { return p.getId() == patientId; });
        bool doctorExists = any_of(doctors.begin(), doctors.end(),
                                  [doctorId](const Doctor& d) { return d.getId() == doctorId; });
        
        if (!patientExists) {
            cout << "Error: Patient with ID " << patientId << " not found!" << endl;
            return;
        }
        if (!doctorExists) {
            cout << "Error: Doctor with ID " << doctorId << " not found!" << endl;
            return;
        }
        
        cout << "Enter Date (DD/MM/YYYY): ";
        getline(cin, date);
        cout << "Enter Time (HH:MM): ";
        getline(cin, time);
        cout << "Enter Purpose: ";
        getline(cin, purpose);
        
        Appointment newAppointment(appointmentId, patientId, doctorId, 
                                 date, time, "Scheduled", purpose);
        appointments.push_back(newAppointment);
        
        cout << "Appointment scheduled successfully!" << endl;
        saveAllData();
    }

    void viewAllAppointments() {
        if (appointments.empty()) {
            cout << "No appointments found." << endl;
            return;
        }
        
        cout << "\n=== ALL APPOINTMENTS ===" << endl;
        for (const auto& appointment : appointments) {
            appointment.displayInfo();
        }
    }

    // Main menu
    void displayMainMenu() {
        cout << "\n" << string(50, '=') << endl;
        cout << "        QMC HOSPITAL MANAGEMENT SYSTEM" << endl;
        cout << string(50, '=') << endl;
        cout << "1. Patient Management" << endl;
        cout << "2. Doctor Management" << endl;
        cout << "3. Staff Management" << endl;
        cout << "4. Appointment Management" << endl;
        cout << "5. Reports" << endl;
        cout << "6. Exit" << endl;
        cout << string(50, '=') << endl;
        cout << "Enter your choice: ";
    }

    void displayPatientMenu() {
        cout << "\n=== PATIENT MANAGEMENT ===" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. View All Patients" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Update Patient" << endl;
        cout << "5. Delete Patient" << endl;
        cout << "6. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }

    void displayDoctorMenu() {
        cout << "\n=== DOCTOR MANAGEMENT ===" << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. View All Doctors" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }

    void displayStaffMenu() {
        cout << "\n=== STAFF MANAGEMENT ===" << endl;
        cout << "1. Add Staff" << endl;
        cout << "2. View All Staff" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }

    void displayAppointmentMenu() {
        cout << "\n=== APPOINTMENT MANAGEMENT ===" << endl;
        cout << "1. Schedule Appointment" << endl;
        cout << "2. View All Appointments" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }

    void generateReports() {
        cout << "\n=== HOSPITAL REPORTS ===" << endl;
        cout << "Total Patients: " << patients.size() << endl;
        cout << "Total Doctors: " << doctors.size() << endl;
        cout << "Total Staff: " << staff.size() << endl;
        cout << "Total Appointments: " << appointments.size() << endl;
        
        // Count admitted patients
        int admittedPatients = count_if(patients.begin(), patients.end(),
                                       [](const Patient& p) { return p.getAdmissionStatus(); });
        cout << "Admitted Patients: " << admittedPatients << endl;
        cout << "Outpatients: " << patients.size() - admittedPatients << endl;
    }

    void run() {
        int choice;
        
        while (true) {
            displayMainMenu();
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    int patientChoice;
                    do {
                        displayPatientMenu();
                        cin >> patientChoice;
                        
                        switch (patientChoice) {
                            case 1: addPatient(); break;
                            case 2: viewAllPatients(); break;
                            case 3: searchPatient(); break;
                            case 4: updatePatient(); break;
                            case 5: deletePatient(); break;
                            case 6: break;
                            default: cout << "Invalid choice!" << endl;
                        }
                    } while (patientChoice != 6);
                    break;
                }
                case 2: {
                    int doctorChoice;
                    do {
                        displayDoctorMenu();
                        cin >> doctorChoice;
                        
                        switch (doctorChoice) {
                            case 1: addDoctor(); break;
                            case 2: viewAllDoctors(); break;
                            case 3: break;
                            default: cout << "Invalid choice!" << endl;
                        }
                    } while (doctorChoice != 3);
                    break;
                }
                case 3: {
                    int staffChoice;
                    do {
                        displayStaffMenu();
                        cin >> staffChoice;
                        
                        switch (staffChoice) {
                            case 1: addStaff(); break;
                            case 2: viewAllStaff(); break;
                            case 3: break;
                            default: cout << "Invalid choice!" << endl;
                        }
                    } while (staffChoice != 3);
                    break;
                }
                case 4: {
                    int appointmentChoice;
                    do {
                        displayAppointmentMenu();
                        cin >> appointmentChoice;
                        
                        switch (appointmentChoice) {
                            case 1: scheduleAppointment(); break;
                            case 2: viewAllAppointments(); break;
                            case 3: break;
                            default: cout << "Invalid choice!" << endl;
                        }
                    } while (appointmentChoice != 3);
                    break;
                }
                case 5:
                    generateReports();
                    break;
                case 6:
                    cout << "\nThank you for using QMC Hospital Management System!" << endl;
                    cout << "Goodbye!" << endl;
                    saveAllData(); // Save data before exiting
                    return;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

// Main function
int main() {
    cout << "\n" << string(60, '*') << endl;
    cout << "           WELCOME TO QMC HOSPITAL" << endl;
    cout << "         MANAGEMENT SYSTEM v1.0" << endl;
    cout << string(60, '*') << endl;
    cout << "\nInitializing system..." << endl;
    
    try {
        HospitalManagementSystem hospital;
        hospital.run();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}