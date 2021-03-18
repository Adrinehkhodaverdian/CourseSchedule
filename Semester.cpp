/*Code Miners : Adrineh Khodaverdian, Arthur Hakobyan, Meghmik Asadoorian
 CS/IS 137
 Mid-Term Project
 */


#include "Semester.h"
#include <iostream>
using namespace std;

Semester::Semester(const string& sName, const Date& startD, const Date& endD): semesterName(sName),semesterStartDate(startD), semesterEndDate(endD)
{
    
 //all member variables are initizlied
}
//set functions allowing cascading
Semester& Semester::setSemesterName(const string& sName)
{
    this->semesterName=sName;
    return *this;
}
Semester& Semester::setSemesterStartDate(const Date& startD)
{
    semesterStartDate=startD;
    return *this;
}
Semester& Semester::setSemesterEndDate(const Date& endD)
{
    semesterEndDate=endD;
    return *this;
}
//get functions should not change the member variables
string Semester::getSemesterName() const
{
    return semesterName;
}
Date Semester::getSemesterStartDate() const
{
    return semesterStartDate;
    
}
Date Semester::getSemesterEndDate() const
{
    return semesterEndDate;
}
//operator overload
istream& operator>>(istream& input, Semester& semester)
{
    getline(input,semester.semesterName,'(');
    input.ignore();
    input>> semester.semesterStartDate;
    input.ignore();
    input >> semester.semesterEndDate;
    return input;
}
ostream& operator<<(ostream& output, const Semester& semester)
{
    output << "Semester: " << semester.getSemesterName();
    output << "  ("<< semester.getSemesterStartDate() << " - " ;
    output<< semester.getSemesterEndDate() << ") "<<endl;

    return output;
}

