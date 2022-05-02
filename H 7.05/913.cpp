#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    unsigned int N;
    float M, tempspeed, speed, time = 0, temptime;
    in >> N >> M;
    speed = M;
    vector <vector<unsigned long int>> vec(N, vector<unsigned long int>(3));

    for (int i = 0; i < N; ++i)
         in >> vec[i][0] >> vec[i][1] >> vec[i][2];

    for (int i = 0; i < N; ++i) {
        time += vec[i][0] / M;
        if (vec[i][1] < M)
            time += vec[i][2];
    }

    for (int i = 0; i < N; ++i) {
        temptime = 0;
        tempspeed = vec[i][1];
        for (int j = 0; j < N; ++j) {
            temptime += vec[j][0] / tempspeed;
            if (vec[j][1] < tempspeed)
                temptime += vec[j][2];
        }
        if (temptime < time) {
            time = temptime;
            speed = tempspeed;
        }

    }
    out << speed;

    return 0;
}