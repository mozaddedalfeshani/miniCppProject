#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <list>
#include <string>
#include <iomanip>
using namespace std;

// Global Variable
string userId = "user";
int userPass = 1234;
string globalTempString;
int globalTempInt;
// Global Map
map<string, int> userData;
// This Function for user panel
void userMenuList()
{
    cout << "1 -->  Sell Food" << endl;
    cout << "2 --> Exit" << endl;
}
// This Function for admin panel
void adminMenuList()
{
    cout << "1 : Set Food Code " << endl
         << "2 : Delete Food" << endl;
}
// Admin Panel Function
//  this have admin power
void adminPanel()
{
    cout << "1 : Enter the Food Data" << endl
         << "2 : Set User" << endl;

    cin >> globalTempInt;
    if(globalTempInt == 2){
        //setting up userdata
        
    }
}
// this fuction for cleaning the screen
int clearTerminal()
{

#if defined(__linux__) // Or #if __linux__
    return system("clear");
#elif __FreeBSD__
    std::cout << "Hello, FreeBSD!" << '\n';
#elif __ANDROID__
    std::cout << "Hello, Android!" << '\n';
#elif __APPLE__
    return system("clear");
#elif _WIN32
    return system("cls");
#else
    std::cout << "Hello, Other!" << '\n';
#endif
}
/*
Starting The MainFunction
*/
int main()
{

    // variable part

    int commands, casecommand;

    // temp variable
    int tempNum;
    string tempString;
    float tempFloat;

    // start programm
    clearTerminal();
    cout << " \tWelcome to Muradian Food Store !" << endl;

level1:
    if (userData.size() != 0)
    {
        cout << "1 : User" << endl
             << "2 : Admin" << endl;

        cin >> commands;
    }
    else
    {
        printf("adminPanel");
    }

level2:
    if (commands == 1)
    {
        cout << "Enter your ID" << endl;
        cin >> tempNum;
    }
    else if (commands == 2)
    {

        cout << "Enter The Username" << endl;
        cin >> tempString;
        cout << "Enter the User Password" << endl;
        cin >> tempNum;
        // check it's right or wrong
        if (tempString == userId && tempNum == userPass)
        {
            adminMenuList();
        }
        else
        {
            clearTerminal();
            cout << " \tWelcome to Muradian Food Store !" << endl;
            cout << "You Entered Wrong User or Pass ! " << endl;
            goto level2;
        }
    }

    return 0;
}