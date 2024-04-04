#include "World.h"
#include <iostream>

int World::is_end() const {
    if (current_t==end || Animal::Get_number_animals()>=n*m || Wolf::Get_number_wolfs()==0 || Rabbit::Get_number_rabbits()==0 || Grass::Get_number_grass()==0) return 1;
    return 0;
}

void World::add_object(Animal* p) {
    objects.push_back(p);
}

void World::clear_statistic_animals() {
    wolf->clear_statistic();
    rabbit->clear_statistic();
    grass->clear_statistic();
}

void World::pop(){
    delete wolf;
    delete grass;
    delete rabbit;
}

void World::print_statistic() {
    std::cout<<"Animal:\n";
    std::cout<<"number_animals: "<<wolf->Get_number_animals()<<"   "<<"age_old_animal: "<<wolf->Get_age_old_animal()<<"   "<<"age_oldest_animal: "<<wolf->Get_age_oldest_animal()<<"   "<<"born_animals: "<<wolf->Get_number_born_animals()<<"   "<<"died_animals: "<<wolf->Get_number_died_animals()<<"\n";
    std::cout<<"number_wolfs: "<<wolf->Get_number_wolfs()<<"   "<<"age_old_wolf: "<<wolf->Get_age_old_wolf()<<"   "<<"age_oldest_wolf: "<<wolf->Get_age_oldest_wolf()<<"   "<<"born_wolfs: "<<wolf->Get_number_born_wolfs()<<"   "<<"died_wolfs: "<<wolf->Get_number_died_wolfs()<<"\n";
    std::cout<<"number_rabbits: "<<rabbit->Get_number_rabbits()<<"   "<<"age_old_rabbit: "<<rabbit->Get_age_old_rabbit()<<"   "<<"age_oldest_rabbit: "<<rabbit->Get_age_oldest_rabbit()<<"   "<<"born_rabbits: "<<rabbit->Get_number_born_rabbits()<<"   "<<"died_rabbits: "<<rabbit->Get_number_died_rabbits()<<"\n";
    std::cout<<"number_grass: "<<grass->Get_number_grass()<<"   "<<"age_old_grass: "<<grass->Get_age_old_grass()<<"   "<<"age_oldest_grass: "<<grass->Get_age_oldest_grass()<<"   "<<"born_grass: "<<grass->Get_number_born_grass()<<"   "<<"died_grass: "<<grass->Get_number_died_grass()<<"\n";
}
