#include <fstream>
#include <map>

using namespace std;

bool isSpace(char c) {
    const string spaces(".,:;-'\"!?\n \t");
    return spaces.find(c) != std::string::npos;
}
void checkSpace(istream& ist) {
    while (true) {
        if (ist.eof() || ist.bad())
            break;
        auto symbol = ist.peek();
        if (false == isSpace(symbol))
            break;
        ist.get();
    }
}
string inputString(istream& ist) {
    string word;
    checkSpace(ist);
    while (true) {
        if (ist.eof() || ist.bad())
            break;
        auto symbol = ist.peek();
        if (isSpace(symbol))
            break;
        word.push_back(toupper(ist.get()));
    }
    return word;
}
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m;
    in >> n >> m;
    map<string, int> dict;
    for (int i = 0; i < n; ++i) {
        dict.insert(make_pair(inputString(in), 0));
    }
    while (true) {
        string word = inputString(in);
        if (word.empty())
            break;
        auto it = dict.find(word);
        if (it == dict.end()) {
            out << "Some words from the text are unknown.";
            return 0;
        }
        dict[word]++;
    }
    for (auto pair : dict) {
        if (pair.second == 0) {
            out << "The usage of the vocabulary is not perfect.";
            return 0;
        }
    }
    out << "Everything is going to be OK.";
}