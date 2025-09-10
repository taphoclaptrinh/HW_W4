#include <bits/stdc++.h>
using namespace std;

// -------------------- class Patient --------------------
class Patient {
private:
    string name;
    int id;
    int age;

public:
    Patient() {}

    // Setter
    void setName(string n) { name = n; }
    void setId(int i) { id = i; }
    void setAge(int a) { age = a; }

    // Getter
    string getName() const { return name; }
    int getId() const { return id; }
    int getAge() const { return age; }

    virtual void scheduleAppointment() {
        cout << "Dat lich cho benh nhan thuong: " << name << endl;
    }

    virtual void displayInfo() const {
        cout << "Benh nhan: " << name << ", ID: " << id << ", Tuoi: " << age << endl;
    }

    virtual ~Patient() {}
};

// -------------------- class ChronicPatient --------------------
class ChronicPatient : public Patient {
private:
    string condition;
    string lastCheckupDate;

public:
    ChronicPatient() {}

    // Setter
    void setCondition(string c) { condition = c; }
    void setLastCheckupDate(string d) { lastCheckupDate = d; }

    // Getter
    string getCondition() const { return condition; }
    string getLastCheckupDate() const { return lastCheckupDate; }

    void scheduleAppointment() override {
        cout << "Dat lich dinh ky cho benh nhan man tinh: " << getName()
             << " (Benh: " << condition << ")" << endl;
    }

    void displayInfo() const override {
        Patient::displayInfo();
        cout << "Benh nen: " << condition << ", Lan kham gan nhat: " << lastCheckupDate << endl;
    }
};

// -------------------- class Doctor --------------------
class Doctor {
private:
    string name;
    int id;
    string specialty;

public:
    Doctor() {}

    // Setter
    void setName(string n) { name = n; }
    void setId(int i) { id = i; }
    void setSpecialty(string s) { specialty = s; }

    // Getter
    string getName() const { return name; }
    int getId() const { return id; }
    string getSpecialty() const { return specialty; }

    void displayInfo() const {
        cout << "Bac si: " << name << ", ID: " << id << ", Chuyen khoa: " << specialty << endl;
    }
};

// -------------------- class Appointment --------------------
class Appointment {
private:
    int appointmentId;
    string date;
    string time;
    string reason;
    string status;
    Patient* patient;
    Doctor* doctor;

public:
    Appointment() : status("Scheduled") {}
    
	// Getter
	int getAppointmentId() const { return appointmentId; }
	string getDate() const { return date; }
	string getTime() const { return time; }
	string getReason() const { return reason; }
	string getStatus() const { return status; }
	Patient* getPatient() const { return patient; }
	Doctor* getDoctor() const { return doctor; }


    // Setter
    void setAppointmentId(int id) { appointmentId = id; }
    void setDate(string d) { date = d; }
    void setTime(string t) { time = t; }
    void setReason(string r) { reason = r; }
    void setPatient(Patient* p) { patient = p; }
    void setDoctor(Doctor* d) { doctor = d; }

    void setStatus(string newStatus) { status = newStatus; }

    void displayInfo() const {
        cout << "Lich hen ID: " << appointmentId << ", Ngay: " << date
             << ", Gio: " << time << ", Ly do: " << reason
             << ", Trang thai: " << status << endl;
        if (patient) patient->displayInfo();
        if (doctor) doctor->displayInfo();
    }
};

