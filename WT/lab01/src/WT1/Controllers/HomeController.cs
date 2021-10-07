using System.Linq;
using Microsoft.AspNetCore.Mvc;
using WT1.Models;

namespace WT1.Controllers
{
    public class HomeController : Controller
    {
        private PersonContext _personContext;

        public HomeController(PersonContext personContext)
        {
            _personContext = personContext;
        }


        public IActionResult Index()
        {

            return View(_personContext.Persons.ToList());
        }

        [HttpGet]
        public IActionResult First(Person person)
        {
            if (ModelState.IsValid)
            {
                var person1 = _personContext.Persons.FirstOrDefault(p => p.Name == person.Name);
                if (person1 == null)
                {
                    _personContext.Add(person);
                    _personContext.SaveChanges();
                    person1 = _personContext.Persons.FirstOrDefault(p => p.Name == person.Name);
                }
                return View(person1);
            }
            return View(person);
        }

        public IActionResult Second()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Third(string Action, string PersonId)
        {
            if (ModelState.IsValid)
            {
                return RedirectToAction(Action, new {PersonId});
            }

            return RedirectToAction("Index");
        }

        public IActionResult Insert()
        {
            return View();
        }

        public IActionResult Update(int personId)
        {
            return View(_personContext.Persons.FirstOrDefault(p => p.Id == personId));
        }

        [HttpPost]
        public IActionResult Update(Person person)
        {
            if (ModelState.IsValid)
            {
                var temp = _personContext.Persons.FirstOrDefault(p => p.Id == person.Id);
                if (temp != null)
                {
                    temp.Name = person.Name;
                    temp.Comments = person.Comments;
                    temp.Department = person.Department;
                    temp.Email = person.Email;
                    temp.Phone = person.Phone;
                    temp.Position = person.Position;
                    temp.Sex = person.Sex;
                    _personContext.SaveChanges();
                }
            }
            return RedirectToAction("Index", _personContext.Persons.ToList());
        }

        public IActionResult Delete(int personId)
        {
            if (ModelState.IsValid)
            {
                _personContext.Remove(_personContext.Persons.FirstOrDefault(p => p.Id == personId));
                _personContext.SaveChanges();
            }

            return RedirectToAction("Index", _personContext.Persons.ToList());
        }

        [HttpPost]
        public IActionResult Insert(Person person)
        {
            if (ModelState.IsValid)
            {
                var person1 = _personContext.Persons.FirstOrDefault(p => p.Name == person.Name);
                if (person1 == null)
                {
                    _personContext.Add(person);
                    _personContext.SaveChanges();
                }
            }

            return RedirectToAction("Index", _personContext.Persons.ToList());
        }
    }
}
