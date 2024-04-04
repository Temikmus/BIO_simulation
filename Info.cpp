#include "Info.h"
#include <iostream>

std::string Info::get_random_sex()const{
    if (rand()%2==0)
        return "F";
    return "M";
}

void Info::set_info() {
    std::cout<<"Wolf:";
    //Wolf:
    int p;
    std::cout<<"\nEnter max_age_w:";
    std::cin>>p;
    max_age_w=p; // максимальный возраст
    std::cout<<"\nEnter time_for_reproduction_w:";
    std::cin>>p;
    time_for_reproduction_w=p; // сколько ходов размножается
    std::cout<<"\nEnter speed_w:";
    std::cin>>p;
    speed_w=p; // сколько клеток проходит за один ход
    std::cout<<"\nEnter speed_old_aged_w:";
    std::cin>>p;
    speed_old_aged_w=p; // сколько клеток проходит за один ход, когда старый
    std::cout<<"\nEnter vision_w:";
    std::cin>>p;
    vision_w=p; // сколько клеток видит
    std::cout<<"\nEnter vision_old_aged_w:";
    std::cin>>p;
    vision_old_aged_w=p; // сколько клеток видит, когда старый
    std::cout<<"\nEnter old_aged_w:";
    std::cin>>p;
    old_aged_w=p; //во сколько лет становится старым
    std::cout<<"\nEnter max_time_without_food_w:";
    std::cin>>p;
    max_time_without_food_w=p; //сколько времени может без еды
    std::cout<<"\nEnter time_full_food_w:";
    std::cin>>p;
    time_full_w=p; // сколько ходов сытый после еды
    //Rabbit:
    std::cout<<"Rabbit:";
    std::cout<<"\nEnter max_age_r:";
    std::cin>>p;
    max_age_r=p; // максимальный возраст
    std::cout<<"\nEnter time_for_reproduction_r:";
    std::cin>>p;
    time_for_reproduction_r=p; // сколько ходов размножается
    std::cout<<"\nEnter speed_r:";
    std::cin>>p;
    speed_r=p; // сколько клеток проходит за один ход
    std::cout<<"\nEnter speed_old_aged_r:";
    std::cin>>p;
    speed_old_aged_r=p; // сколько клеток проходит за один ход, когда старый
    std::cout<<"\nEnter vision_r:";
    std::cin>>p;
    vision_r=p; // сколько клеток видит
    std::cout<<"\nEnter vision_old_aged_r:";
    std::cin>>p;
    vision_old_aged_r=p; // сколько клеток видит, когда старый
    std::cout<<"\nEnter old_aged_r:";
    std::cin>>p;
    old_aged_r=p; //во сколько лет становится старым
    std::cout<<"\nEnter max_time_without_food_r:";
    std::cin>>p;
    max_time_without_food_r=p; //сколько времени может без еды
    std::cout<<"\nEnter time_full_food_r:";
    std::cin>>p;
    time_full_r=p; // сколько ходов сытый после еды
    // Grass:
    std::cout<<"Grass:";
    std::cout<<"\nEnter max_age_g:";
    std::cin>>p;
    max_age_g=p; // максимальный возраст
    std::cout<<"\nEnter time_for_reproduction_g:";
    std::cin>>p;
    time_for_reproduction_g=p; // сколько ходов размножается
    //World:
    std::cout<<"World:";
    std::cout<<"\nEnter end:";
    std::cin>>p;
    end=p; //время окончания программы
    std::cout<<"\nEnter n:";
    std::cin>>p;
    n=p; //размеры поля (высота)
    std::cout<<"\nEnter m:";
    std::cin>>p;
    m=p; //размеры поля (ширина)
    std::cout<<"\nEnter start_number_of_wolf:";
    std::cin>>p;
    start_number_of_wolf=p; // кол-во волков в начале
    std::cout<<"\nEnter start_number_of_rabbit:";
    std::cin>>p;
    start_number_of_rabbit=p; // кол-во кроликов в началe
    std::cout<<"\nEnter start_number_of_grass:";
    std::cin>>p;
    start_number_of_grass=p; // кол-во травы в начале
    std::cout<<"\nEnter t_to_year:";
    std::cin>>p;
    t_to_year=p; // кол-во ходов в году
}
