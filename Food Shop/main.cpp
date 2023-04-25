#include <iterator>
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

// Global Array for saving UserId
// int array[];

// Global Map

// User Database
// user map<string, map<int,string>>
map<string, map<int, string> /*Spacing*/> userData;

// userid array value
int globalArrayNameAndlistChanger = 0;

// Array For Store the user name
string UserNameList[1];

// Array for storing user id
int UserIdList[1];

// This map function for user database
map<int, map<string, int> /*spacing*/> foodData;

// Funtion area

// this fuction for cleaning the screen
// this function will autometically call differect by system confiq
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
// Welcome Message
void welcome()
{
    clearTerminal();
    cout << "Welcome to Muradian Food World" << endl;
}

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
void userDataEnter()
{
    // setting up userdata
    // clearTerminal();
    cout << "Enter The User Info" << endl
         << " userName : ";

    cin >> globalTempString;
    cout << endl
         << " userID : ";

    cin >> globalTempInt;
    // taking name and ID
    // setting up with usermap
    userData["user"][globalTempInt] = globalTempString;
    welcome();
    cout << "Saved Successfully" << endl;
}
// Food Data Input map<int, map<String , int> > fooddata
// FoodID<foodName, foodPrices>
void foodDataEnter()
{
    string foodName;
    int foodCode, foodPrice;
    cout << "Enter The FoodID" << endl;
    cin >> foodCode;
    cout << "Enter the FoodName" << endl;
    cin >> foodName;
    cout << "Enter the Food Prices" << endl;
    cin >> foodPrice;
    // maps are updating
    foodData[foodCode][foodName] = foodPrice;
}

int main()
{

    // variable part

    int commands, casecommand;

    // temp variable
    int tempNum;
    string tempString;
    float tempFloat;

    // start programm
    welcome();

level1:
    if (userData.size() != 0)
    {
        cout << "User_Name list is empty :( " << endl;
        cout << "You Need to Resister a new user :)" << endl;
        cout << "Enter your Name: ";
        cin >> UserNameList[globalArrayNameAndlistChanger];

    userid:
        cout << "Enter your unique ID: ";
        cin >> globalTempInt;
        for (int i = 0; i < UserIdList.size; i++)
        {
            if (globalTempInt == UserIdList[i])
            {
                cout << "User ID already register: " << endl;
                goto userid;
            }
        }
        UserIdList[globalArrayNameAndlistChanger] == globalTempInt;
        globalArrayNameAndlistChanger++;
        welcome();
        cout << "Do you wanna again save UserId: " << endl;
        cin >> globalTempInt;
        if (globalTempInt == 1)
        {
            cout << "User Id Again start to save" << endl;
        }
        else
        {
            welcome();
            goto level1;
        }
    }
    else
    {
        userDataEnter();
        goto level1;
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