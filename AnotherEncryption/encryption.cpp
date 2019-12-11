//
//  encryption.cpp
//  AnotherEncryption
//
//  Created by Agni Earasi on 12/11/19.
//  Copyright © 2019 Agni Earasi. All rights reserved.
//

#include <string>

using namespace std;

string encrypt(string data)
{
    string result;
    for (char &c : data)
    {
        int ascii_val = c;
        ascii_val++;
        c = ascii_val;
        result += c;
    }
    return result;
}

string decrypt(string data)
{
    string result;
    for (char &c : data)
    {
        int ascii_val = c;
        ascii_val--;
        c = ascii_val;
        result += c;
    }
    return result;
}

