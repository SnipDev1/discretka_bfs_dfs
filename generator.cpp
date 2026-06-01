#include <fstream>
#include <random>
#include <set>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void gen_sparse_chain() {
    int n = 1000;
    ofstream out("tests/1_sparse_chain");

    out << n << " " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++) {
        out << i << " " << i + 1 << "\n";
    }
}

void gen_dense_complete() {
    int n = 1000;
    long long m = 1LL * n * (n - 1) / 2;

    ofstream out("tests/2_dense_complete");

    out << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            out << i << " " << j << "\n";
        }
    }
}

void gen_deep_chain() {
    int n = 1000000;

    ofstream out("tests/3_deep_chain");

    out << n << " " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++) {
        out << i << " " << i + 1 << "\n";
    }
}

void gen_random() {
    int n = 10000;
    int m = 50000;

    ofstream out("tests/4_random");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, n - 1);

    set<pair<int,int>> edges;

    while ((int)edges.size() < m) {
        int u = dist(gen);
        int v = dist(gen);
        if (u == v) continue;
        if (u > v) swap(u, v);
        edges.insert({u, v});
    }

    out << n << " " << m << "\n";
    for (auto &e : edges) {
        out << e.first << " " << e.second << "\n";
    }
}

void gen_star() {
    int n = 100000;

    ofstream out("tests/5_star");

    out << n << " " << n - 1 << "\n";
    for (int i = 1; i < n; i++) {
        out << 0 << " " << i << "\n";
    }
}

int main() {
    fs::create_directories("tests");

    gen_sparse_chain();
    gen_dense_complete();
    gen_deep_chain();
    gen_random();
    gen_star();

    return 0;
}