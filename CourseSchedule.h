/*Code Miners : Adrineh Khodaverdian, Arthur Hakobyan, Meghmik Asadoorian
 CS/IS 137
 Mid-Term Project
 
 -----------------------------------------------------------------
                         CourseSchedule
 -----------------------------------------------------------------
 -studentName: string
 -numCourses: int
 -maxSize: int
 -*courses: Course
 -semester: Semester
 -checkDates(Sem: const Semester&, startD: Date , endD: Date ) const :bool
 - operator=(const CourseSchedule&) = delete:const CourseSchedule&
 -CourseSchedule(courseScheduleToCopy: const CourseSchedule&)=delete
 -----------------------------------------------------------------
 +CourseSchedule(name:const string&,SemesterName: const Semester&,courseSize: const int)
 +~CourseSchedule()
 +getStudentName() const:string
 +getSemester() const: Semester
 +getNumCourses() const: double
 +setStudentName(NameStudent: const string&): CourseSchedule&
 +setNumCourses(numCOURESES:int): CourseSchedule&
 +setSemester(SEMESTER: const Semester&): CourseSchedule&
 +addCourses(course: const Course&): bool
 +removeCourses(course: const Course&): bool
 -----------------------------------------------------------------
                   |friend functions|
  operator<<( output : ostream&, courseSchedule: const CourseSchedule&) : ostream&

 */

#ifndef CourseSchedule_h
#define CourseSchedule_h
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "Semester.h"
#include "Course.h"
#include "Time.h"

using namespace std;
class CourseSchedule
{
    friend ostream& operator<<(ostream&, const CourseSchedule& );
    
private:
    string studentName;
    int numCourses;
    int maxSize;
    Course *courses;
    Semester semester;
    bool checkDates(const Semester&, Date , Date ) const;
    const CourseSchedule& operator=(const CourseSchedule&) = delete;
    CourseSchedule(const CourseSchedule&) = delete;
    
public:
    CourseSchedule(const string & = "NULL"  ,const Semester & = Semester(), const int& =5);
    ~CourseSchedule();
    string getStudentName() const;
    Semester getSemester() const;
    double getNumCourses() const;
    CourseSchedule& setStudentName(const string&);
    CourseSchedule& setNumCourses(int);
    CourseSchedule& setSemester(const Semester&);
    bool addCourses(const Course&);
    bool removeCourses(const Course&);

    
};
#endif /* CourseSchedule_h */
