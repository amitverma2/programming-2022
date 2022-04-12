#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
  int quickest = 101;

  array<int, 101> visited = { 0 };
  deque<pair<int, int>> pipeline;
  pipeline.push_back(make_pair(1, 0)); // start with 1 and with steps 0
  visited[1] = 1;
  while (!pipeline.empty()) {
    auto [pos, step] = pipeline.front();
    // cout << "Debug : " << pos << ", " << step << endl;
    pipeline.pop_front();
    if (pos == 100) {
      return step;
      //if (step < quickest) quickest = step;
    } else {
      // Check if we hit a ladder
      bool ladder = false;
      for (int l = 0; l < ladders.size(); ++l) {
        if (ladders[l][0] == pos) {
          pos = ladders[l][1];
          ladder = true;
          break;
        }
      }
      if (ladder) {
        if (!visited[pos]) {
          visited[pos] = 1;
          pipeline.push_front(make_pair(pos, step));
        }
        continue;
      }
      bool snake = false;
      for (int s = 0; s < snakes.size(); ++s) {
        if (snakes[s][0] == pos) {
          pos = snakes[s][1];
          snake = true;
          break;
        }
      }
      if (snake) {
        if (!visited[pos]) {
          visited[pos] = 1;
          pipeline.push_front(make_pair(pos, step));
        }
        continue;
      }
      // This position is not a snake or ladder position
      // Enumerate the next position and add them for traversal
      for (int i = 1 ; i <= 6 ; ++i) {
        int new_pos = pos + i;
        if (new_pos <= 100 && !visited[new_pos]) {
          visited[new_pos] = 1;
          pipeline.push_back(make_pair(new_pos, step + 1));
        }
      }
    }
  }
  return (quickest == 101)?-1:quickest;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

