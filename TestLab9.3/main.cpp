#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <Windows.h>
using namespace std;
#define N 1

struct note
{
    char name[100];
    char phone[50];
    int date[3];
} info[8]; 

void Sort(void)
{
    int i, k, Date1, Date2;
    k = N - 1;
    bool fs = true;
    while (fs)
    {
        fs = false;
        for (i = 0; i < k; i++)
        {
            Date1 = info[i].date[2] * 10000 + info[i].date[1] * 100 + info[i].date[0];
            Date2 = info[i + 1].date[2] * 10000 + info[i + 1].date[1] * 100 + info[i + 1].date[0];
            if (Date1 < Date2)
            {
                struct note Tmp;
                Tmp = info[i];
                info[i] = info[i + 1];
                info[i + 1] = Tmp;
                fs = true;
            }
        }
        k--;
        if (k < 0) fs = false;
    }
}

int main(void) {
    int i, j;
    char phone[50];
    for (i = 0; i < N; ++i)
    {
        cout << "\n\t---- " << i + 1 << " ---\n Name :";
        cin.ignore();
        cin.get(info[i].name, 100);
        cout << "Phone number : ";
        cin.ignore();
        cin.get(info[i].phone, 50);
        cout << " Date :\nNumber> ";
        cin >> info[i].date[0];
        cout << "month >> ";
        cin >> info[i].date[1];
        cout << "Year >> ";
        cin >> info[i].date[2];
    }
    Sort();

    for (i = 0; i < N; ++i) {
        cout << "\n----------------------------------------------\n";
        cout << "Name : " << setw(20) << info[i].name << endl
            << "Phone: " << setw(20) << info[i].phone << endl
            << "Birthday :" << endl
            << setw(30) << "Day   >> " << info[i].date[0] << endl
            << setw(30) << "Month >> " << info[i].date[1] << endl
            << setw(30) << "Year  >> " << info[i].date[2] << endl;
    }
    cout << "Enter a phone number :";
    cin.ignore();
    cin.get(phone, 50);
    for (i = 0, j = 0; i < N; i++)
        if (strcmp(info[i].phone, phone) == 0)
            ++j;
    if (j > 0) {

        cout << "\n----------------------------------------------\n";
        for (i = 0; i < N; ++i) {
            if (strcmp(info[i].phone, phone) == 0) {
                cout << "Name   " << setw(20) << info[i].name << endl
                    << "Birthday :" << endl
                    << setw(30) << "Day  >> " << info[i].date[0] << endl
                    << setw(30) << "Month >> " << info[i].date[1] << endl
                    << setw(30) << "Year  >> " << info[i].date[2] << endl;
            }
            else continue;
            cout << endl;
        }
    }
    else
        cout << "Number " << phone << "Not in the list\n";
    cout << "Press any key\n";
    getch();
    return 0;
}