#include <vector>
#pragma once

class Vertex{
public:
    int x,y; // координаты
    int color;
    std::vector<std::vector<int>> neighbours;
    int d;
    int x_p, y_p;
    int name;
};

class Graph{
public:
    int find_vertex(int x1, int y1);
    void BFS(int x, int y, int goal1, int goal2,int goal3, int vision);
    std::vector<Vertex> graph;
    std::vector<std::vector<int>> path1;
    std::vector<std::vector<int>> path2;
    std::vector<std::vector<int>> path3;
};
