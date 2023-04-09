#include <iostream>
#include <fstream>
#include <limits>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <cctype>
using namespace std;

int room_fill = 0;
int row_admin;
long int data_sheet[50][3];
short int operating_choich;
int row = 0, col = 0;
// function start
int checkString(string value)
{
    int l;

    for (int i = 1; i < value.length(); i++)
    {

        if (isdigit(value[i]))
        {
            l = true;
        }
        else
        {
            l = false;
            break;
        }
        return l;
    }
    return l;
}
int fileOpen()
{
#if defined(__linux__) // Or #if __linux__
    return 2;

#elif __APPLE__
    return 2;
#elif _WIN32

    return 1;
#else
    std::cout << "Hello, Other!" << '\n';
#endif
}

int clean()
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

int clear(int operating_choich1)
{
    if (operating_choich1 == 1)
    {
        return system("cls");
    }
    else if (operating_choich1 == 2)
    {
        return system("clear");
    }
    return 1;
}

void login()
{
    string user, pass;
    time_t givemetime = time(NULL);
    printf("\t\t\t%s", ctime(&givemetime));
again:
    cout << "What is username? ";

    cin >> user;
    cout << "what is password? ";
    cin >> pass;
    if (user != "dip" || pass != "1234")
    {
        cout << "\t\t\aUsername or password is wrong" << endl;
        goto again;
    }
}
void room_book()
{
    ofstream file;
    string name;

    string phoneNumber;
    char temp;
    string temp1;
    clean();
    
    int current, i, j;

    file.open("room_info.text", ios::out | ios::app);
    
book_again:
    cout << "\t\tPlease give legal information! " << endl;
    cout << 50 - room_fill << " room is available ! " << endl;
    cout << "Room: ";
    cin >> temp1;
    if (checkString(temp1))
    {
        if ((stoi(temp1) >= 50 || (stoi(temp1)) <= 0))
        {
            // clear(operating_choich);
            clean();
            cout << "\t\tPlease enter valid room number" << endl;
            goto book_again;
        }
        else
        {
            data_sheet[row][0] = stoi(temp1);
        }
    }
    else
    {
        clean();
        cout << "Please enter integer number (1~50)" << endl;
        goto book_again;
    }

repeatPhone:
    cout << "Phone Number: ";
    // cin >> data_sheet[row][1];
    cin >> phoneNumber;

    if (checkString(phoneNumber) == false)
    {
        cout << "\t\tPlease enter all postive integer number!" << endl;

        goto repeatPhone;
    }
    else if (checkString(phoneNumber) == true)
    {
        data_sheet[row][1] = stoi(phoneNumber);
    }

// name entered
name_again:
    cout << "Name: " << endl;
    // cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    if (name.length() < 20)
    {
        file << "Room: " << data_sheet[row][0] << " "
             << " Name: " << name << " Phone: " << data_sheet[row][1] << endl;

        file.close();
    }
    else
    {
        cout << "\t\tName limit wrong! Write in 18 words" << endl;
        goto name_again;
    }

    cout << "data stored" << endl;
    row++;
    room_fill++;
    cout << "1:Again book ! " << endl;
    cout << "Any other number for :Main Menu" << endl;
    cin >> temp;
    if (temp == '1')
    {
        clean();
        
        goto book_again;
    }

    clean();
    // system("clear");
}

void list()
{
    cout << "\t\t\tWelcome to Hotel Mangement" << endl;
    cout << "1: room book" << endl

         << "2: show booked room " << endl
         << "3: edit room information " << endl

         << "4 Exit" << endl;
    if (fileOpen() == 2)
    {
        cout << "5: delete dataheets " << endl;
    }
}

void details()
{
    int row1, col1;
    if (room_fill == 0)
    {
        clean();
        cout << "\n\t\tSorry! :( No room booked" << endl;
    }
    else
    {
        cout << "Room\tPhone Number" << endl;
        for (row1 = 0; row1 < room_fill; row1++)
        {
            for (col1 = 0; col1 < 2; col1++)
            {
                cout << data_sheet[row1][col1] << "\t";
            }
            cout << endl;
        }
    }
}
// sercing funtion

// editing array information
void editor()
{
ss:
    cout << "Searching style:" << endl;
    cout << "1:room number" << endl;

    int choich1, rn;

    cin >> choich1;
    for (int i = 0; i < room_fill; i++)
    {
        if (choich1 == data_sheet[i][0])
        {
            cout << "Present room : " << data_sheet[i][0] << endl;
            cout << "New Room Number : ";
            cin >> data_sheet[i][0];
            cout << "Present Nid Number : " << data_sheet[i][1] << endl;
            cout << "New nid Numeber : ";
            cin >> data_sheet[i][1];
        }
    }
}

int main()
{
    clean();
    // login function
    login();
    // auto clean
    clean();

list_again:
    if (room_fill > 45 && room_fill < 49)
    {
        cout << "\t\tYour Room Almost finished" << endl;
    }
    list();
    int choich;
    cin >> choich;

    switch (choich)
    {
    case 1:
        if (50 - room_fill == 0)
        {
            cout << "\t\tYou need to delete some room!" << endl;
            goto list_again;
        }
        else
        {
            room_book();
        }

        goto list_again;
    case 4:
        return 0;
    case 3:
        clean();
        cout << "\t\tDear , this system come very soon" << endl;
        // editor();
        goto list_again;

    case 2:
        if (fileOpen() == 2)
        {
            system("open room_info.text");
            clean();
        }
        else if (fileOpen() == 1)
        {
            details();
        }

        goto list_again;
    case 5:
        if (fileOpen() == 2)
        {
            system("rm -rf room_info.text");
            clean();
            // system("clear");
            cout << "\t\t   ##Your data sheet is delated! ##\n"
                 << endl;
        }

    default:
        cout << "\t\tPlease enter valid keyword only integer allow!" << endl;
        goto list_again;
    }

    return 0;
}