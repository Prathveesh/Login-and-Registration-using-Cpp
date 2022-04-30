#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;
    cout << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t               MENU               \t\t\t" << endl;
    cout << endl;
    cout << "\t\t\t          1.REGISTRATION          \t\t\t" << endl;
    cout << endl;
    cout << "\t\t\t             2.LOGIN              \t\t\t" << endl;
    cout << endl;
    cout << "\t\t\t        3.FORGOT PASSWORD         \t\t\t" << endl;
    cout << endl;
    cout << "\t\t\t              4.EXIT              \t\t\t" << endl;
    cout << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        registration();
        break;

    case 2:
        login();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "Thank You!!" << endl;
        break;

    default:
        system("cls");
        cout << "Enter valid Choice please!!" << endl;
        main();
        break;
    }

    return 0;
}

void login() // this function is for checking the login data
{
    string loginid, loginpass, logid, logpass;
    int count = 0;
    system("cls");
    cout << "Enter USER ID : " << endl;
    cin >> loginid;
    cout << "Enter PASSWORD : " << endl;
    cin >> loginpass;

    ifstream input("log.txt"); // this is for read the input from .txt file

    while (input >> logid >> logpass)
    {
        if (logid == loginid && logpass == loginpass)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        system("cls");
        cout << "Username Password is correct and LoggedIn . " << endl;
        main();
    }
    else
    {
        system("cls");
        cout << "Username or Password or both are wrong, try again. " << endl;
        main();
    }
}

void registration() // this function is to make new data entry
{
    system("cls");
    string regid, regpass, rid, rpass;
    int count = 0;
    system("cls");
    cout << "Enter USER ID : " << endl;
    cin >> regid;
    cout << "Enter PASSWORD : " << endl;
    cin >> regpass;

    ofstream f1("log.txt", ios::app); // this is to write information to the .txt file
    f1 << regid << " " << regpass << endl;
    system("cls");
    cout << "Registration is Successfull!!." << endl;
    main();
}

void forgot() // this is for giving the password if the USER ID is correctly given
{
    int choice;

    system("cls");
    cout << "\t\t   Did you forgot PASSWORD??, Don't worry I Gotchu.." << endl;
    cout << endl;
    cout << "\t\t\t     Choose any option from bellow : \t\t\t" << endl;
    cout << endl;
    cout << "\t\t\t           1.RESET PASSWORD              \t\t\t" << endl;
    cout << endl;
    cout << "\t\t\t             2.MAIN MENU                 \t\t\t" << endl;
    cout << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        string user, uid, pw;
        int count = 0;
        cout << "Enter the USER ID that you remember!!" << endl;
        cin >> user;
        ifstream f2("log.txt");
        while (f2 >> uid >> pw)
        {
            if (uid == user)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "USER ID found!!" << endl;
            cout << "Your PASSWORD is : " << pw;
            main();
        }
        else
        {
            cout << "Sorry your account was not found." << endl;
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "Wrong choice, please try from the give options." << endl;
        forgot();
    }
}
