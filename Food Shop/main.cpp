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
#include <vector>

using namespace std;

// Global Variable
string userId = "user";
int userPass = 1234;
string globalTempString;
int globalTempInt;

// Global Vector
vector<int> cartPrices;

// Global Array
// This is an array
int foodList[0][0];


// Global Map
// FoodCart Map
// Food card map foodCart<foodnumber, <quantity, price>>
map<int, map<int, int> /*spacing*/> foodCart;

// User Database
// user map<string, map<int,string>>
map<string, map<int, string> /*Spacing*/> userDataMap;

// userdata for saving the userpanel
map<int, map<int, string> /*spacing*/> UserListMap;

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

//Food List array inputer that can input food item

void updateFoodList(){
    int adminChoice;
    cout << "How many food you wanna update" << endl;
    std::cin >> adminChoice;
    
}
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
    cout << "UserDataEnter Function start" << endl;
    cout << "Enter The User Info" << endl
         << " userName : ";

    cin >> globalTempString;
    cout << endl
         << " userID : ";

    cin >> globalTempInt;
    // taking name and ID
    // setting up with usermap
    userDataMap["user"][globalTempInt] = globalTempString;
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
// FoodList Function
void foodList()
{

    cout << "1 : Milk" << endl
         << "2 : chips" << endl
         << "3 : chocalate" << endl;
}

// Food List Function For buy Food from Muradian Store
void buyFood()
{
    auto a = 0;
    auto choice = 0;
    auto quan = 0;
    string name = "";
    cout << "1 : Show Food List" << endl;
    cout << "2 : My Food Cart" << endl;
    cin >> a;
    if (a == 1)
    {
        foodList();
        std::cout << "Choice your food Beetween "<<endl;
        cin >> choice;
    }
}

// new Function for Everythin User Interface
void interfaceFunc()
{
    int commandForinterfaceFunc;
    cout << "1 : Buy Food Now" << endl;
    cout << "2 : setting" << endl;
    cin >> commandForinterfaceFunc;
    if (commandForinterfaceFunc == 1)
    {
        welcome();
        cout << "Here You can Easily Buy Food which is available here" << endl;
        buyFood();
    }
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
    cout << "\n"
         << endl;

level1:
    if (UserListMap.size() == 0)
    {
        if (UserListMap.size() == 0)
        {
            cout << "User_Name list is empty :( " << endl;
        }

        cout << "You Need to Resister a new user :)" << endl;
    leveluserid:
        cout << "Enter your Name: ";

        cin >> UserNameList[globalArrayNameAndlistChanger];

        cout << "Enter your unique ID: ";
        cin >> globalTempInt;
        for (int i = 0; i < (globalArrayNameAndlistChanger); i++)
        {
            if (globalTempInt == UserIdList[i])
            {
                cout << "User ID already register: " << endl;
                cout << "You should Enter Unique ID for register new user Here " << endl;
                goto level1;
            }
        }
        // Ending point of User Data Store
        UserIdList[globalArrayNameAndlistChanger] = globalTempInt;
        UserListMap[globalArrayNameAndlistChanger][globalTempInt] = UserNameList[globalArrayNameAndlistChanger];

        welcome();
        cout << "Do you wanna again save UserId: " << endl;
        cout << "1: Again\nAnyNumber for No" << endl;
        cin >> globalTempInt;
        if (globalTempInt == 1)
        {
            welcome();
            globalArrayNameAndlistChanger++;
            cout << "User Id Again start to save" << endl;
            goto leveluserid;
        }
        else
        {
            welcome();
            cout << "You Select No : That's means you won't save anything . Thank You !\n"
                 << endl;
            goto level1;
        }
    }
    else
    {
        welcome();
        cout << "You Have Enough UserData for Login here" << endl;
        interfaceFunc();
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
            cout << " \t Welcome to Muradian Food Store !" << endl;
            cout << "You Entered Wrong User or Pass ! " << endl;
            goto level2;
        }
    }

    return 0;
}