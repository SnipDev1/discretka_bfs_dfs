#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;


void run_dfs(const string& input_file);
void run_bfs(const string& input_file);
int main() {
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    vector<string> filenames;
    string str;

    printf_s("Имя файлов с графами: ");
    while (getline(cin, str) && !str.empty())
    {
        filenames.push_back(str);
    }


    for (vector<string>::iterator name = filenames.begin(); name != filenames.end(); ++name) {
        printf_s("Запуск Поиска в Ширину (BFS) <%s>...\n", name->c_str());
        run_bfs(*name);
        printf_s("Запуск Поиска в Глубину (DFS) <%s>...\n", name->c_str());
        run_dfs(*name);
    }

}