using System.Collections.Generic;

namespace WT2._2.Models
{
    public class Course
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public int FacultyId { get; set; }
        public Faculty Faculty { get; set; }

        public List<Group> Group { get; set; }

        public Course()
        {
            Group = new List<Group>();
        }
    }
}
