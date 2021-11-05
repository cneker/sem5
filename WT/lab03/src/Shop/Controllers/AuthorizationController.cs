using Microsoft.AspNetCore.Mvc;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Identity;
using Shop.Models;

namespace Shop.Controllers
{
    public class AuthorizationController : Controller
    {
        private UserManager<UserModel> _userManager;
        private SignInManager<UserModel> _signInManager;

        public AuthorizationController(UserManager<UserModel> userManager, SignInManager<UserModel> signInManager)
        {
            _userManager = userManager;
            _signInManager = signInManager;
        }

        public IActionResult Registration()
        {
            ViewBag.Title = "Shop";
            return View();
        }

        [HttpPost]
        
        public async Task<IActionResult> Registration(RegistrationModel model)
        {
            if (ModelState.IsValid)
            {
                var temp = await _signInManager.UserManager.FindByEmailAsync(model.Email);
                if (temp == null)
                {
                    UserModel user = new UserModel() {Email = model.Email, UserName = model.NickName};
                    var result = await _userManager.CreateAsync(user, model.Password);
                    if (result.Succeeded)
                        await _signInManager.SignInAsync(user, false);
                    return RedirectToAction(actionName: "Index", controllerName: "Home");
                }
                ModelState.AddModelError("err", "This user already exists");
            }
            return View(model);
        }

        public IActionResult Authorize() => View();

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Authorize(LoginModel model)
        {
            var user = await _signInManager.UserManager.FindByEmailAsync(model.Email);
            if (user != null)
            {
                var result = await _signInManager.PasswordSignInAsync(user.UserName, model.Password, false, false);
                if (result.Succeeded)
                    return RedirectToAction(actionName: "Index", controllerName: "Home");
            }

            return RedirectToAction(actionName: "Authorize", controllerName: "Authorization");
        }

        public async Task<IActionResult> LogOut()
        {
            await _signInManager.SignOutAsync();
            return RedirectToAction(actionName: "Index", controllerName: "Home");
        }
    }
}
