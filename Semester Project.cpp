
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;



struct Course {
    string name;
    int creditHours;
    double grade;
};


double calculateGPA(double grade) {
    //  GPA calculation logic 
    
   	
	if (grade >= 80)
        return 4.0;
    else if (grade >= 75 || grade < 80 )
        return 3.5;
    else if (grade >= 70 || grade < 75)
        return 3.0;
    else if (grade >= 65 || grade < 70)
        return 2.5;
    else if (grade >= 60 || grade < 65)
	     return 2.0;
	else if (grade >= 55 || grade < 60)
	      return 1.5;
	else if (grade >= 45 || grade < 55)	
	  	  return 1.0;   
    else
        return 0.0;
}



double calculateCGPA(Course courses[], int numCourses) {
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;

    for (int i = 0; i < numCourses; i++) {
        totalGradePoints += courses[i].creditHours * calculateGPA(courses[i].grade);
        totalCreditHours += courses[i].creditHours;
    }

    return totalGradePoints / totalCreditHours;
}
 
int main() {
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    Course courses[numCourses];

    // Read course information from the user
    for (int i = 0; i < numCourses; i++) {
        cout << "Enter the name of course " << i + 1 << ": ";
        cin.ignore();
        getline(cin, courses[i].name);

        cout << "Enter the credit hours of course " << i + 1 << ": ";
        cin >> courses[i].creditHours;

        cout << "Enter the score obtained in course " << i + 1 << ": ";
        cin >> courses[i].grade;
    }

    // Calculate and display the CGPA
    double cgpa = calculateCGPA(courses, numCourses);
    cout << fixed << setprecision(2);
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
