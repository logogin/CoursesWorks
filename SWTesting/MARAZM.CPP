#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <assert.h>

bool flagin;
bool flagout;

ifstream in_file;
ofstream out_file;

bool check_number(const int n)
{
    int number = n;
    int digit;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        digit = number % 10;
        number /= 10;
        digit = digit * digit * digit * digit;
        sum += digit;
    }
    if (sum == n)
        return true;
    else
        return false;
}

void check_segment()
{
    for (int i = 1000; i <= 9999; i++)
        if (check_number(i))
            if (flagout)
                cout << i << endl;
            else
                out_file << i << endl;
}

void request()
{
    int choice;
    int number;
    if (flagin)
    {
        cout << "Enter your choice : ";
        cin >> choice;
    }
    else
        in_file >> choice;
    switch (choice)
    {
    case 1:
        if (flagin)
        {
            cout << "Enter number for checking : ";
            cin >> number;
        }
        else
            in_file >> number;
        if (check_number(number))
            if (flagout)
                cout << "The Number is matching to the rule." << endl;
            else
                out_file << "The Number is matching to the rule.";
        else if (flagout)
            cout << "The Number is not matching to the rule." << endl;
        else
            out_file << "The Number is not matching to the rule.";
        break;
    case 2:
        check_segment();
        break;
    }
}

void main(int argn, char **argv)
{
    assert(argn == 3);
    if (!strcmp(argv[1], "stdin"))
        flagin = true;
    else
    {
        in_file.open(argv[1]);
        assert(in_file);
    }
    if (!strcmp(argv[2], "stdout"))
        flagout = true;
    else
    {
        out_file.open(argv[2]);
        assert(out_file);
    }
    request();
    if (!flagin)
        in_file.close();
    if (!flagout)
        out_file.close();
}