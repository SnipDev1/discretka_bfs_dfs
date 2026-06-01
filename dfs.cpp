#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

static vector<vector<unsigned int>> graph;
static vector<bool> visited;

void dfs(unsigned int v) {
    visited[v] = true;
    for (unsigned int to : graph[v]) {
        if (!visited[to]) {
            dfs(to);
        }
    }
}

void run_dfs(const string& in_filename) {
    ifstream infile(in_filename);

    // Умный поиск файла
    if (!infile.is_open()) {
        infile.open("../" + in_filename);
    }
    if (!infile.is_open()) {
        printf_s("Ошибка: Не удалось открыть файл %s\n\n", in_filename.c_str());
        return;
    }

    unsigned int n = 0, m = 0, u = 0, v = 0;
    if (!(infile >> n >> m)) return;

    graph.clear();
    graph.resize(n);

    for (unsigned int i = 0; i < m; i++) {
        infile >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    infile.close();

    unsigned int components = 0;
    const int RUNS = 1000;
    auto start_time = chrono::high_resolution_clock::now();

    for (int r = 0; r < RUNS; r++) {
        visited.assign(n, false);
        components = 0;

        for (unsigned int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
                components++;
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();


    chrono::duration<double, milli> elapsed = end_time - start_time;
    double avg_time = elapsed.count() / RUNS;

    printf_s("(dfs.cpp)\n");
    printf_s("Количество компонент связности: %u\n", components);
    printf_s("Среднее время выполнения (%d запусков): %.6f мс\n\n", RUNS, avg_time);
}