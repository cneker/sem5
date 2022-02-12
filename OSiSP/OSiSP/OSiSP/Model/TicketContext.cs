using Microsoft.EntityFrameworkCore;

namespace OSiSP.Model
{
    public class TicketContext : DbContext
    {
        public DbSet<TicketModel> Tickets { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(@"Server=(localdb)\mssqllocaldb;Database=tickets;Trusted_Connection=True;");
        }
    }
}
