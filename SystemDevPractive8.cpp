#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Employee {
    char name[255];

    union {
        struct {
            char spouse_name[255];
        } married;
        struct {
            int divorce_year;
        } divorced;
    } marital_status;
};

Employee employees[3];

int main() {

    setlocale(LC_ALL, "RU");


    strcpy_s(employees[0].name, "Петр Петрович");
    strcpy_s(employees[0].marital_status.married.spouse_name, "Mария Михайловна");

    strcpy_s(employees[1].name, "Иван Иванов");

    strcpy_s(employees[2].name, "Дмитрий Журавлёв");
    employees[2].marital_status.divorced.divorce_year = 2019;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (employees[i].name < employees[j].name)
            {
                Employee buf = employees[i];
                employees[i] = employees[j];
                employees[j] = buf;
            }
        }
    }

    cout << "Список сотрудников:" << endl;

    for (short i = 0; i < 3; i++)
    {
        Employee item = employees[i];
        
        if (string(item.marital_status.married.spouse_name) != "") {
            cout << item.name << " (разведен с " << item.marital_status.divorced.divorce_year << " года)" << endl;
        }
        else if (item.marital_status.divorced.divorce_year > 0) {
            cout << item.name << " (супруг(а): " << item.marital_status.married.spouse_name << ")" << endl;
        }
        else {
            cout << item.name << " (не состоял в браке)" << endl;
        }

    }

    return 0;
}
