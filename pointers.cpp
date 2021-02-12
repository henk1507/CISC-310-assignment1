// compile: g++ -std=c++11 -o pointers pointers.cpp
// run: ./pointers
#include <iostream>
#include <string>
#include <limits>
#include <cmath>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    Student *p_student = &student;
    double average;
    double *p_average = &average;
    std::string message;
    bool invalid = true;

    student.f_name = new char[128];
    student.l_name = new char[128];

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);
    
    while(invalid)
    {
        std::cout << "Please enter the student's first name: ";
        std::cin >> student.f_name;
        if(std::cin.fail())
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            invalid = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    invalid = true;
    
    while(invalid)
    {
        std::cout << "Please enter the student's last name: ";
        std::cin >> student.l_name;
        if(std::cin.fail())
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            invalid = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 0, 134217728);

    student.grades = new double[student.n_assignments];
    std::cout << std::endl;

    for(int i = 0; i < student.n_assignments; i++)
    {
        message = "Please enter grade for assignment " + std::to_string(i) + ": ";
        *(student.grades + i) = promptDouble(message, 0, 1000);
    }
    std::cout << std::endl;

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(p_student, p_average);
    // Output `average`
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
    std::cout << "  Average grade: " << average << std::endl;

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    bool invalid = true;
    int input;

    while(invalid)
    {
        std::cout << message;
        std::cin >> input;
        if(input >= max or input <= min or std::cin.fail())
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            invalid = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return input;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    bool invalid = true;
    double input;

    while(invalid)
    {
        std::cout << message;
        std::cin >> input;
        if(input >= max or input <= min or std::cin.fail())
        {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            invalid = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return input;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    Student student = *(Student *)object;
    double count = 0;
    double rounder;

    for(int i = 0; i < student.n_assignments; i++)
    {
        count += *(student.grades + i);
    }
    rounder = count/student.n_assignments;

    rounder = rounder * 10;
    rounder = std::round(rounder);
    rounder = rounder/10;

    *avg = rounder;

    return;
}
