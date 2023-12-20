#include <iostream>
#include <vector>
#include <iomanip>

// Define a class for Student
class Student {
private:
    std::string name;
    int rollNumber;
    std::vector<int> marks;

public:
    // Constructor to initialize the student
    Student(const std::string& name, int rollNumber) : name(name), rollNumber(rollNumber) {}

    // Function to input marks for a subject
    void inputMarks(int mark) {
        marks.push_back(mark);
    }

    // Function to calculate the average marks
    double calculateAverage() const {
        if (marks.empty()) {
            return 0.0;
        }
        double sum = 0.0;
        for (int mark : marks) {
            sum += mark;
        }
        return sum / marks.size();
    }

    // Function to calculate the grade based on the average marks
    char calculateGrade() const {
        double average = calculateAverage();
        if (average >= 90) return 'A';
        else if (average >= 80) return 'B';
        else if (average >= 70) return 'C';
        else if (average >= 60) return 'D';
        else return 'F';
    }

    // Function to display student result
    void displayResult() const {
        std::cout << "\n----- Student Result -----\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Roll Number: " << rollNumber << "\n";
        std::cout << "Subject Marks: ";
        for (int mark : marks) {
            std::cout << mark << " ";
        }
        std::cout << "\nAverage: " << std::fixed << std::setprecision(2) << calculateAverage() << "\n";
        std::cout << "Grade: " << calculateGrade() << "\n";
    }
};

int main() {
    const int numStudents = 1; // Adjust as needed
    std::vector<Student> students;

    // Input data for each student
    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        int rollNumber;
        std::cout << "Enter student name: ";
        std::getline(std::cin >> std::ws, name);
        std::cout << "Enter roll number: ";
        std::cin >> rollNumber;

        Student student(name, rollNumber);
        student.inputMarks(85); // Sample mark, you can extend this for multiple subjects
        students.push_back(student);
    }

    // Display result for each student
    for (const auto& student : students) {
        student.displayResult();
    }

    return 0;
}

