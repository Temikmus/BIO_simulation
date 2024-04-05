#include "Animal.h"

#pragma once

class World
{
public:
    World(const Info& data): end(data.end), n(data.n), m(data.m), current_t(0), t_to_year(data.t_to_year){}
    int is_end() const;
    int get_current_t()const {return current_t;}
    void upgrade_current_t() {current_t++;}
    int get_end()const {return end;}
    int get_t_to_year()const {return t_to_year;}
    void clear_statistic_animals();
    void print_statistic();
    void add_object(Animal* p);
    void pop();
    void set_wolf(Wolf* p) {wolf = p;}
    void set_grass(Grass* p) {grass = p;}
    void set_rabbit(Rabbit* p) {rabbit = p;}
    std::vector<Animal*> objects;
    std::vector<Animal*> visited_objects;
private:
    Wolf* wolf;
    Rabbit* rabbit;
    Grass* grass;
    int end; // после какого хода программа заканчивается
    int current_t; // текущий ход
    int n,m; //размеры поля
    int t_to_year; //сколько в одном году ходов
};