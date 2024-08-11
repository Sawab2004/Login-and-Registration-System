#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

bool fileExists(const string& filename) 
{
    ifstream file(filename);
    return file.good();
}

void registerUser() 
{
    string username, password;
    cout << "Enter a new username: ";
    getline(cin, username);
    cout << "Enter a new password: ";
    getline(cin, password);

    string filename = username + ".txt";
    if (fileExists(filename)) {
        cout << "Username already exists. Please choose a different username." << endl;
    }
    else {
        ofstream file(filename);
        file << password;
        file.close();
        cout << "Registration successful!" << endl;
    }
}

void loginUser() 
{
    string username, password;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);

    string filename = username + ".txt";
    if (fileExists(filename)) 
    {
        ifstream file(filename);
        string storedPassword;
        getline(file, storedPassword);
        file.close();
        if (password == storedPassword) 
        {
            cout << "Login successful!" << endl;
        }
        else 
        {
            cout << "Incorrect password. Please try again." << endl;
        }
    }
    else {
        cout << "Username does not exist. Please register first." << endl;
    }
}

int main() {
    int choice;

    while (true) 
    {
        cout << "\nLogin and Registration System" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) 
        {
        case 1:
        {
            registerUser();
            break;
        }
        case 2:
        {
            loginUser();
            break;
        }
        case 3:
        {
            cout << "Exiting the system..." << endl;
            return 0;
        }
        default:
        { 
            cout << "Invalid choice! Please try again." << endl; 
        }

        }
    }

    return 0;
}
