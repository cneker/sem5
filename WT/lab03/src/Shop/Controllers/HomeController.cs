using System;
using System.Security.Cryptography;
using System.Text;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Shop.Models;

namespace Shop.Controllers
{
    public class HomeController : Controller
    {
        private UserManager<UserModel> _userManager;
        private SignInManager<UserModel> _signInManager;

        public HomeController(UserManager<UserModel> userManager, SignInManager<UserModel> signInManager)
        {
            _userManager = userManager;
            _signInManager = signInManager;
        }
        
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Hash(LoginModel model) => View(model);

        [Route("MakeHash")]
        public IActionResult MakeHash(LoginModel model)
        {
            var result = new LoginModel()
            {
                Email = GetHash(model.Email),
                Password = GetHash(model.Password)
            };
            return RedirectToAction("Hash", result);
        }

        private string GetHash(string input)
        {
            var md5 = MD5.Create();
            var hash = md5.ComputeHash(Encoding.UTF8.GetBytes(input));
            return Convert.ToBase64String(hash);
        }
    }
}
