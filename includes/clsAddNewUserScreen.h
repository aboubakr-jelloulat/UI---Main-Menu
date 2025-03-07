#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser &User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\n🆔 User Card:";
		cout << "\n───────────────────";
		cout << "\n📝 First Name   : " << User.FirstName;
		cout << "\n📝 Last Name    : " << User.LastName;
		cout << "\n📛 Full Name    : " << User.FullName();
		cout << "\n📧 Email        : " << User.Email;
		cout << "\n📞 Phone        : " << User.Phone;
		cout << "\n👤 User Name    : " << User.UserName;
		cout << "\n🔒 Password     : " << User.Password;
		cout << "\n🛠️ Permissions  : " << User.Permissions;
		cout << "\n───────────────────\n";
	}

	static int _ReadPermissionsToSet()
	{

		int Permissions = 0;
		char Answer = 'n';

		cout << "\nDo you want to give full access? y/n? ";  cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";  cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";  cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";  cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";   cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";  cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";  cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";  cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register? y/n? ";   cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowLogInRegister;
        }


		return Permissions;
	}

public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t  Add New User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName Is Already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();
		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Addeded Successfully ✅\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError User was not saved because it's Empty ❌";
			break;
		}
		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "\nError User was not saved because UserName is used❌\n";
			break;
		}
		}
	}
};
