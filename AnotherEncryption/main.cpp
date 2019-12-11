//
//  main.cpp
//  AnotherEncryption
//
//  Created by Agni Earasi on 12/11/19.
//  Copyright © 2019 Agni Earasi. All rights reserved.
//

#include "encryption.h"
#include <iostream>
#include <fstream>
using namespace std;
string get_filename();
int encrypt_file(string);
int decrypt_file(string);

int main(int argc, const char * argv[]) {
   
    bool done = false;
        while (!done)
        {
            cout << "1) Encrypt\n2) Decrypt\n3) Exit\n\n";
            cout << "Enter an option number: ";

            int option;
            while (!(cin >> option))
            {
                cout << "Error: enter a number: ";
                cin >> option;
                cin.clear();
                cin.ignore(123, '\n');
            }

            switch (option)
            {
            case 1:
            {
                string file_name = get_filename();
                encrypt_file(file_name);
                break;
            }
            case 2:
            {
                string file_name = get_filename();
                decrypt_file(file_name);
                break;
            }
            case 3:
            {
                done = true;
                break;
            }
            default:
            {
                cout << "That was not a valid option\n";
                break;
            }
            }
            cout << endl;
        }
    }

    string get_filename()
    {
        cout << "Enter full path to file: \n";
        string file_name;
        cin >> file_name;
        cout << endl;
        return file_name;
    }

    int encrypt_file(string file_name)
    {

        ifstream myfile(file_name);
        cout << "Encrypting " << file_name << "...\n";

        if (myfile.is_open())
        {
            string line;
            string result = "";
            while (getline(myfile, line))
            {
                result += encrypt(line);
            }
            cout << "Result: " << result << endl;
            myfile.close();

            ofstream outfile(file_name, ios_base::out);
            outfile << result;
        }
        else
        {
            cerr << "Can't open input file!";
            return 1;
        }

        cout << "Done.\n";
        return 0;
    }

    int decrypt_file(string file_name)
    {
        ifstream myfile(file_name);
        cout << "Decrypting " << file_name << "...\n";

        if (myfile.is_open())
        {
            string line;
            string result = "";
            while (getline(myfile, line))
            {
                result += decrypt(line);
            }
            cout << "Result: " << result << endl;
            myfile.close();

            ofstream outfile(file_name, ios_base::out);
            outfile << result;
        }
        else
        {
            cerr << "Can't open input file!";
            return 1;
        }

        cout << "Done.\n";
        return 0;
    
    
    
}
