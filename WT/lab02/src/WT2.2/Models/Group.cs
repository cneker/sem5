using System.Collections.Generic;

namespace WT2._2.Models
{
    public class Group
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public int CourseId { get; set; }
        public Course Course { get; set; }

        public List<Student> Student { get; set; }

        public Group()
        {
            Student = new List<Student>();
        }
    }
}
