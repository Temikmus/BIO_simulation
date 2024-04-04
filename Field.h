#include <vector>
#pragma once

class Field{
public:
    Field(int n,int m);
    void upgrade_field(int object, int x, int y);
    void upgrade_infected(int vision_r, int x, int y);
    std::vector<int> give_free_coordinates();
    void print()const;
    void pop(int x, int y) {matrix_field[x][y]=0;}
    int get_n()const {return n;}
    int get_m()const {return m;}
    std::vector <std::vector <int> > matrix_field;
    std::vector <std::vector <int> > infected_matrix;
private:
    int n,m; //размерность поля
};