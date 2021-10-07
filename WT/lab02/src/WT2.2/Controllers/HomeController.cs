using System.Linq;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WT2._2.Models;

namespace WT2._2.Controllers
{
    public class HomeController : Controller
    {
        private DataBaseContext _dataBaseContext;

        public HomeController(DataBaseContext dataBaseContext)
        {
            _dataBaseContext = dataBaseContext;
        }

        public IActionResult Index()
        {
            return View(_dataBaseContext.Faculties.ToList());
        }

        [HttpGet]
        public IActionResult Faculties(int FacultyId)
        {
            if (ModelState.IsValid)
            {
                return RedirectToAction("Courses", new {FacultyId});
            }

            return RedirectToAction("Index", _dataBaseContext.Faculties.ToList());
        }

        public IActionResult Courses(int FacultyId)
        {
            var courses = _dataBaseContext.Courses
                .Include(f => f.Faculty)
                .Where(c => c.FacultyId == FacultyId).Select(c => c).ToList();
            return View(courses);
        }

        [HttpGet]
        public IActionResult Groups(int FacultyId, int CourseId)
        {
            if (ModelState.IsValid)
            {
                return RedirectToAction("Group", new { FacultyId, CourseId });
            }
            return RedirectToAction("Index", _dataBaseContext.Faculties.ToList());
        }

        public IActionResult Group(int FacultyId, int CourseId)
        {
            var courses = _dataBaseContext.Groups
                .Include(f => f.Course.Faculty)
                .Include(c => c.Course)
                .Where(c => c.CourseId == CourseId).Select(c => c).ToList();
            return View(courses);
        }

        [HttpGet]
        public IActionResult Students(int FacultyId, int CourseId, int GroupId)
        {
            if (ModelState.IsValid)
            {
                return RedirectToAction("Student", new { FacultyId, CourseId, GroupId });
            }
            return RedirectToAction("Index", _dataBaseContext.Faculties.ToList());
        }

        public IActionResult Student(int FacultyId, int CourseId, int GroupId)
        {
            var courses = _dataBaseContext.Students
                .Include(f => f.Group.Course.Faculty)
                .Include(c => c.Group.Course)
                .Include(g => g.Group)
                .Where(s => s.GroupId == GroupId)
                .Select(s => s)
                .ToList();
            return View(courses);
        }

        [HttpGet]
        public IActionResult StudentInfo(int FacultyId, int CourseId, int GroupId, int StudentId)
        {
            if (ModelState.IsValid)
            {
                return RedirectToAction("SelectedStudent", new { FacultyId, CourseId, GroupId, StudentId });
            }
            return RedirectToAction("Index", _dataBaseContext.Faculties.ToList());
        }

        public IActionResult SelectedStudent(int FacultyId, int CourseId, int GroupId, int StudentId)
        {
            var student = _dataBaseContext.Students
                .Include(f => f.Group.Course.Faculty)
                .Include(c => c.Group.Course)
                .Include(g => g.Group)
                .FirstOrDefault(s => s.Id == StudentId);
            return View(student);
        }
    }
}
