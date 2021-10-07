using System.Collections.Generic;

namespace WT2._2.Models
{
    public class Faculty
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public List<Course> Courses { get; set; }

        public Faculty()
        {
            Courses = new List<Course>();
        }
    }
}
