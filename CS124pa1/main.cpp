#include <iostream>
#include <time.h>

using namespace std;

int extractmin(float dist[], int size, bool s[])
{
    int index = -1;
    float mindist = 2;
    for(int i = 0; i < size; i++)
    {
        if(dist[i] < mindist && s[i] == false)
        {
            index = i;
            mindist = dist[i];
        }
    }
    return index;
}

float prim(int n)
{
    float size = 0;
    float dist[n];
    bool s[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = 2;
        s[i] = false;
    }
    dist[0] = 0;
    for(int j = 0; j < n; ++j)
    {
        int v = extractmin(dist, n, s);
        size += dist[v];
        s[v] = true;
        for(int w = 0; w < n; ++w)
        {
            float edgeWeight = (float)rand()/RAND_MAX;
            if((v != w) && (s[w] == false) && (dist[w] > edgeWeight))
            {
                dist[w] = edgeWeight;
            }
        }
    }
    return size;
}

float prim2d(int n)
{
    float graph[n][2];
    for(int k = 0; k < n; ++k)
    {
        graph[k][0] = (float)rand()/RAND_MAX;
        graph[k][1] = (float)rand()/RAND_MAX;
    }
    float size = 0;
    float dist[n];
    bool s[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = 2;
        s[i] = false;
    }
    dist[0] = 0;
    for(int j = 0; j < n; ++j)
    {
        int v = extractmin(dist, n, s);
        size += dist[v];
        s[v] = true;
        for(int w = 0; w < n; ++w)
        {
            float edgeWeight = (float) sqrt((float)pow(graph[w][0] - graph[v][0], 2) + (float)pow(graph[w][1] - graph[v][1], 2));
            if((v != w) && (s[w] == false) && (dist[w] > edgeWeight))
            {
                dist[w] = edgeWeight;
            }
        }
    }
    return size;
}

float prim3d(int n)
{
    float graph[n][3];
    for(int k = 0; k < n; ++k)
    {
        graph[k][0] = (float)rand()/RAND_MAX;
        graph[k][1] = (float)rand()/RAND_MAX;
        graph[k][2] = (float)rand()/RAND_MAX;
    }
    float size = 0;
    float dist[n];
    bool s[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = 2;
        s[i] = false;
    }
    dist[0] = 0;
    for(int j = 0; j < n; ++j)
    {
        int v = extractmin(dist, n, s);
        size += dist[v];
        s[v] = true;
        for(int w = 0; w < n; ++w)
        {
            float edgeWeight = (float) sqrt((float)pow(graph[w][0] - graph[v][0], 2) +
                    (float)pow(graph[w][1] - graph[v][1], 2) + (float)pow(graph[w][2] - graph[v][2], 2));
            if((v != w) && (s[w] == false) && (dist[w] > edgeWeight))
            {
                dist[w] = edgeWeight;
            }
        }
    }
    return size;
}

float prim4d(int n)
{
    float graph[n][4];
    for(int k = 0; k < n; ++k)
    {
        graph[k][0] = (float)rand()/RAND_MAX;
        graph[k][1] = (float)rand()/RAND_MAX;
        graph[k][2] = (float)rand()/RAND_MAX;
        graph[k][3] = (float)rand()/RAND_MAX;
    }
    float size = 0;
    float dist[n];
    bool s[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = 2;
        s[i] = false;
    }
    dist[0] = 0;
    for(int j = 0; j < n; ++j)
    {
        int v = extractmin(dist, n, s);
        size += dist[v];
        s[v] = true;
        for(int w = 0; w < n; ++w)
        {
            float edgeWeight = (float) sqrt((float)pow(graph[w][0] - graph[v][0], 2)
                    + (float)pow(graph[w][1] - graph[v][1], 2) + (float)pow(graph[w][2] - graph[v][2], 2)
                                                                 + (float)pow(graph[w][3] - graph[v][3], 2));
            if((v != w) && (s[w] == false) && (dist[w] > edgeWeight))
            {
                dist[w] = edgeWeight;
            }
        }
    }
    return size;
}


int main(int argc, char *argv[])
{
    int numpoints;
    int numtrials;
    int dimension;
    if(argc == 5)
    {
        numpoints = atoi(argv[2]);
        numtrials = atoi(argv[3]);
        dimension = atoi(argv[4]);
    }
    else
    {
        cout << "Incorrect Number of Command Line Arguments" << endl;
    }
    srand((unsigned)time(NULL));
    for(int i = 0; i < numtrials; ++i)
    {
        if(dimension == 0)
        {
            cout << prim(numpoints) << endl;
        }
        else if(dimension == 2)
        {
            cout << prim2d(numpoints) << endl;
        }
        else if(dimension == 3)
        {
            cout << prim3d(numpoints) << endl;
        }
        else if(dimension == 4)
        {
            cout << prim4d(numpoints) << endl;
        }
        else
        {
            cout << "Dimension must be 0, 2, 3, or 4." << endl;
        }
        
    }
    return 0;
}

//using adjmatrix = vector<vector<float> >; //use this?
//notes from zach: return graph(vector<float>(0, n)) to generate an empty graph

// float** firstGraphGenerator(int n)
// {
//     //generates the first type of graph
//     srand((unsigned)time(NULL));

//     for(int i = 0; i < n; ++i)
//     {
//         for(int j = 0; j < n; ++j)
//         {
//             if(i < j)
//             {
//                 graph[i][j] = (float) rand()/RAND_MAX;
//             }
//             else if (i == j)
//             {
//                 graph[i][j] = 2;
//             }
//             else
//             {
//                 graph[i][j] = graph[j][i];
//             }
//         }
//     }
//     return graph;
// }


// vector<vector<float> > secondGraphGenerator(int n)
// {
//generates the second type of graph
// }


// vector<vector<float> > thirdGraphGenerator(int n)
// {
//generates the third type of graph
// }

// float prim(float **graph, int n)
// {
//     float dist[n];
//     bool s[n];
//     for(int i = 0; i < n; ++i)
//     {
//         dist[i] = 2;
//         s[i] = false;
//     }
//     dist[0] = 0;
//     for(int j = 0; j < n; ++j)
//     {
//         int v = extractmin(dist, n);
//         s[v] = true;
//         for(int w = 0; w < n; ++w)
//         {
//             if(s[w] == false && dist[w] > graph[v][w])
//             {
//                 dist[w] = graph[v][w];
//                 s[w] = true;
//             }
//         }
//     }
//     float size = 0;
//     for(int k = 0; k < n; ++k)
//     {
//         size += dist[k];
//     }
//     return size;
// }