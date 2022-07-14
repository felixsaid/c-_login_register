#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn(){
    string username, password, un, pw;

    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    ifstream read("D:\\Test\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(username == un && pw == password){
        return true;
    }else{
        return false;
    }
}

int main()
{
    int choice;
    cout << "1: Register\n2: Login\n Your choice: "; cin>> choice;

    if(choice == 1){
        string username, password;

        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;

        ofstream file;
        file.open("D:\\Test\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if(choice == 2)
    {
        bool status = IsLoggedIn();

        if(!status)
        {
            cout << "False Login!" << endl;
            system("PAUSE");
            return 0;
        }
        else{
            cout << "Successfully Logged In!";
            system("PAUSE");
            return 0;
        }
    }
    else{
        cout << "You have chosen an invalid option!." << endl;
        main();
    }
}
