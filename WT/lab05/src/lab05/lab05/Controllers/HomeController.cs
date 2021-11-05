using lab05.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using System.Diagnostics;
using System.Linq;
using System.IO;
using Microsoft.AspNetCore.Http;

namespace lab05.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly Context _context;

        public HomeController(ILogger<HomeController> logger, Context context)
        {
            _logger = logger;
            _context = context;
        }

        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }

        public IActionResult First() => View();
        public IActionResult Second() => View();
        public IActionResult Third() => View();
        public IActionResult Forth() => View();
        [HttpPost]
        public IActionResult Fifth(IFormFile file)
        {
            if (file == null)
                return View();
            if (file.Length < 100000)
            {
                var asas = new FileInfo(file.FileName);
                ViewBag.Length = file.Length;
                ViewBag.Dir = asas.DirectoryName;
                ViewBag.Name = asas.Name;
                ViewBag.Ext = asas.Extension;
                ViewBag.Create = asas.CreationTime;
                ViewBag.Modify = asas.LastAccessTime;
            }
            return View();
        }
        public IActionResult Six() => View();
        public IActionResult Seven() => View();
        public IActionResult Eight() => View();
        public IActionResult Nine() => View();
        [HttpPost]
        public IActionResult Ten(IFormFile image)
        {
            if (image != null)
            {
                var temp = new FileInfo(image.FileName);
                if (temp.Extension == ".jpg" || temp.Extension == ".gif")
                {
                    string path = Path.Combine(Directory.GetCurrentDirectory(), "wwwroot", image.FileName);
                    image.CopyTo(new FileStream(path, FileMode.Create));
                    _context.Add(new Modell() {FilePath = image.FileName});
                    _context.SaveChanges();
                    var img = _context.Tbl.FirstOrDefault(m => m.FilePath == image.FileName);
                    if (img != null)
                    {
                        return View("Show", img.FilePath);
                    }
                }
            }
            return View();
        }

        public IActionResult Show(string path) => View(model:path);
    }
}
