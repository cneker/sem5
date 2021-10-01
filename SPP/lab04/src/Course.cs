using System;
using System.Collections.Generic;

namespace lab04 {
    abstract class Person {
        protected string _name;
        public virtual void ShowName() {
            Console.WriteLine($"Name: {_name}");
        }
        public override string ToString()
        {
            return _name;
        }
    }

    class Teacher : Person {
        public Dictionary<Course, List<Student>> _lst = new Dictionary<Course, List<Student>>();

        public Teacher(string name) {
            _name = name;
        }

        public void AddCourse(string nameofcourse) {
            Course course = new Course(nameofcourse);
            _lst.Add(course, new List<Student>());
        }

        public override string ToString()
        {
            return _name.ToString();
        }

        public Course GetCourse(string name) {
            foreach (var sd in _lst.Keys) {
                if (sd.ToString() == name){
                    return sd;
                }
            }
            return null;
        }

        public Mark SetMark(int mark, Student student, string course) {
            var n = GetCourse(course);
            var v = _lst[n];
            v.Remove(student);
            _lst[n] = v;
            Mark mar = new Mark(mark, this, student, n);
            Archive.AddMark(mar);
            return mar;
        }
    }

    class Course {
        private string _nameofcourse;
        
        public Course (string coursename) {
            _nameofcourse = coursename;
        }

        public override string ToString()
        {
            return _nameofcourse;
        }
    }

    class Student : Person {
        private List<Course> _courses = new List<Course>();

        public Student(string name) {
            _name = name;
        }

        public void EnterToCourse(Teacher teacher, string coursename) {
            var crs = teacher.GetCourse(coursename);
            var vrs = teacher._lst[crs];
            vrs.Add(this);
            teacher._lst[crs] = vrs;
        }
    }

    static class Archive {
        private static List<Mark> lst = new List<Mark>();

        public static void AddMark(Mark mark) {
            lst.Add(mark);
        }
        public static void ShowMarks() {
            foreach (Mark mark in lst) {
                Console.WriteLine(mark.ToString());
            }
        }
    }

    class Mark {
        public int mark;
        public Teacher teacher;
        public Student student;
        public Course course;
        public Mark(int mark1, Teacher teacher1, Student student1, Course course1) {
            mark = mark1;
            teacher = teacher1;
            student = student1;
            course = course1;
        }

        public override string ToString()
        {
            return $"Student name: {student.ToString()}, Teacher name: {teacher.ToString()}, Course name: {course.ToString()}, Mark: {mark}";
        }
    }
}