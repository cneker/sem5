using Microsoft.EntityFrameworkCore;

namespace WT1.Models
{
    public class PersonContext : DbContext
    {
        public DbSet<Person> Persons { get; set; }

        public PersonContext(DbContextOptions<PersonContext> options) : base(options)
        {

        }

    }
}
