#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void createItem(string number, string name, map<string, vector<string>> &ptrBook)
{
    if (ptrBook.count(name) == 0)
    {
        vector<string> tmp;
        tmp.push_back(number);
        pair<string, vector<string>> oP(name, tmp);
        ptrBook.insert(oP);
    }
    else
    {
        cout << "Пользователь с именем " << name << " уже существует";
    }
}
void addNumber(string number, string name, map<string, vector<string>> &ptrBook)
{
    if (ptrBook.count(name) != 0)
    {
        ptrBook.find(name)->second.push_back(number);
    }
    else
    {
        cout << "Пользователь с именем " << name << " не существует в списке";
    }
}
vector<string> findNumber(string name, map<string, vector<string>> &ptrBook)
{
    vector<string> rez;
    if (ptrBook.count(name) != 0)
    {
        rez = ptrBook.find(name)->second;
        return rez;
    }
    else
    {
        cout << "Нет такого пользователя в списке...";
        return rez;
    }
}
string findName(string number, map<string, vector<string>> &ptrBook)
{
    string rez = "No-Name";
    map<string, vector<string>>::iterator it = ptrBook.begin();
    for (it; it != ptrBook.end(); it++)
    {
        for (string s : it->second)
        {
            if (s == number)
            {
                rez = it->first;
                return rez;
            }
        }
    }
    return rez;
}
void displayBook(map<string, vector<string>> &ptrBook)
{
    map<string, vector<string>>::iterator it = ptrBook.begin();
    for (it; it != ptrBook.end(); it++)
    {
        cout << "Имя: " << it->first << endl;
        for (string s : it->second)
        {
            cout << "Номер - " << s << endl;
        }
    }
}

int main()
{
    map<string, vector<string>> telBook;
    map<string, vector<string>> &ptrBook = telBook;
    int choice = 1;
    while (choice != 0)
    {
        cout << "Выберите операцию справочника: \n1 - добавить пару \"Имя, телефон\", \n2 - добавить дополнительный номер в стравочник, \n3 - наити телефон по фамилии, \n4 - найти фамилию по номеру телефона. \n0 - выход из программы ";
        cin >> choice;
        string number;
        string name;
        switch (choice)
        {
        case 1:
        {
            cout << "Введите через пробел номер телефона и имя ";
            cin >> number >> name;
            createItem(number, name, ptrBook);
            displayBook(ptrBook);
            break;
        }
        case 2:
        {
            cout << "Введите через пробел номер телефона и имя ";
            cin >> number >> name;
            addNumber(number, name, ptrBook);
            displayBook(ptrBook);
            break;
        }
        case 3:
        {
            cout << "Введите имя ";
            cin >> name;
            vector<string> rez;
            rez = findNumber(name, ptrBook);
            if (rez.size() != 0)
            {
                cout << "У пользователя " << name << " найдены следующие номера: " << endl;
                for (string s : rez)
                {
                    cout << "Номер - " << s << endl;
                }
            }
            else
            {
                cout << "Не найдено ни чего..." << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Введите номер телефона ";
            cin >> number;
            string fName;
            fName = findName(number, ptrBook);
            if (fName != "No-Name")
            {
                cout << "По номеру " << number << " найден следующий пользователь " << fName << endl;
            }
            else
            {
                cout << "Ни чего не найдено..." << endl;
            }
            break;
        }
        case 0:
        {
            cout << "Выход из программы...";
            break;
        }
        default:
            cout << "Не верный ввод. Повторите еще раз!";
            break;
        }
    }
}