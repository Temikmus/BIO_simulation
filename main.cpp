#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window/Mouse.hpp>
//#include <SFML/Window/Keyboard.hpp>
#include "World.h"
#include <vector>

void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape-последовательность для очистки консоли
    //system("cls");
}

void Game(World& world, Field& field,const Info& info_game)
{
    while (!world.is_end())
    {
        if (!world.objects.empty())
        {
            world.clear_statistic_animals();
        }
        while(!world.objects.empty())
        {
            if (world.objects[0]->is_live())
            {
                world.objects[0]->move(field, world.objects, info_game);
                world.objects[0]->upgrade_info(world.get_current_t(), world.get_t_to_year());
                world.visited_objects.push_back(world.objects[0]);
                world.objects.erase(world.objects.begin());
            }
            else
            {
                field.pop(world.objects[0]->x_coo(), world.objects[0]->y_coo());
                world.objects[0]->death();
                if (world.objects[0]->reproduction_pair != nullptr)
                {
                    world.objects[0]->reproduction_pair->reproduction_pair = nullptr;
                    world.objects[0]->reproduction_pair->set_stage(0);
                }

                delete world.objects[0];
                world.objects.erase(world.objects.begin());
            }
        }
        world.objects=world.visited_objects;
        world.visited_objects.clear();
        world.upgrade_current_t();
        //clearConsole();
        std::cout<<world.get_current_t()<<"\n";
        world.print_statistic();
        field.print();
    }
    //current_t==end || Animal::Get_number_animals()>n*m || Wolf::Get_number_wolfs()==0 || Rabbit::Get_number_rabbits()==0 || Grass::Get_number_grass()==0
    if (world.get_current_t()==world.get_end())
    {
        std::cout<<"Game passed!!!";
    }
    else if (Animal::Get_number_animals()>field.get_n()*field.get_m())
    {
        std::cout<<"Game over! Overpopulation";
    }
    else if (Wolf::Get_number_wolfs()==0)
    {
        std::cout<<"Game over! The wolves died";
    }
    else if (Rabbit::Get_number_rabbits()==0)
    {
        std::cout<<"Game over! The rabbits died";
    }
    else if (Grass::Get_number_grass()==0)
    {
        std::cout<<"Game over! The grass died";
    }
    else
    {
        std::cout<<"Smth went wrong...";
    }
}

int main()
{
    srand(time(0));
    Info info_game;
    info_game.set_info();
    Field field(info_game.n, info_game.m);
    World world(info_game);
    for(int i=0; i<info_game.start_number_of_wolf; i++)
    {
        auto* wolf = new Wolf(info_game);
        std::vector<int> coo;
        coo=field.give_free_coordinates();
        if (coo.empty() || coo.size() < 2)
        {
            std::cout<<"Game over";
            return 0;
        }
        wolf->Set_coordinates(coo[0], coo[1]);
        if (wolf->get_sex()=="F")
            field.upgrade_field(31, wolf->x_coo(), wolf->y_coo());
        else
            field.upgrade_field(30, wolf->x_coo(), wolf->y_coo());
        world.add_object(wolf);
    }
    for(int i=0; i<info_game.start_number_of_rabbit; i++)
    {
        auto* rabbit = new Rabbit(info_game);
        std::vector<int> coo;
        coo=field.give_free_coordinates();
        if (coo.empty() || coo.size() < 2)
        {
            std::cout<<"Game over";
            return 0;
        }
        rabbit->Set_coordinates(coo[0], coo[1]);
        if (rabbit->get_sex()=="F")
            field.upgrade_field(21, rabbit->x_coo(), rabbit->y_coo());
        else
            field.upgrade_field(20, rabbit->x_coo(), rabbit->y_coo());
        world.add_object(rabbit);
    }
    for(int i=0; i<info_game.start_number_of_grass; i++)
    {
        auto* grass = new Grass(info_game);
        std::vector<int> coo;
        coo=field.give_free_coordinates();
        if (coo.empty() || coo.size() < 2)
        {
            std::cout<<"Game over";
            return 0;
        }
        grass->Set_coordinates(coo[0], coo[1]);
        field.upgrade_field(1, grass->x_coo(), grass->y_coo());
        world.add_object(grass);
    }
    auto* wolf = new Wolf(info_game);
    auto* rabbit = new Rabbit(info_game);
    auto* grass = new Grass(info_game);
    world.set_rabbit(rabbit);
    world.set_grass(grass);
    world.set_wolf(wolf);
    Game(world, field, info_game);
    world.pop();
    return 0;
}
//R"(C:\Users\artem\Downloads\Merriweather\Merriweather-BoldItalic.ttf)"

