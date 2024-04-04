#include "Graph.h"

int Graph::find_vertex(int x1, int y1) {
    int ind=-1;
    for (int i=0; i<graph.size(); i++)
    {
        if (graph[i].x==x1 && graph[i].y==y1)
        {
            ind=i;
            break;
        }
    }
    return ind;
}

void Graph::BFS(int x, int y, int goal1, int goal2, int goal3, int vision) {
    for (int i=0; i<graph.size(); i++)
    {
        graph[i].color=0;
        graph[i].d=10000;
        graph[i].x_p=-1;
        graph[i].y_p=-1;
    }
    int ind1=this->find_vertex(x,y);
    if (ind1==-1)
        return;
    graph[ind1].color=1;
    graph[ind1].d=0;
    std::vector<std::vector<int>> Q;
    std::vector<int> u;
    u.push_back(x);
    u.push_back(y);
    Q.push_back(u);
    int find=0;
    while(!Q.empty() && find==0)
    {
        int x1=Q[0][0];
        int y1=Q[0][1];
        Q.erase(Q.begin());
        ind1=this->find_vertex(x1,y1);
        if (ind1==-1)
            return;
        for (int i=0; i<graph[ind1].neighbours.size(); i++)
        {
            int ind2=this->find_vertex(graph[ind1].neighbours[i][0], graph[ind1].neighbours[i][1]);
            if (ind2==-1)
                return;
            if (graph[ind2].color==0)
            {
                if (graph[ind2].name==goal1 || graph[ind2].name==goal2 || graph[ind2].name==goal3)
                {
                    graph[ind2].color=1;
                    graph[ind2].d=graph[ind1].d+1;
                    graph[ind2].x_p=graph[ind1].x;
                    graph[ind2].y_p=graph[ind1].y;
                    if (graph[ind2].d>vision)
                    {
                        find=1;
                        break;
                    }
                    if (graph[ind2].name==goal1)
                    {
                        std::vector<int> o;
                        o.push_back(graph[ind2].x);
                        o.push_back(graph[ind2].y);
                        if (!path1.empty()) {
                            path1.insert(path1.begin(), o);
                        } else {
                            path1.push_back(o); // Добавляем элемент в конец вектора
                        }
                        while(graph[ind2].x_p!=-1)
                        {
                            ind2=this->find_vertex(path1[0][0], path1[0][1]);
                            if (graph[ind2].x_p==-1)
                                break;
                            std::vector<int> o1;
                            o1.push_back(graph[ind2].x_p);
                            o1.push_back(graph[ind2].y_p);
                            if (!path1.empty()) {
                                path1.insert(path1.begin(), o1);
                            } else {
                                path1.push_back(o1); // Добавляем элемент в конец вектора
                            }
                        }
                        find=1;
                        break;
                    }
                    if (graph[ind2].name==goal2)
                    {
                        std::vector<int> o;
                        o.push_back(graph[ind2].x);
                        o.push_back(graph[ind2].y);
                        if (!path2.empty()) {
                            path2.insert(path2.begin(), o);
                        } else {
                            path2.push_back(o); // Добавляем элемент в конец вектора
                        }
                        while(graph[ind2].x_p!=-1)
                        {
                            ind2=this->find_vertex(path2[0][0], path2[0][1]);
                            if (graph[ind2].x_p==-1)
                                break;
                            std::vector<int> o1;
                            o1.push_back(graph[ind2].x_p);
                            o1.push_back(graph[ind2].y_p);
                            if (!path2.empty()) {
                                path2.insert(path2.begin(), o1);
                            } else {
                                path2.push_back(o1); // Добавляем элемент в конец вектора
                            }
                        }
                        find=1;
                        break;
                    }
                    if (graph[ind2].name==goal3)
                    {
                        std::vector<int> o;
                        o.push_back(graph[ind2].x);
                        o.push_back(graph[ind2].y);
                        if (!path3.empty()) {
                            path3.insert(path3.begin(), o);
                        } else {
                            path3.push_back(o); // Добавляем элемент в конец вектора
                        }
                        while(graph[ind2].x_p!=-1)
                        {
                            ind2=this->find_vertex(path3[0][0], path3[0][1]);
                            if (graph[ind2].x_p==-1)
                                break;
                            std::vector<int> o1;
                            o1.push_back(graph[ind2].x_p);
                            o1.push_back(graph[ind2].y_p);
                            if (!path3.empty()) {
                                path3.insert(path3.begin(), o1);
                            } else {
                                path3.push_back(o1); // Добавляем элемент в конец вектора
                            }
                        }
                        find=1;
                        break;
                    }
                }
                else
                {
                    if (graph[ind2].name==0)
                    {
                        graph[ind2].color=1;
                        graph[ind2].d=graph[ind1].d+1;
                        graph[ind2].x_p=graph[ind1].x;
                        graph[ind2].y_p=graph[ind1].y;
                        if (graph[ind2].d>vision)
                        {
                            find=1;
                            break;
                        }
                        std::vector<int> v;
                        v.push_back(graph[ind2].x);
                        v.push_back(graph[ind2].y);
                        Q.push_back(v);
                    }
                }
            }
        }
    }
}


