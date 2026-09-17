#include <iostream>
#include <string>
using namespace std;  

void addStudent(string names[], int &studentCount, int absences[]);   

void enterGrades(int exam1[], int exam2[], int exam3[], string names[], int studentCount);

void calculateAverage(int exam1[], int exam2[], int exam3[], string names[], int studentCount);

int findStudentByName(string names[], int studentCount, string searchName);    // will return the index of the found student; if not found, it can return -1, for example.

void listStudents(string names[], int studentCount);

void findMinMaxAverage(int exam1[], int exam2[], int exam3[], string names[], int studentCount);  

void listAbsentStudents(int absences[], string names[], int studentCount, int limit); 

void sortStudents(int exam1[], int exam2[], int exam3[], string names[], int absences[], int studentCount);   // sort by name, alphabetically
// When we want to sort an array within an array, do we also need to use the other arrays because they are linked via indices? 
// Alphabetical sorting (bubble sort, moving 5 arrays together)


int main() {
    string names[20];

    int exam1[20];   
    int exam2[20];
    int exam3[20];
    
    int absences[20];  

    int studentCount=0;

    int choice;

    do{
        cout<<"STUDENT GRADE ATTENDANCE TRACKER\n";  
        cout<<"1.Add Student"<<"\n";
        cout<<"2.Enter Grades"<<"\n";
        cout<<"3.Calculate Average"<<"\n";
        cout<<"4.Find Min/Max Average"<<"\n";
        cout<<"5.Search by Name"<<"\n";
        cout<<"6.List Absent Students"<<"\n";
        cout<<"7.List Students"<<"\n";  
        cout<<"8.Sort Students"<<"\n";
        cout<<"9.Exit"<<"\n";

        cin>>choice;


        switch(choice) {
            
            case 1: addStudent(names, studentCount, absences);  
 // Ama biz addStudent'ı reference (&) ile tanımlamıştık, pointer (*) ile değil. Hatırlarsan reference'ın en büyük avantajı tam da buydu: 
//çağırırken & yazmana gerek yok normal değişken adını yazman yeterli referans olma işi fonksiyonun tanımında(int &studentCount prototipte)halletti
             break;
// We defined addStudent with reference (&), not pointer (*). If you remember, this was exactly the biggest advantage of reference: 
//You don't need to write & when calling; just write the regular variable name; the reference handling is handled in the function definition (int &studentCount in the prototype).
            case 2: enterGrades(exam1, exam2, exam3, names, studentCount);   
             break;

            case 3: calculateAverage(exam1, exam2, exam3, names, studentCount);
             break;

            case 4: findMinMaxAverage(exam1, exam2, exam3, names, studentCount);
             break;

            case 5: {
            string searchName; 

            cout<<"Enter name to search: ";
            cin>>searchName;

            int result = findStudentByName(names, studentCount, searchName);  
                  if (result == -1) {
                   cout << "Student not found!\n";
                  } else {
                   cout << "Student found: " << names[result] << "\n";
                  }
             break;
            }

            case 6: {
            int limit;

            cout << "Enter absence limit: ";
            cin >> limit;

            listAbsentStudents(absences, names, studentCount, limit);
             break;
            }
            
            case 7: listStudents(names, studentCount);
             break;

            case 8: sortStudents(exam1, exam2, exam3, names, absences, studentCount);
             break;

            case 9:
               cout<<"Goodbye"<<"\n";
             break;
            default:
                cout<<"Invalid choice!";
             break;
        }
   } while(choice != 9);

}

void addStudent(string names[], int &studentCount, int absences[]){
    if (studentCount >= 20) {
        cout << "Cannot add more students, limit reached!\n";
        return;
    }
    cin.ignore();    // önceki cin >> choice'tan kalan "Enter" karakterini temizle
    cout<<"Enter student name: ";
    //cin >> or getline(cin, . since the name may contain spaces...)
    getline(cin, names[studentCount]);    // Consider: studentCount currently holds the information "how many students have been added so far".
// If studentCount = 0 and you're adding the first student, shouldn't this student go to names[0]? Second student to names[1], third student to names[2]...
 // So you should use studentCount itself as the index.
    cout << "Enter absences: ";
    cin >> absences[studentCount];  

    studentCount++;
}

