#pragma one
#include "Global.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
class clsLoginScreen :protected clsScreen
{

private :

  static  void _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        do
        {
            if (LoginFaild)
                cout << "\nInvlaid Username/Password!\n\n";

            cout << "Enter Username? ";  cin >> Username;

            cout << "Enter Password? ";  cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        clsMainScreen::ShowMainMenue();
    }

public:

    static void ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};
