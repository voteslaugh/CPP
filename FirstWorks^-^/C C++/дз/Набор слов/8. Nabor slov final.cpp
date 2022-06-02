#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool match(string arr1, string arr2, int n1, int n2)
{
    for (int i=0; i<n1; i++)
    {
        for (int j=0; j<n2; j++)
        {
            if (arr1[i] == arr2[j]) return true;
        }
    }
    return false;
}

void reading(string& s) {
    setlocale(LC_ALL, "rus");
    fstream file;
    file.open("file.txt", fstream::in | fstream::out | fstream::app);
    if (!file) {
        cout << "Ошибка чтения файла" << endl;
    }
    else {
        while (!file.eof())
        {
            s = "";
            getline(file, s);
        }
    }
}

int main()
{
    string s;
    reading(s);
    int n = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            n++;
        }
    }
    string* words = new string[n];
    string word;
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') {
            words[j] = word;
            j++;
            word = "";
            continue;
        }
        word += s[i];
        if (i == s.length() - 1) {
            words[j] = word;
            word = "";
        }
    }
    s = "";
    

    for (int i=1; i<n; i++)
    {
        if (match(words[i - 1], words[i], words[i - 1].length(), words[i].length()) == true)continue;
        else s += words[i-1]+' ';
    }
    cout << s;
}