void enterGrades(int exam1[], int exam2[], int exam3[], string names[], int studentCount){

// If we don't write this, it may produce an incorrect result if an invalid index is entered.
     if (studentCount == 0) {
        cout << "No students added yet!\n";
        return;
    }
    
// Print the names[i] values from 0 to studentCount using a for loop.
     for(int i=0;i<studentCount;i++){
        cout<< i << "." << names[i] <<"\n";    
     }

int selected;
cout<<"Selected student number: ";
cin>>selected;

if (selected < 0 || selected >= studentCount) {
    cout << "Invalid student number!\n";
    return;
}

cout<<"Enter exam 1 grade: ";
cin>>exam1[selected];

cout<<"Enter exam 2 grade: ";
cin>>exam2[selected];

cout<<"Enter exam 3 grade: ";
cin>>exam3[selected];
}

void calculateAverage(int exam1[], int exam2[], int exam3[], string names[], int studentCount){

      for(int i=0;i<studentCount;i++){  
        float average = (exam1[i] + exam2[i] + exam3[i]) / 3.0;   
        cout << names[i] << ": " << average << "\n";
    }
}

int findStudentByName(string names[], int studentCount, string searchName){
      
      for(int i=0;i<studentCount;i++){ 
        if(names[i] == searchName){          // Using "==", string comparison can be done directly with == in C++
          return i;
        }
     }
     return -1;
}

void listStudents(string names[], int studentCount){

    for(int i=0;i<studentCount;i++){
        cout<<i<<"."<<names[i]<<"\n";   
    }
}

void findMinMaxAverage(int exam1[], int exam2[], int exam3[], string names[], int studentCount){
      
     if (studentCount == 0) {
        cout << "No students added yet!\n";
        return;
    }

    float maxAverage = (exam1[0] + exam2[0] + exam3[0]) / 3.0;
    int maxIndex = 0;    
    
     for(int i=1;i<studentCount;i++){     

        float average = (exam1[i] + exam2[i] + exam3[i]) / 3.0;
        if(average > maxAverage){
            maxAverage = average;
            maxIndex = i;
        }
     }
     float minAverage = (exam1[0] + exam2[0] + exam3[0]) / 3.0;
     int minIndex = 0;

       for(int i=1;i<studentCount;i++){   
         float average = (exam1[i] + exam2[i] + exam3[i]) / 3.0;
        if(average < minAverage){
            minAverage = average;
            minIndex = i;
        }
       }
    cout<< "Highest average: "<< names[maxIndex] << " with " << maxAverage <<"\n";
    cout<< "Lowest average: "<< names[minIndex] << " with " << minAverage <<"\n";
}

void listAbsentStudents(int absences[], string names[], int studentCount, int limit){

   // Task: To list students whose absenteeism exceeds the limit value.
       for(int i=0;i<studentCount;i++){
          if(absences[i] > limit){
              cout<< names[i] <<"\n";
          }
        }
}

void sortStudents(int exam1[], int exam2[], int exam3[], string names[], int absences[], int studentCount){

// Our goal: To sort the names alphabetically, but while doing so, also move the arrays exam1, exam2, exam3, absences at the same time. 
// (because the indices were interconnected, we had discussed this)
    for (int i = 0; i < studentCount - 1; i++){        // outer loop = how many times will we iterate?
        for (int j = 0; j < studentCount - i - 1; j++){       // inner loop = which two neighbors will we compare?
 
            if (names[j] > names[j+1]) {
            string temp = names[j];
            names[j] = names[j+1];
            names[j+1] = temp;

            int tempExam1 = exam1[j];
            exam1[j] = exam1[j+1];
            exam1[j+1] = tempExam1;

            int tempExam2 = exam2[j];
            exam2[j] = exam2[j+1];
            exam2[j+1] = tempExam2;

            int tempExam3 = exam3[j];
            exam3[j] = exam3[j+1];
            exam3[j+1] = tempExam3;

            int tempAbsences = absences[j];
            absences[j] = absences[j+1];
            absences[j+1] = tempAbsences;
          }
       }  
    }
   cout << "Students sorted successfully!\n";

   listStudents(names, studentCount);     // We call this function to display the list after sorting.
}
