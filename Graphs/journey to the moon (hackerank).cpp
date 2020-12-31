#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int,list<int>>l;
    
public:

    vector<vector<int>> c;
    vector<int>comp;
        
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void dfs_helper(int node, map<int, bool> &visited)
    {
        comp.push_back(node);
        //cout<<node<<" ";
        visited[node]=true;
        for(auto p:l[node])
        {
            if(!visited[p])
            {
                dfs_helper(p, visited);
            }
        }
    }
    
    vector<vector<int>> dfs()
    {
        map<int,bool> visited;
        
        for(auto p:l)
        {
            int node=p.first;
            visited[node]=false;
        }
        
        for(auto p:l)
        {
            int node = p.first;
            if(!visited[node])
            {
                dfs_helper(node, visited);
                c.push_back(comp);
                comp.clear();
                //cout<<endl;
            }
        }
        
        return c;
    }
};

vector<string> split_string(string);

// Complete the journeyToMoon function below.
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    Graph g;
    //int a,b;
    for (int i = 0; i < astronaut.size(); i++)
    {
        g.addEdge(astronaut[i][0],astronaut[i][1]);
    }
    
    vector<vector<int>> k =g.dfs();
    
    long long c=n;
    c*=(n-1);
    c/=2;
    
    for(int i=0;i<k.size();i++)
    {
        int m=k[i].size();
        //for(int j=0;j<m;j++)
        //    cout<<k[i][j]<<" ";
        if(m>1)
        {
            c-=(m*(m-1))/2;
        }
        //cout<<endl;
    }
    
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
