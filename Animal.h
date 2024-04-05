#include <vector>
#include <string>
#include "Info.h"
#include "Field.h"
#pragma once



class Animal
{
public:
    Animal():age(0), stage(0), current_time_reproduction(0) , reproduction_pair(nullptr) {}
    void Set_coordinates(int x, int y);
    int x_coo()const {return x;}
    int y_coo()const {return y;}
    virtual int is_live()const { return 1; }
    virtual void upgrade_info(int current_t, int t_to_year);
    virtual void death() {}
    int get_age()const {return age;}
    int get_stage()const {return stage;}
    void set_stage(int a) {stage=a;}
    virtual ~Animal() = default;
    int get_current_time_reproduction()const {return current_time_reproduction;}
    void upgrade_current_time_reproduction() {current_time_reproduction++;}
    void clear_current_time_reproduction() {current_time_reproduction=0;}
    virtual void move(Field& field, std::vector<Animal*>& objects,std::vector<Animal*>& visit_objects, const Info& info_game) {}
    virtual void clear_statistic();
    static int Get_number_animals() {return number_animals;}
    static int Get_number_died_animals() {return number_died_animals;}
    static int Get_age_oldest_animal() {return age_oldest_animal;}
    static int Get_age_old_animal() {return age_old_animal;}
    static int Get_number_born_animals() {return number_born_animals;}
    int is_not_killed(const Field &field) const;
    Animal* reproduction_pair;
private:
    int age; // текущий возраст
    int x,y; // координаты объекта
protected:
    int stage;
    int max_age;// максимальный возраст
    int current_time_reproduction;
    int time_for_reproduction;//сколько ходов размножается
    static int number_animals;
    static int number_died_animals;
    static int age_oldest_animal;
    static int age_old_animal;
    static int number_born_animals;
};

class Wolf: public Animal
{
public:
    Wolf(const Info& data);
    void move(Field& field, std::vector<Animal*>& objects,std::vector<Animal*>& visit_objects, const Info& info_game);
    std::string get_sex()const {return sex;}
    int get_old_age()const {return old_aged;}
    int is_old_age()const {return is_old_aged;}
    void death();
    void upgrade_info(int current_t, int t_to_year);
    void clear_statistic();
    static int Get_number_wolfs() {return number_wolfs;}
    static int Get_number_died_wolfs() {return number_died_wolfs;}
    static int Get_age_oldest_wolf() {return age_oldest_wolf;}
    static int Get_age_old_wolf() {return age_old_wolf;}
    static int Get_number_born_wolfs() {return number_born_wolfs;}
    int is_live()const;
    ~Wolf() {};
    //Wolf* reproduction_pair;
private:
    int is_old_aged; // старый ли?
    int speed; // сколько клеток проходит за один ход
    int speed_old_aged; // сколько клеток проходит за один ход, когда старый
    int vision; // сколько клеток видит
    int vision_old_aged; // сколько клеток видит, когда старый
    int old_aged; //во сколько лет становится старым
    std::string sex; //пол
    int time_without_food; //сколько в текущий момент времени без еды
    int max_time_without_food; //сколько времени может без еды
    int time_full_food; // сколько ходов сытый после еды
    static int number_wolfs;
    static int number_died_wolfs;
    static int age_oldest_wolf;
    static int age_old_wolf;
    static int number_born_wolfs;
};

class Rabbit: public Animal
{
public:
    Rabbit(const Info& data);
    void move(Field& field, std::vector<Animal*>& objects,std::vector<Animal*>& visit_objects, const Info& info_game);
    std::string get_sex() {return sex;}
    int get_old_age()const {return old_aged;}
    int is_old_age()const {return is_old_aged;}
    void upgrade_info(int current_t, int t_to_year);
    void death();
    int is_live()const;
    void clear_statistic();
    static int Get_number_rabbits() {return number_rabbits;}
    static int Get_number_died_rabbits() {return number_died_rabbits;}
    static int Get_age_oldest_rabbit() {return age_oldest_rabbit;}
    static int Get_age_old_rabbit() {return age_old_rabbit;}
    static int Get_number_born_rabbits() {return number_born_rabbits;}
    ~Rabbit() {};
    //Rabbit* reproduction_pair;
private:
    int speed; // сколько клеток проходит за один ход
    int speed_old_aged; // сколько клеток проходит за один ход, когда старый
    int vision; // сколько клеток видит
    int vision_old_aged; // сколько клеток видит, когда старый
    int is_old_aged; // старый ли?
    int old_aged; //во сколько лет становится старым
    std::string sex; //пол
    int time_without_food; //сколько в текущий момент времени без еды
    int max_time_without_food; //сколько времени может без еды
    int time_full_food; // сколько ходов сытый после еды
    static int number_rabbits;
    static int number_died_rabbits;
    static int age_oldest_rabbit;
    static int age_old_rabbit;
    static int number_born_rabbits;
};

class Grass: public Animal
{
public:
    Grass(const Info& data);
    void move(Field& field, std::vector<Animal*>& objects,std::vector<Animal*>& visit_objects, const Info& info_game);
    void upgrade_info(int current_t, int t_to_year);
    void death();
    void clear_statistic();
    static int Get_number_grass() {return number_grass;}
    static int Get_number_died_grass() {return number_died_grass;}
    static int Get_age_oldest_grass() {return age_oldest_grass;}
    static int Get_age_old_grass() {return age_old_grass;}
    static int Get_number_born_grass() {return number_born_grass;}
    int is_live()const {
        if (this->get_age()<=max_age)
            return 1;
        return 0;
    }
    ~Grass() {};
    //Grass* reproduction_pair;
private:
    static int number_grass;
    static int number_died_grass;
    static int age_oldest_grass;
    static int age_old_grass;
    static int number_born_grass;
};






