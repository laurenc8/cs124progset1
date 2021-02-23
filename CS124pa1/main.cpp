#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;
//using adjmatrix = vector<vector<float> >; //use this?
//notes from zach: return graph(vector<float>(0, n)) to generate an empty graph

vector<vector<float> > firstGraphGenerator(int n)
{
    //generates the first type of graph
    srand((unsigned)time(NULL));
    vector<vector<float> > graph = vector<vector<float> >(n, vector<float>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i < j)
            {
                graph[i][j] = (double) rand()/RAND_MAX;
            }
            else if (i == j)
            {
                graph[i][j] = 2;
            }
            else
            {
                graph[i][j] = graph[j][i];
            }
        }
    }
    return graph;
}


vector<vector<float> > secondGraphGenerator(int n)
{
    //generates the second type of graph
}


vector<vector<float> > thirdGraphGenerator(int n)
{
    //generates the third type of graph
}


void prim(const vector<vector<float> >& graph, int n)
{
    vector<float> dist = vector<float> (n, (float)n*(n-1)/2);
    vector<float> prev = vector<float> (n, (float)n+1);
    vector<float> s = vector<float> (n, (float)0);
    vector<float> h = vector<float> (n, (float)-1);
    h[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        dist[i] = (2);
    }
    dist[0] = 0;
    bool empty = false;
    while(!empty)
    {
        cout << "hi" << endl;
        int min = 2;
        int v = 0;
        for(int i = 0; i < n; ++i)
        {
            if(h[i] < min)
            {
                min = h[i];
                v = i;
            }
        }
        h[v] = (float)-1;
        for(int j = 0; j < n; ++j)
        {
            if(s[j] != 0)
            {
                s[j] = (float)v;
            }
        }
        for(int w = 0; w < n; ++w)
        {
            if(count(s.begin(), s.end(), (float)w) == 0)
            {
                if(dist[w] > graph[v][w])
                {
                    dist[w] = graph[v][w];
                    prev[w] = v;
                    h[w] = dist[w];
                }
            }
        }
        empty = true;
        for(int k = 0; k < n; ++k)
        {
            if (h[k] != -1)
            {
                empty = false;
            }
        }
    }
}


int main()
{
    //generate graph
    int n;
    cout << "Give a value of n: " << endl;
    cin >> n;

    auto graph = firstGraphGenerator(n);
    //graph = secondGraphGenerator();
    //graph = thirdGraphGenerator();

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << graph[i][j] << " ";
        }
    }

    //perform mst algorithm
    prim(graph, n);
    return 0;
}