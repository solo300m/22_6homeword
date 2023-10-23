#include <iostream>
#include <map>
#include <string>

using namespace std;
int main()
{
    multimap<string, int> regList;
    multimap<string, int> &ptrReg = regList;
    int count = 0;
    while (true)
    {
        string enter;
        cout << "Введите фамилию и имя через пробел для включения в электронный список или Next для вызова из списка " << endl;
        cout << "-> ";
        cin >> enter;
        if (enter != "Next")
        {
            count++;
            pair<string, int> oP(enter, count);
            ptrReg.insert(oP);
        }
        else
        {
            if (count != 0)
            {
                multimap<string, int>::iterator it = regList.begin();
                cout << "<- " << it->first << endl;
                regList.erase(it);
                count--;
            }
            else
            {
                cout << "В списке нет посетителей. Программа завершает работу..." << endl;
                break;
            }
        }
    }
}
