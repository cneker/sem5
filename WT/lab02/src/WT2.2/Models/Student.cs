﻿namespace WT2._2.Models
{
    public class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public int GroupId { get; set; }
        public Group Group { get; set; }
    }
}
