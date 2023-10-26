#include <iostream>
#include <map>
#include <string>
using namespace std;

bool checkAn(string str1, string str2)
{
    bool rez = false;
    if (str1.size() != str2.size())
    {
        rez = false;
    }
    else
    {
        multimap<char, int> mStr1;
        multimap<char, int> mStr2;
        for (int i = 0; i < str1.size(); i++)
        {
            pair<char, int> oP((char)str1[i], i);
            mStr1.insert(oP);
            pair<char, int> oP2((char)str2[i], i);
            mStr2.insert(oP2);
        }
        multimap<char, int>::iterator it = mStr1.begin();
        for (it; it != mStr1.end(); it++)
        {
            multimap<char, int>::iterator it2 = mStr2.begin();
            for (it2; it2 != mStr2.end(); it2++)
            {
                if (it->first == it2->first)
                {
                    mStr2.erase(it2);
                    break;
                }
            }
        }
        if (mStr2.size() == 0)
        {
            rez = true;
        }
        else
        {
            rez = false;
        }
    }
    return rez;
}

int main()
{
    string str1;
    string str2;
    cout << "Введите первое слово: ";
    cin >> str1;
    cout << "Введите второе слово: ";
    cin >> str2;

    if (checkAn(str1, str2))
    {
        cout << "Слово " << str2 << " является анаграммой слова " << str1 << endl;
    }
    else
    {
        cout << "Слово " << str2 << " не является анаграммой слова " << str1 << endl;
    }
}