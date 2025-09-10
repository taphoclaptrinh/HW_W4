# 📌 Overview

**smallclinic.cpp** – A simple Clinic Management System built with Object-Oriented Programming (OOP) in C++.

The system manages:
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

```
### On Windows (MinGW g++):
```bash
g++ smallclinic.cpp -o clinic.exe
clinic.exe
```

### 🤖 AI Disclosure
Author: Nguyen Minh Thanh – 24110132

I used ChatGPT to assist with:

Brainstorming ideas for class design and method structure

Improving code readability and encapsulation

Understanding how to override virtual functions effectively

All code has been written, tested, and personalized before submission. The AI was used ethically as a support tool, not for full code generation.

### 📝 Reflection
During this assignment, I gained a deeper understanding of Object-Oriented Programming (OOP) concepts, especially inheritance and polymorphism. Designing the Patient base class and extending it with the ChronicPatient subclass helped me clearly see how inheritance allows us to avoid code duplication while adapting behavior for different types of patients.

Implementing virtual and overridden methods gave me practical experience in applying polymorphism to real-world scenarios. I also learned how to manage relationships between objects — such as linking patients and doctors through appointments — and how to structure interactive menus for user input.

One challenge I faced was ensuring that appointment data remained consistent across patients and doctors. While I implemented features like adding, canceling, and viewing appointments, I realized that deeper integration (e.g., syncing medical history with appointment outcomes) would require more advanced design patterns. This is something I hope to improve in future versions.

Overall, this project was a valuable exercise in applying OOP principles to a realistic healthcare scenario.



