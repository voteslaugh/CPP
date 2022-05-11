#include <fstream>
#include <string>
#include <list>

using namespace std;

void delSymb(list<size_t>& str, list<size_t>::iterator& curLine) {
    if (*curLine > 0) {
        (*curLine)--;
        return;
    }
    if (str.begin() == curLine)
        return;
    curLine = prev(str.erase(curLine));
}

void toPrevLine(list<size_t>& str, list<size_t>::iterator& curLine) {
    if (str.begin() == curLine)
        return;
    --curLine;
}

void toNextLine(list<size_t>& str, list<size_t>::iterator& curLine) {
    list<size_t>::iterator nextLine = next(curLine);
    if (str.end() == nextLine)
        return;
    curLine = nextLine;
}

void addLine(list<size_t>& str, list<size_t>::iterator& curLine) {
    curLine = str.insert(next(curLine), 0);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    list<size_t> str(1);
    list<size_t>::iterator curLine = str.begin();
    size_t max = 0;

    while (in) {
        char c;
        in.get(c);
        if (c < 32)
            break;
        switch (c) {
        case '<':
            delSymb(str, curLine);
            break;
        case '^':
            toPrevLine(str, curLine);
            break;
        case '|':
            toNextLine(str, curLine);
            break;
        case '\\':
            addLine(str, curLine);
            break;
        default:
            ++(*curLine);
            if (*curLine > max) {
                max = *curLine;
            }
            break;
        }
    }

    out << max;
}