/*Code Miners : Adrineh Khodaverdian, Arthur Hakobyan, Meghmik Asadoorian
 CS/IS 137
 Mid-Term Project
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "CourseSchedule.h"
using namespace std;

int main()
{
    string studentName{ '\0' };
    string semesterName{ '\0' };
    int maxCourses{ 0 };
    Date semesterStartDate;
    Date semesterEndDate;
    Date courseStartDate;
    Date courseEndDate;
    char choice{ '\0' };
    string courseNumber{ '\0' };
    double units{ 0 };
    Time starTime;
    Time endTime;
    string meetingDays{ '\0' };
    string courseName{ '\0' };


    cout << "Please enter your name: ";
    getline(cin, studentName);
    cout << "Please enter your enrollment semester name: ";
    getline(cin, semesterName);
    cout << "Please enter maximum number of courses allowed for semester : ";
    cin >> maxCourses;
    cin.ignore();
    cout << "Please enter semester start date in (01/01/2020 format) : ";
    cin >> semesterStartDate;
    cout << "Please enter semester end date in (02/02/2020 format) : ";
    cin >> semesterEndDate;

    while(semesterStartDate > semesterEndDate)
    {  
        cout << "COURSE DATE IS INVALID!" << endl;
        cout << "Please enter semester start date in (02/02/2020 format) : ";
        cin >> semesterStartDate;
        cout << "Please enter semester end date in (02/02/2020 format) : ";
        cin >> semesterEndDate;

    }
   
    Semester semester(semesterName, semesterStartDate, semesterEndDate);

    CourseSchedule courseSchedule(studentName, semester, maxCourses);
    do
    {
        cout << "\nCOURSE ENTRY MENU FOR " <<  semester << endl;
        cout << "---------------------------------------------------------- "<<endl;
        cout << "1) Enter a new course" << endl;
        cout << "2) Remove a course" <<endl;
        cout << "3) Print a Semester Schedule "<<endl;
        cout << "q) Quit the program" << endl;
        cin >> choice;
        if(choice=='1')
        {
            cin.ignore();
            cout << "Please enter course number : ";
            getline (cin, courseNumber);
            cout << "Please enter course name : ";
            getline (cin, courseName);
            cout << "Please enter course units: ";
            cin>> units;
            cin.ignore();
            cout << "Please enter course meeting Days: ";
            getline (cin, meetingDays);
            cout << "enter course startTime (12:00 AM/PM format): ";
            cin >> starTime;
            cout << "enter course endTime (12:00 AM/PM format): ";
            cin >> endTime;
            cout << "enter course startDate (01/01/2020 format): ";
            cin >> courseStartDate;
            cout << "enter class endDate (01/01/2020 format): ";
            cin >> courseEndDate;
            //checking course date with semester date
            if( courseStartDate >= semesterStartDate && courseEndDate <= semesterEndDate )
            {
                Course course( courseNumber, courseName, meetingDays, units, courseStartDate, courseEndDate, starTime, endTime);
                if(courseSchedule.addCourses(course))
                {
                    cout << "COURSE ADDED SUCCESSFULLY!" <<endl;
                }
                else
                {
                    cout << "COURSE DOES NOT EXIST! OR HAS BEEN ADDED PREVIOUSLY!" <<endl;
                }
            }
            else
            {
                cout << "COURSE DATE IS INVALID!" <<endl;
            }
       }
        else if(choice=='2')
        {
            cin.ignore();
            cout << "Please enter course number : ";
            getline (cin, courseNumber);
            cout << "Please enter course name : ";
            getline (cin, courseName);

            Course course( courseNumber, courseName);
            
            if(courseSchedule.getNumCourses()==0)
            {
                cout << "THERE ARE 0 NUMBER OF COURSES TO BE REMOVED!" <<endl;
            }
            else{
                if(courseSchedule.removeCourses(course))
                {
                    cout << "COURSE REMOVED SUCCESSFULLY" <<endl;
                }
                else
                {
                    cout << "COURSE DOES NOT EXIST! OR HAS BEEN ADDED PREVIOUSLY!" <<endl;
                }
            }
        }
        else if(choice=='3')
        {
            cout << courseSchedule <<endl;
            
        }
        else if(choice=='q' || choice=='Q')
        {
            cout << courseSchedule <<endl;
            cout << "Good Luck! for your new semester!" <<endl;
        }
        else
        {
            cout << "invalid entery" <<endl;
        }
    }while( choice!='q' && choice!='Q');

    
    return 0;
}
