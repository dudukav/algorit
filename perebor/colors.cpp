#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_valid(const vector<char>& colors, const unordered_map<int, vector<int>>& connections, char color, int curr) {
    for (int next : connections.at(curr)) {
        if (colors[next] == color) {
            return false;
        }
    }
    return true;
}

void recolor_circles(vector<char>& colors, const unordered_map<int, vector<int>>& connections) {
    char new_color;
    for (char curr_color : {'R', 'G', 'B'}) {
        if (is_valid(colors, connections, curr_color, 0)) {
            new_color = curr_color;
            break;
        }
    }

    for (char& curr_color : colors) {
        if (curr_color == new_color) {
            for (char next_color : {'R', 'G', 'B'}) {
                if (is_valid(colors, connections, next_color, &curr_color - &colors[0])) {
                    curr_color = next_color;
                    break;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<char> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    unordered_map<int, vector<int>> connections;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    recolor_circles(colors, connections);

    for (char color : colors) {
        cout << color;
    }
    cout << endl;

    return 0;
}

