#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string, bool> visited;
map<string, set<string, less<string>>> adj_list;

int max_depth = 0;
bool found = false;
vector<string> path;
void dfs()
{
    // cout << path.size() << ": ";
    // for (string i : path)
    // {
    //     cout << i << ", ";
    // }
    // cout << endl;

    if (path.size() == max_depth + 1)
    {
        found = true;
        return;
    }

    string current = path[path.size() - 1];
    for (string next : adj_list.find(current)->second)
    {
        if (visited.find(current + next)->second == false)
        {
            visited.find(current + next)->second = true;
            path.push_back(next);
            dfs();
            if (found)
                return;
            path.pop_back();
            visited.find(current + next)->second = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    max_depth = tickets.size();

    for (int i = 0; i < tickets.size(); i++)
    {
        if (adj_list.find(tickets[i][0]) == adj_list.end())
            adj_list.insert({tickets[i][0], {}});
        adj_list.find(tickets[i][0])->second.insert(tickets[i][1]);
        visited.insert({tickets[i][0] + tickets[i][1], false});
    }
    path = {"ICN"};
    dfs();
    // cout << "hello" << endl;
    return path;
}

int main(int argc, char const *argv[])
{

    // for (string i : solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}))
    for (string i : solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}}))
        cout << i << endl;
    return 0;
}