// -------------------- Main --------------------
int main() {
    vector<Doctor*> doctors;
    vector<Patient*> patients;
    vector<Appointment*> appointments;

    // ------------------ D? LI?U M?U ------------------
    // B?nh nhân thu?ng
    Patient* bnThuong = new Patient();
    bnThuong->setName("Nguyen Van A");
    bnThuong->setId(101);
    bnThuong->setAge(35);
    patients.push_back(bnThuong);

    // B?nh nhân mãn tính
    ChronicPatient* bnManTinh = new ChronicPatient();
    bnManTinh->setName("Tran Thi B");
    bnManTinh->setId(102);
    bnManTinh->setAge(60);
    bnManTinh->setCondition("Tieu duong");
    bnManTinh->setLastCheckupDate("01/07/2025");
    patients.push_back(bnManTinh);

    // Bác si chuyên khoa
    Doctor* bs1 = new Doctor();
    bs1->setName("Dr. Le Van C");
    bs1->setId(201);
    bs1->setSpecialty("Noi khoa");
    doctors.push_back(bs1);

    Doctor* bs2 = new Doctor();
    bs2->setName("Dr. Pham Thi D");
    bs2->setId(202);
    bs2->setSpecialty("Nhi khoa");
    doctors.push_back(bs2);

    Doctor* bs3 = new Doctor();
    bs3->setName("Dr. Hoang Van E");
    bs3->setId(203);
    bs3->setSpecialty("Da lieu");
    doctors.push_back(bs3);

    Doctor* bs4 = new Doctor();
    bs4->setName("Dr. Nguyen Thi F");
    bs4->setId(204);
    bs4->setSpecialty("Tim mach");
    doctors.push_back(bs4);

    int choice;

    do {
        cout << "\n=== MENU PHONG KHAM ===\n";
        cout << "1. Them bac si\n";
        cout << "2. Them benh nhan thuong\n";
        cout << "3. Them benh nhan man tinh\n";
        cout << "4. Xem danh sach bac si\n";
        cout << "5. Xem danh sach benh nhan\n";
        cout << "6. Lap lich hen\n";
        cout << "7. Huy lich hen\n";
        cout << "8. Xem danh sach lich hen\n";
        cout << "9. Xem lich su kham cua benh nhan\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Doctor* d = new Doctor();
            string name, specialty;
            int id;

            cout << "Nhap ten bac si: "; getline(cin, name);
            cout << "Nhap ID: "; cin >> id;
            cin.ignore();
            cout << "Nhap chuyen khoa: "; getline(cin, specialty);

            d->setName(name);
            d->setId(id);
            d->setSpecialty(specialty);

            doctors.push_back(d);
            cout << "Da them bac si.\n";
        }
        else if (choice == 2 || choice == 3) {
            Patient* p;
            if (choice == 2) {
                p = new Patient();
            } else {
                p = new ChronicPatient();
            }

            string name;
            int id, age;

            cout << "Nhap ten benh nhan: "; getline(cin, name);
            cout << "Nhap ID: "; cin >> id;
            cout << "Nhap tuoi: "; cin >> age;
            cin.ignore();

            p->setName(name);
            p->setId(id);
            p->setAge(age);

            if (choice == 3) {
                ChronicPatient* cp = dynamic_cast<ChronicPatient*>(p);
                string condition, date;
                cout << "Nhap benh nen: "; getline(cin, condition);
                cout << "Nhap ngay kham gan nhat (dd/mm/yyyy): "; getline(cin, date);
                cp->setCondition(condition);
                cp->setLastCheckupDate(date);
            }

            patients.push_back(p);
            cout << "Da them benh nhan.\n";
        }
        else if (choice == 4) {
            for (Doctor* d : doctors) {
                d->displayInfo();
                cout << "-------------------\n";
            }
        }
        else if (choice == 5) {
            for (Patient* p : patients) {
                p->displayInfo();
                cout << "-------------------\n";
            }
        }
        else if (choice == 6) {
            Appointment* a = new Appointment();
            int id;
            string date, time, reason;

            cout << "Nhap ID lich hen: "; cin >> id;
            cin.ignore();
            cout << "Nhap ngay (dd/mm/yyyy): "; getline(cin, date);
            cout << "Nhap gio: "; getline(cin, time);
            cout << "Nhap ly do: "; getline(cin, reason);

            a->setAppointmentId(id);
            a->setDate(date);
            a->setTime(time);
            a->setReason(reason);

            cout << "Chon benh nhan (ID): ";
            int pid; cin >> pid;
            cin.ignore();
            Patient* selectedPatient = nullptr;
            for (Patient* p : patients) {
                if (p->getId() == pid) {
                    selectedPatient = p;
                    break;
                }
            }

            cout << "Chon bac si (ID): ";
            int did; cin >> did;
            cin.ignore();
            Doctor* selectedDoctor = nullptr;
            for (Doctor* d : doctors) {
                if (d->getId() == did) {
                    selectedDoctor = d;
                    break;
                }
            }

            if (selectedPatient && selectedDoctor) {
                a->setPatient(selectedPatient);
                a->setDoctor(selectedDoctor);
                appointments.push_back(a);
                cout << "Da lap lich hen.\n";
            } else {
                cout << "Khong tim thay benh nhan hoac bac si.\n";
                delete a;
            }
        }
        else if (choice == 7) {
            cout << "Nhap ID lich hen can huy: ";
            int aid; cin >> aid;
            cin.ignore();
            bool found = false;
            for (auto it = appointments.begin(); it != appointments.end(); ++it) {
                if ( (*it)->getAppointmentId() == aid) {
                    delete *it;
                    appointments.erase(it);
                    cout << "Da huy lich hen.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Khong tim thay lich hen.\n";
        }
        else if (choice == 8) {
            for (Appointment* a : appointments) {
                a->displayInfo();
                cout << "-------------------\n";
            }
        }
        else if (choice == 9) {
            cout << "Nhap ID benh nhan: ";
            int pid; cin >> pid;
            cin.ignore();
            for (Appointment* a : appointments) {
                if (a->getPatient()->getId() == pid) {
                    a->displayInfo();
                    cout << "-------------------\n";
                }
            }
        }

    } while (choice != 0);

    // Giai phong bo nho
    for (Patient* p : patients) delete p;
    for (Doctor* d : doctors) delete d;
    for (Appointment* a : appointments) delete a;

    return 0;
}
 

