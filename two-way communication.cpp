#include <iostream>
#include <string>

using namespace std;

struct Student;
struct Lesson;

struct Student{
  int semester;
  string faculty;
  Lesson *lesson1;
  Lesson *lesson2;
  Lesson *lesson3;
};

struct Lesson{
  int semester;
  string faculty;
  Student *student1;
  Student *student2;
  Student *student3;
};

struct Student *student1;
struct Student *student2;
struct Student *student3;
struct Lesson *lesson1;
struct Lesson *lesson2;
struct Lesson *lesson3;


int main()
{

  Lesson Mechanics;
  Lesson AnalytGeom;
  Lesson Python;
  Lesson Electricity;
  Lesson DiffEquations;
  Lesson Cpp;
  Lesson QuantMech;
  Lesson TFCV;
  Lesson EqMathPhys;

  Student Ivan;
  Student Vasiliy;
  Student Anatoly;
  Student Alexander;
  Student Nikolai;
  Student Oleg;
  Student Anton;
  Student Olga;


  Mechanics.semester = 1;
  Mechanics.faculty = "Physics";
  Mechanics.student1 = &Vasiliy;


  AnalytGeom.semester = 1;
  AnalytGeom.faculty = "Higher Mathematics";
  AnalytGeom.student1 = Ivan;
  AnalytGeom.student2 = Vasiliy;
  AnalytGeom.student3 = Anatoly;


  Python.semester = 1;
  Python.faculty = "Computer Science";
  Python.student1 = Ivan;
  Python.student2 = Anatoly;


  Electricity.semester = 3;
  Electricity.faculty = "Physics";
  Electricity.student1 = Nikolai;


  DiffEquations.semester = 3;
  DiffEquations.faculty = "Higher Mathematics";
  DiffEquations.student1 = Alexander;
  DiffEquations.student2 = Nikolai;
  DiffEquations.student3 = Oleg;


  Cpp.semester = 3;
  Cpp.faculty = "Computer Science";
  Cpp.student1 = Alexander;
  Cpp.student2 = Oleg;


  QuantMech.semester = 5;
  QuantMech.faculty = "Physics";
  QuantMech.student1 = Anton;


  TFCV.semester = 5;
  TFCV.faculty = "Higher Mathematics";
  TFCV.student1 = Anton;
  TFCV.student2 = Olga;


  EqMathPhys.semester = 5;
  EqMathPhys.faculty = "Higher Mathematics";
  EqMathPhys.student1 = Anton;
  EqMathPhys.student2 = Olga;




  Ivan.semester = 1;
  Ivan.faculty = "Computer Science";
  Ivan.lesson1 = AnalytGeom;
  Ivan.lesson2 = Python;


  Vasiliy.semester = 1;
  Vasiliy.faculty = "Physics";
  Vasiliy.lesson1 = Mechanics;
  Vasiliy.lesson2 = AnalytGeom;


  Anatoly.semester = 1;
  Anatoly.faculty = "Higher Mathematics";
  Anatoly.lesson1 = AnalytGeom;
  Anatoly.lesson2 = Python;


  Alexander.semester = 3;
  Alexander.faculty = "Computer Science";
  Alexander.lesson1 = DiffEquations;
  Alexander.lesson2 = Cpp;


  Nikolai.semester = 3;
  Nikolai.faculty = "Physics";
  Nikolai.lesson1 = Electricity;
  Nikolai.lesson2 = DiffEquations;


  Oleg.semester = 3;
  Oleg.faculty = "Higher Mathematics";
  Oleg.lesson1 = DiffEquations;
  Oleg.lesson2 = Cpp;


  Anton.semester = 5;
  Anton.faculty = "Physics";
  Anton.lesson1 = QuantMech;
  Anton.lesson2 = TFCV;
  Anton.lesson3 = EqMathPhys;


  Olga.semester = 5;
  Olga.faculty = "Higher Mathematics";
  Olga.lesson1 = TFCV;
  Olga.lesson2 = EqMathPhys;

  return 0;
}
