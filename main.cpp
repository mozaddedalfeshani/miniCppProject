#include <iostream>
using namespace std;
int room_fill = 0;
int data_sheet[50][2];
int row = 0, col = 0;
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

book_again:
    char temp;
    system("clear");
    int current, i, j;
    cout << "Please give legal information! " << endl;
    cout << 50 - room_fill << " room is available ! " << endl;
    // for (int i = 0; i < current; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << "Enter room and Nid_Numebr: " << endl;
    //         cin >> data_sheet[i][j];
    //     }
    //
    // }

    cout << "Room: ";
    cin >> data_sheet[row][0];
    cout << "Nid: ";
    cin >> data_sheet[row][1];
    row++;
    room_fill++;
    cout << "1:Again book ! " << endl;
    cout << "Any other key :Main Menu" << endl;
    cin >> temp;
    if (temp == '1')
    {
        goto book_again;
    }
    system("clear");
}

void list()
{
    cout << "Welcome to Hotel Mangement" << endl;
    cout << " 1:room book" << endl
         << "2: show booked room " << endl
         << "3: edit room information " << endl
         << "4 Exit" << endl;
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
    ;

    login();
    system("clear");
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
        details();
        goto list_again;
    default:
        cout << "Please enter valid keyword" << endl;
        goto list_again;
    }

    return 0;
}