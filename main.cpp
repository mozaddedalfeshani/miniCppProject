#include <iostream>
#include <fstream>

using namespace std;

int room_fill = 0;
int row_admin;
long int data_sheet[50][3];
short int operating_choich;
int row = 0, col = 0;
void checker()
{
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
again:
    cout << "What is username?" << endl;
    cin >> user;
    cout << "what is password?" << endl;
    cin >> pass;
    if (user != "muradian" || pass != "1234")
    {
        cout << "Username or password is wrong" << endl;
        goto again;
    }
}
void room_book()
{
    ofstream file;
    string name;

    char temp;
    int temp1;
    clear(operating_choich);
    int current, i, j;

    file.open("room_info.text", ios::out | ios::app);
    file << "Room Number-"
         << "Name-"
         << "phone number below" << endl;
book_again:
    cout << "Please give legal information! " << endl;
    cout << 50 - room_fill << " room is available ! " << endl;
    cout << "Room: ";
    cin >> temp1;
    if (temp1 >= 50 || temp <= 0)
    {
        clear(operating_choich);
        cout << "Please enter valid room number" << endl;
        goto book_again;
    }
    else
    {
        temp1 = data_sheet[row][1];
    }

    cout << "Phone: ";
    cin >> data_sheet[row][1];
    cout << "Name: " << endl;
    cin >> name;

    file << "  " << data_sheet[row][0] << "\t"
         << " " << name << " " << data_sheet[row][1] << endl;
    cin.ignore();
    file.close();
    cout << "data stored" << endl;
    row++;
    room_fill++;
    cout << "1:Again book ! " << endl;
    cout << "Any other number for :Main Menu" << endl;
    cin >> temp;
    if (temp == '1')
    {
        clear(operating_choich);
        goto book_again;
    }

    system("clear");
}

void list()
{
    cout << "Welcome to Hotel Mangement" << endl;
    cout << "1:room book" << endl

         << "2: show booked room " << endl
         << "3: edit room information " << endl

         << "4 Exit" << endl;
    if (operating_choich == 2)
    {
        cout << "5: delete data (linux & OsX terminal " << endl;
    }
}

void details()
{
    int row1, col1;
    if (room_fill == 0)
    {
        cout << "Sorry! :( No room booked" << endl;
    }
    else
    {
        cout << "Number\tNid Number" << endl;
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
    system("clear");

    // login();
    // user acces

    cout << "Who you are?" << endl;
    cout << "What is your operating system" << endl;
    cout << "1: windows\t"
         << "2: Mac" << endl;

    cin >> operating_choich;
    if (operating_choich == 1)
    {
        system("cls");
    }
    else if (operating_choich == 2)
    {
        system("clear");
    }

list_again:
    if (room_fill > 45 && room_fill < 49)
    {
        cout << "Your Room Almost finished" << endl;
    }
    list();
    int choich;
    cin >> choich;

    switch (choich)
    {
    case 1:
        if (50 - room_fill == 0)
        {
            cout << "You need to delete some room!" << endl;
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
        editor();
        goto list_again;

    case 2:
        if (operating_choich == 2)
        {
            system("open room_info.text");
            system("clear");
        }
        else
        {
            details();
        }

        goto list_again;
    case 5:
        if (operating_choich == 2)
        {
            system("rm -rf room_info.text");
            system("clear");
            cout << "Your data sheet is delated! \n"
                 << endl;
        }

    default:
        cout << "Please enter valid keyword only integer allow!" << endl;
        goto list_again;
    }

    return 0;
}