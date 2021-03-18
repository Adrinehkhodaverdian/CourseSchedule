/*Code Miners : Adrineh Khodaverdian, Arthur Hakobyan, Meghmik Asadoorian
 CS/IS 137
 Mid-Term Project
 ---------------------------------------------------------------------------------------
                                     Course
 ---------------------------------------------------------------------------------------
 -courseNumber : string
 -courseName :string
 -courseMeetingDays : string
 -units :double
 -startDate : Date
 -endDate : Date
 -startTime : Time
 -endTime : Time
 --------------------------------------------------------------------------------------
 +Course(cNumber: const string& ,cName : const string& ,meetingDays: const string&,
         units: const double, startD :const Date& , endD:const Date&, startT: const Time, endT :const Time&)
 +~Course()
 +setCourseNumber(cNumber: const string&) :  Course&
 +setCourseName(cName: const string&):  Course&
 +setCourseMeetingDays(meetingDays: const string&):  Course&
 +setUnits(UNITS: const double):  Course&
 +setStartDate(startD: const Date&):  Course&
 +setStartTime(startT: const Time&):  Course&
 +setEndDate(endD: const Date&):  Course&
 +setEndTime(endT: const Time&):  Course&
 +getCourseNumber() const: string
 +getCourseName() const: string
 +getCourseMeetingDays() const: string
 +getUnits() const : double
 +getStartDate() const: Date
 +getStartTime() const: Time
 +getEndDate() const: Date
 +getEndTime() const:Time
 +calcDailyDuration() const: double
 ------------------------------------------------------------------------------------------
                   |friend functions|
  operator<<( output : ostream&, course: const Course&) : ostream&

 */

#ifndef Course_h
#define Course_h
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class Course
{
    friend ostream& operator<<( ostream&, const Course&);
private:
    string courseNumber; // number of the class such as CS/IS 124
    string courseName; //name of the course such as c++
    string courseMeetingDays; //days that the class meets MTWTh
    double units; //course units 1.5
    Date startDate; //days the course starts
    Date endDate;  //day the course ends
    Time startTime; //class start time
    Time endTime; //class end time
    
    
public:
    // because instances of the course will be used in the class we want to make sure
    //non of the other programs will change the course
    Course(const string & = "NULL", const string & = "NULL", const string & = "NULL",
            double = 0, const Date & = Date(), const Date & = Date(), const Time & = Time(), const Time & = Time());
    ~Course();
    Course& setCourseNumber(const string&);
    Course& setCourseName(const string&);
    Course& setCourseMeetingDays(const string&);
    Course& setUnits( double);
    //set functions for Time and Date objects
    Course& setStartDate(const Date&);
    Course& setStartTime(const Time&);
    Course& setEndDate(const Date&);
    Course& setEndTime(const Time&);
    //get functions should not be able to modify
    string getCourseNumber() const;
    string getCourseName() const;
    string getCourseMeetingDays() const;
    double getUnits() const;
    Date getStartDate() const;
    Time getStartTime() const;
    Date getEndDate() const;
    Time getEndTime() const;
    double calcDailyDuration() const;

};

#endif /* Course_h */
