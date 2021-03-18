/*Code Miners : Adrineh Khodaverdian, Arthur Hakobyan, Meghmik Asadoorian
 CS/IS 137
 Mid-Term Project
 */

#include <iomanip>
#include "CourseSchedule.h"

using namespace std;

//it wouldn't let me do const Date& because the getSemesterStart date was not a &
//and it returns by value so it couldn't compare the two
bool CourseSchedule::checkDates(const Semester& Sem, Date startDate, Date endDate) const
{
    if( Sem.getSemesterStartDate() > startDate || Sem.getSemesterEndDate() <endDate )
    {
        return false;
    }
    else
    {
        return true;
    }
}

CourseSchedule::CourseSchedule(const string& name,const Semester& SemesterName, const int& courseSize ) : studentName(name), semester(SemesterName),  maxSize(courseSize)
{
    //because all the arguments passed to the constructor are constant we used the member initlazer syntax
    numCourses=0;
    courses=new Course[maxSize];
}
CourseSchedule::~CourseSchedule()
{
    delete [] courses;
    cout<< "destructor running in courseSchedule" <<endl;
}
string CourseSchedule::getStudentName() const
{
    return studentName;
}
Semester CourseSchedule::getSemester() const
{
    return semester;
}
double CourseSchedule::getNumCourses() const
{
    return numCourses;
}
CourseSchedule& CourseSchedule::setStudentName(const string& NameStudent)
{
    studentName=NameStudent;
    return *this;
}
CourseSchedule& CourseSchedule::setNumCourses(int numCOURSES)
{
    numCourses=(numCOURSES >0 && numCOURSES<maxSize ? numCOURSES : 0);
    return *this;
}
CourseSchedule& CourseSchedule::setSemester(const Semester& SEMESTER)
{
    semester=SEMESTER;
    return *this;
}
bool CourseSchedule::addCourses(const Course& course)
{

    bool valid{false};

    if(numCourses< maxSize)
    {

       if(checkDates(semester, course.getStartDate(), course.getEndDate()))
       {
           for(int i=0; i<numCourses; i++)
           {
               if(courses[i].getCourseName()==course.getCourseName() && courses[i].getCourseNumber()==course.getCourseNumber())
               {
                   valid=false;
               }
               
           }
           courses[numCourses]=course;
           setNumCourses(numCourses+1);
           valid=true;
       }
       else
       {
           valid=false;
       }
        
    }
    else
    {
        valid=false;
        
    }

    return valid;
}
bool CourseSchedule::removeCourses(const Course& course)
{
    bool valid{false};

   if(numCourses>0)
    {
       for(int i=0; i<numCourses; i++)
       {
           if(courses[i].getCourseName()==course.getCourseName() && courses[i].getCourseNumber()==course.getCourseNumber())
           {
               numCourses=i;
           }
       }
        Course *Courses;
        Courses=new Course[maxSize];
        courses[numCourses]=Courses[numCourses];
        setNumCourses(numCourses-1);
        valid=true;
    }
    else
    {
        valid=false;
        
    }
    
    return valid;
}

ostream& operator<<(ostream& output, const CourseSchedule& courseSchedule )
{
    output << "CLASS SCHEDULE" <<endl;
    output << "-----------------------" <<endl;
    output << "Name: " << courseSchedule.getStudentName() <<endl;
    output << "Semester: " << courseSchedule.getSemester();
    output << "Number of Classes: "<<courseSchedule.getNumCourses() <<endl;
    output << "-----------------------------------------" <<endl;
    for(int i=0; i<courseSchedule.maxSize; i++)
    {
        output << "Course Info: " << courseSchedule.courses[i] <<endl;

    }
    return output;

}
