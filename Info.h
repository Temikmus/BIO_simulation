#include <vector>
#include <string>
#include <ctime>
#pragma once

class Info{
public:
    std::string get_random_sex()const;
    void set_info();
    //Wolf:
    int max_age_w; // максимальный возраст
    int time_for_reproduction_w; // сколько ходов размножается
    int speed_w; // сколько клеток проходит за один ход
    int speed_old_aged_w; // сколько клеток проходит за один ход, когда старый
    int vision_w; // сколько клеток видит
    int vision_old_aged_w; // сколько клеток видит, когда старый
    int old_aged_w; //во сколько лет становится старым
    std::string sex_w; //пол
    int max_time_without_food_w; //сколько времени может без еды
    int time_full_w; // сколько ходов сытый после еды
    //Rabbit:
    int max_age_r; // максимальный возраст
    int time_for_reproduction_r; // сколько ходов размножается
    int speed_r; // сколько клеток проходит за один ход
    int speed_old_aged_r; // сколько клеток проходит за один ход, когда старый
    int vision_r; // сколько клеток видит
    int vision_old_aged_r; // сколько клеток видит, когда старый
    int old_aged_r; //во сколько лет становится старым
    std::string sex_r; //пол
    int max_time_without_food_r; //сколько времени может без еды
    int time_full_r; // сколько ходов сытый после еды
    // Grass:
    int max_age_g; // максимальный возраст
    int time_for_reproduction_g; // сколько ходов размножается
    //World:
    int start_number_of_wolf; // кол-во волков в начале
    int start_number_of_rabbit; // кол-во кроликов в началe
    int start_number_of_grass; // кол-во травы в начале
    int t_to_year; //сколько в одном году ходов
    int end; //время окончания программы
    int n,m; //размеры поля
};