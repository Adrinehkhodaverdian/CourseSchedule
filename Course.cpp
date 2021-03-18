/*Code Miners : Adrineh Khodaverdian, Arthur Hakobyan, Meghmik Asadoorian
 CS/IS 137
 Mid-Term Project
 */


#include <stdio.h>
#include <iostream>
#include "Course.h"
using namespace std;



Course::Course(const string& cNumber, const string & cName, const string & meetingDays,
        double UNITS, const Date & startD, const Date & endD, const Time & startT,
       const Time & endT): courseNumber(cNumber), courseName(cName), courseMeetingDays(meetingDays),  units(UNITS), startDate(startD), endDate(endD),startTime(startT), endTime(endT)
{
    //nothing to set
}
Course::~Course()
{
    cout<< "desctructor running" <<endl;
}
Course& Course::setCourseNumber(const string& cNumber)
{
    courseNumber=cNumber;
    return *this;
}
Course& Course::setCourseName(const string& cName)
{
    courseName=cName;
    return *this;
}
Course& Course::setCourseMeetingDays(const string& meetingDays)
{
    courseMeetingDays=meetingDays;
    return *this;
}
Course& Course::setUnits( double UNITS)
{
    units=( UNITS >0 && UNITS <20 ? UNITS : 1);
    return *this;
}

//set functions for Time and Date objects
Course& Course::setStartDate(const Date& startD)
{
    startDate=startD;
    return *this;
}
Course& Course::setStartTime(const Time& startT)
{
    startTime=startT;
    return *this;
}

Course& Course::setEndDate(const Date& endD)
{
    endDate=endD;
    return *this;
}
Course& Course::setEndTime(const Time& endT)
{
    endTime=endT;
    return *this;
}

//get functions should not be able to modify
string Course::getCourseNumber() const
{
    return courseNumber;
    
}
string Course::getCourseName() const
{
    return courseName;
}
string Course::getCourseMeetingDays() const
{
    return courseMeetingDays;
}
double Course::getUnits() const
{
    return units;
}
Date Course::getStartDate() const
{
    return startDate;
}
Time Course::getStartTime() const
{
    return startTime;
}
Date Course::getEndDate() const
{
    return endDate;
}
Time Course::getEndTime() const
{
    return  endTime;
}
double Course::calcDailyDuration() const
{
    double duration{0};
    duration=this->getEndTime()-this->getStartTime();
    return duration;
}

ostream& operator<<( ostream& output, const Course& course)
{
    output << "Course Info: " << course.getCourseNumber();
    output <<" --- " << course.getCourseName() << endl;
    output << "# of Units: " << course.getUnits() << endl;
    output << "Course Dates: " << course.getStartDate() ;
    output << " - " <<course.getEndDate() <<endl;
    output << "Meeting Days: " << course.getCourseMeetingDays()<< endl;
    output << "Meeting Time: " << course.getStartTime();
    output << " - " << course.getEndTime() <<endl;
    output << "Daily Duration: " <<setprecision(2)<< course.calcDailyDuration() << "hours"<<endl;
    return output;
}

