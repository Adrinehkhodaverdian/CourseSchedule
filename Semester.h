/*Code Miners : Adrineh Khodaverdian, Arthur Hakobyan, Meghmik Asadoorian
 CS/IS 137
 Mid-Term Project
 -----------------------------------------------------------------
                         Semester
 -----------------------------------------------------------------
 -semesterName: string
 -semesterStartDate: Date
 -semesterEndDate: Date
 -----------------------------------------------------------------
 +Semester(sName: const string &,startD: const Date & , endD: const Date & )
 +setSemesterName(sName: const string&) : Semester&
 +setSemesterStartDate(startD: const Date&): Semester&
 +setSemesterEndDate(endD: const Date&): Semester&
 +getSemesterName() const: string
 +getSemesterStartDate() const: Date
 +getSemesterEndDate() const: Date
 -----------------------------------------------------------------
                   |friend functions|
  operator<<( output : ostream&, semester: const Semester&) : ostream&
  operator>>( input  : istream&, semester: Semester&) : istream&
 
 */

#ifndef Semester_h
#define Semester_h
#include <iostream>
#include <iomanip>
#include <string>
#include "Course.h"
#include "Date.h"
#include "Time.h"
using namespace std;

class Semester
{
    friend ostream& operator<<(ostream&, const Semester&);
    friend istream& operator>>(istream&, Semester&);
private:
    string semesterName;
    Date semesterStartDate;
    Date semesterEndDate;
public:
    Semester(const string & = "NULL", const Date & = Date(), const Date & = Date());
    //set functions allowing cascading
    Semester& setSemesterName(const string&);
    Semester& setSemesterStartDate(const Date&);
    Semester& setSemesterEndDate(const Date&);
    //get functions should not change the member variables
    string getSemesterName() const;
    Date getSemesterStartDate() const;
    Date getSemesterEndDate() const;
    
};

#endif /* Semester_h */
