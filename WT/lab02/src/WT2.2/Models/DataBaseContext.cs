using Microsoft.EntityFrameworkCore;

namespace WT2._2.Models
{
    public class DataBaseContext : DbContext
    {
        public DbSet<Faculty> Faculties { get; set; }
        public DbSet<Course> Courses { get; set; }
        public DbSet<Group> Groups { get; set; }
        public DbSet<Student> Students { get; set; }

        //protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        //{
        //    optionsBuilder.UseSqlServer("Server=(localdb)\\mssqllocaldb;Database=wt2;Trusted_Connection=True");
        //}
        public DataBaseContext(DbContextOptions<DataBaseContext> options) : base(options)
        {

        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            #region Faculty
            Faculty FEIS = new Faculty()
            {
                Id = 1,
                Name = "ФЭИС"
            };
            Faculty EF = new Faculty()
            {
                Id = 2,
                Name = "ЭФ"
            };
            Faculty SF = new Faculty()
            {
                Id = 3,
                Name = "СФ"
            };
            Faculty FISE = new Faculty()
            {
                Id = 4,
                Name = "ФИСЭ"
            };
            #endregion

            #region Course
            Course first = new Course()
            {
                Id = 1,
                Name = "1",
                FacultyId = 1
            };
            Course second = new Course()
            {
                Id = 2,
                Name = "2",
                FacultyId = 2
            };
            Course third = new Course()
            {
                Id = 3,
                Name = "3",
                FacultyId = 1
            };
            Course forth = new Course()
            {
                Id = 4,
                Name = "4s",
                FacultyId = 3
            };
            #endregion

            #region Group

            Group po_4 = new Group()
            {
                Id = 1,
                Name = "ПО-4",
                CourseId = 3
            };
            Group po_5 = new Group()
            {
                Id = 2,
                Name = "ПО-5",
                CourseId = 3
            };
            Group t_90 = new Group()
            {
                Id = 3,
                Name = "Т-90",
                CourseId = 2
            };
            Group e_78 = new Group()
            {
                Id = 4,
                Name = "Е-78",
                CourseId = 1
            };
            Group pgs_2 = new Group()
            {
                Id = 5,
                Name = "ПГС-2",
                CourseId = 2
            };
            Group ooo_oao = new Group()
            {
                Id = 6,
                Name = "ООО-ОАО",
                CourseId = 3
            };
            #endregion

            #region Student

            Student st1 = new Student()
            {
                Id = 1,
                Name = "Макс",
                GroupId = 1
            };
            Student st2 = new Student()
            {
                Id = 2,
                Name = "Толя",
                GroupId = 2
            };
            Student st3 = new Student()
            {
                Id = 3,
                Name = "Ваня",
                GroupId = 1
            };
            Student st4 = new Student()
            {
                Id = 4,
                Name = "Петя",
                GroupId = 3
            };
            Student st5 = new Student()
            {
                Id = 5,
                Name = "Лёха",
                GroupId = 2
            };
            #endregion
            modelBuilder.Entity<Faculty>().HasData(FEIS, EF, SF, FISE);
            modelBuilder.Entity<Course>().HasData(first, second, third, forth);
            modelBuilder.Entity<Group>().HasData(po_4, po_5, t_90, e_78, pgs_2, ooo_oao);
            modelBuilder.Entity<Student>().HasData(st1, st2, st3, st4, st5);
            base.OnModelCreating(modelBuilder);
        }
    }
}
