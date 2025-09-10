# HW_W4
**smallclinic.cpp** – A simple Clinic Management System built with Object-Oriented Programming (OOP) in C++.

This system manages:
- Patients (regular & chronic)
- Doctors
- Appointments

It demonstrates key OOP principles:
- Classes & objects
- Inheritance
- Encapsulation
- Polymorphism

---

# ⚙️ Build & Run Instructions

### On Linux / macOS / WSL:
```bash
g++ smallclinic.cpp -o clinic
./clinic
On Windows (MinGW g++):
bash
g++ smallclinic.cpp -o clinic.exe
clinic.exe
🤖 AI Disclosure
Author: Nguyen Minh Thanh – 24110132

I used ChatGPT to assist with:

Brainstorming method ideas for the Appointment class

Designing inheritance structure between Patient and ChronicPatient

Improving code readability and ensuring proper encapsulation

All code was written, understood, tested, and refined by me before submission. The AI was used ethically as a support tool, not for full code generation.

📝 Reflection
This assignment helped me strengthen my understanding of Object-Oriented Programming (OOP), especially the use of inheritance and polymorphism in real-world scenarios.

Designing the Patient base class and extending it with the ChronicPatient subclass allowed me to model different types of patients without duplicating code. Overriding methods like scheduleAppointment() gave me hands-on experience with polymorphism and dynamic behavior.

One challenge I encountered was managing consistency between patient records and appointment data. While I implemented features like scheduling and canceling appointments, I realized that syncing these changes with a patient's medical history would require deeper integration between classes. This highlighted the complexity of real-world systems and gave me ideas for future improvements, such as adding a medicalHistory vector and linking it to appointment outcomes.

Overall, this project was a valuable exercise in applying OOP principles to a practical healthcare scenario.
