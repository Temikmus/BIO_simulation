#include "Animal.h"
#include "Info.h"
#include "Graph.h"

            int Animal::number_animals=-3;
            int Animal::age_oldest_animal=0;
            int Animal::number_born_animals=-3;
            int Animal::number_died_animals=0;
            int Animal::age_old_animal=0;
            int Wolf::number_wolfs=-1;
            int Wolf::age_old_wolf=0;
            int Wolf::age_oldest_wolf=0;
            int Wolf::number_born_wolfs=-1;
            int Wolf::number_died_wolfs=0;
            int Rabbit::number_rabbits=-1;
            int Rabbit::age_oldest_rabbit=0;
            int Rabbit::number_born_rabbits=-1;
            int Rabbit::number_died_rabbits=0;
            int Rabbit::age_old_rabbit=0;
            int Grass::number_grass=-1;
            int Grass::age_oldest_grass=0;
            int Grass::number_born_grass=-1;
            int Grass::number_died_grass=0;
            int Grass::age_old_grass=0;


            Wolf::Wolf(const Info& data) :Animal() {
                max_age = data.max_age_w; // максимальный возраст
                time_for_reproduction= data.time_for_reproduction_w; // сколько ходов размножается
                speed=data.speed_w; // сколько клеток проходит за один ход
                speed_old_aged=data.speed_old_aged_w; // сколько клеток проходит за один ход, когда старый
                vision= data.vision_w; // сколько клеток видит
                vision_old_aged= data.vision_old_aged_w; // сколько клеток видит, когда старый
                old_aged=data.old_aged_w; //во сколько лет становится старым
                sex=data.get_random_sex();
                time_without_food=0; //сколько в текущий момент времени без еды
                max_time_without_food=data.max_time_without_food_w; //сколько времени может без еды
                time_full_food=data.time_full_w; // сколько ходов сытый после еды
                number_wolfs++;
                number_animals++;
                is_old_aged=0;
                reproduction_pair= nullptr;
                number_born_animals++;
                number_born_wolfs++;
            }

            Rabbit::Rabbit(const Info& data) :Animal() {
                max_age = data.max_age_r; // максимальный возраст
                time_for_reproduction= data.time_for_reproduction_r; // сколько ходов размножается
                speed=data.speed_r; // сколько клеток проходит за один ход
                speed_old_aged=data.speed_old_aged_r; // сколько клеток проходит за один ход, когда старый
                vision= data.vision_r; // сколько клеток видит
                vision_old_aged= data.vision_old_aged_r; // сколько клеток видит, когда старый
                old_aged=data.old_aged_r; //во сколько лет становится старым
                sex=data.get_random_sex();
                time_without_food=0; //сколько в текущий момент времени без еды
                max_time_without_food=data.max_time_without_food_r; //сколько времени может без еды
                time_full_food=data.time_full_r; // сколько ходов сытый после еды
                number_rabbits++;
                number_animals++;
                is_old_aged=0;
                reproduction_pair= nullptr;
                number_born_rabbits++;
                number_born_animals++;
            }

            Grass::Grass(const Info& data):Animal(){
                max_age=data.max_age_g; // максимальный возраст
                time_for_reproduction=data.time_for_reproduction_g; // сколько ходов размножается
                number_grass++;
                reproduction_pair= nullptr;
                number_animals++;
                number_born_grass++;
                number_born_animals++;
            }

            void Animal::Set_coordinates(int x1, int y1)
            {
                x=x1;
                y=y1;
            }

            void Animal::upgrade_info(int current_t, int t_to_year) {
                if (current_t%t_to_year==0 && current_t!=0)
                {
                    age++;
                }
            }

            void Wolf::upgrade_info(int current_t, int t_to_year) {
                Animal::upgrade_info(current_t, t_to_year);
                if (age_old_wolf<get_age())
                {
                    age_old_wolf=get_age();
                    if (age_old_animal<age_old_wolf)
                        age_old_animal=age_old_wolf;
                    if (age_oldest_wolf<age_old_wolf)
                    {
                        age_oldest_wolf=age_old_wolf;
                        if (age_oldest_animal<age_oldest_wolf)
                        {
                            age_oldest_animal=age_oldest_wolf;
                        }
                    }
                }
                time_without_food++;
                if (is_old_aged==0)
                {
                    if (old_aged<=get_age())
                    {
                        is_old_aged=1;
                        vision=vision_old_aged;
                        speed=speed_old_aged;
                    }
                }
            }


            void Rabbit::upgrade_info(int current_t, int t_to_year) {
                Animal::upgrade_info(current_t, t_to_year);
                if (age_old_rabbit<get_age())
                {
                    age_old_rabbit=get_age();
                    if (age_old_animal<age_old_rabbit)
                        age_old_animal=age_old_rabbit;
                    if (age_oldest_rabbit<age_old_rabbit)
                    {
                        age_oldest_rabbit=age_old_rabbit;
                        if (age_oldest_animal<age_oldest_rabbit)
                        {
                            age_oldest_animal=age_oldest_rabbit;
                        }
                    }
                }
                time_without_food++;
                if (is_old_aged==0)
                {
                    if (old_aged<=get_age())
                    {
                        is_old_aged=1;
                        vision=vision_old_aged;
                        speed=speed_old_aged;
                    }
                }
            }

            void Grass::upgrade_info(int current_t, int t_to_year) {
                Animal::upgrade_info(current_t, t_to_year);
                if (age_old_grass<get_age())
                {
                    age_old_grass=get_age();
                    if (age_old_animal<age_old_grass)
                        age_old_animal=age_old_grass;
                    if (age_oldest_grass<age_old_grass)
                    {
                        age_oldest_grass=age_old_grass;
                        if (age_oldest_animal<age_oldest_grass)
                        {
                            age_oldest_animal=age_oldest_grass;
                        }
                    }
                }
            }


            int Wolf::is_live() const {
                if (this->get_age()<=max_age && time_without_food<max_time_without_food)
                    return 1;
                return 0;
            }

            int Rabbit::is_live() const {
                if (this->get_age()<=max_age && time_without_food<max_time_without_food)
                    return 1;
                return 0;
            }

            int Animal::is_not_killed(const Field& field)const
            {
                if(is_live())
                {
                    if (field.matrix_field[x_coo()][y_coo()]!=0)
                        return 1;
                    return 0;
                }
                return 0;
            }

            void Wolf::death(){
                this->number_wolfs--;
                this->number_animals--;
                number_died_wolfs++;
                number_died_animals++;
            }

            void Grass::death() {
                this->number_grass--;
                this->number_animals--;
                number_died_grass++;
                number_died_animals++;
            }

            void Rabbit::death() {
                this->number_rabbits--;
                this->number_animals--;
                number_died_rabbits++;
                number_died_animals++;
            }

            std::vector<std::vector<int>> neighbours_grass(const Field& field,int n, int m, int x, int y)
            {
                std::vector<std::vector<int>> neigh;
                if (x-1>=0 && y-1>=0)
                {
                    if (field.matrix_field[x-1][y-1]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x-1);
                        coo.push_back(y-1);
                        neigh.push_back(coo);
                    }
                }
                if (x-1>=0)
                {
                    if (field.matrix_field[x-1][y]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x-1);
                        coo.push_back(y);
                        neigh.push_back(coo);
                    }
                }
                if (x-1>=0 && y+1<m)
                {
                    if (field.matrix_field[x-1][y+1]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x-1);
                        coo.push_back(y+1);
                        neigh.push_back(coo);
                    }
                }
                if (y-1>=0)
                {
                    if (field.matrix_field[x][y-1]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x);
                        coo.push_back(y-1);
                        neigh.push_back(coo);
                    }
                }
                if (y+1<m)
                {
                    if (field.matrix_field[x][y+1]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x);
                        coo.push_back(y+1);
                        neigh.push_back(coo);
                    }
                }
                if (x+1<n && y-1>=0)
                {
                    if (field.matrix_field[x+1][y-1]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x+1);
                        coo.push_back(y-1);
                        neigh.push_back(coo);
                    }
                }
                if (x+1<n)
                {
                    if (field.matrix_field[x+1][y]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x+1);
                        coo.push_back(y);
                        neigh.push_back(coo);
                    }
                }
                if (x+1<n && y+1<m)
                {
                    if (field.matrix_field[x+1][y+1]==1)
                    {
                        std::vector<int> coo;
                        coo.push_back(x+1);
                        coo.push_back(y+1);
                        neigh.push_back(coo);
                    }
                }
                return neigh;
            }

            std::vector<std::vector<int>> neighbours(const Field& field,int n, int m, int x, int y, int object)
            {
                std::vector<std::vector<int>> neigh;
                if (x-1>=0 && y-1>=0)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x-1][y-1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x-1);
                            coo.push_back(y-1);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x-1][y-1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x-1);
                            coo.push_back(y-1);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x-1);
                        coo.push_back(y-1);
                        neigh.push_back(coo);
                    }
                }
                if (x-1>=0)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x-1][y]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x-1);
                            coo.push_back(y);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x-1][y]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x-1);
                            coo.push_back(y);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x-1);
                        coo.push_back(y);
                        neigh.push_back(coo);
                    }
                }
                if (x-1>=0 && y+1<m)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x-1][y+1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x-1);
                            coo.push_back(y+1);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x-1][y+1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x-1);
                            coo.push_back(y+1);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x-1);
                        coo.push_back(y+1);
                        neigh.push_back(coo);
                    }
                }
                if (y-1>=0)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x][y-1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x);
                            coo.push_back(y-1);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x][y-1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x);
                            coo.push_back(y-1);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x);
                        coo.push_back(y-1);
                        neigh.push_back(coo);
                    }
                }
                if (y+1<m)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x][y+1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x);
                            coo.push_back(y+1);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x][y+1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x);
                            coo.push_back(y+1);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x);
                        coo.push_back(y+1);
                        neigh.push_back(coo);
                    }
                }
                if (x+1<n && y-1>=0)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x+1][y-1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x+1);
                            coo.push_back(y-1);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x+1][y-1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x+1);
                            coo.push_back(y-1);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x+1);
                        coo.push_back(y-1);
                        neigh.push_back(coo);
                    }
                }
                if (x+1<n)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x+1][y]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x+1);
                            coo.push_back(y);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x+1][y]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x+1);
                            coo.push_back(y);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x+1);
                        coo.push_back(y);
                        neigh.push_back(coo);
                    }
                }
                if (x+1<n && y+1<m)
                {
                    if(object==2)
                    {
                        if (field.infected_matrix[x+1][y+1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x+1);
                            coo.push_back(y+1);
                            neigh.push_back(coo);
                        }
                    }
                    else if (object==0)
                    {
                        if (field.matrix_field[x+1][y+1]==0)
                        {
                            std::vector<int> coo;
                            coo.push_back(x+1);
                            coo.push_back(y+1);
                            neigh.push_back(coo);
                        }
                    }
                    else
                    {
                        std::vector<int> coo;
                        coo.push_back(x+1);
                        coo.push_back(y+1);
                        neigh.push_back(coo);
                    }
                }
                return neigh;
            }

            int find(const std::vector<Animal*>& objects, int x, int y)
            {
                int ind=-1;
                for (int i=0; i<objects.size(); i++)
                {
                    if(objects[i]->x_coo()==x && objects[i]->y_coo()==y)
                    {
                        ind=i;
                        break;
                    }
                }
                return ind;
            }

            void Wolf::move(Field& field, std::vector<Animal*>& objects, const Info& info_game)
            {
                if (stage==0)
                {
                    Graph G;
                    for(int x1=this->x_coo()-vision; x1<=(this->x_coo()+vision); x1++)
                    {
                        for(int y1=this->y_coo()-vision; y1<=(this->y_coo()+vision); y1++)
                        {
                            if (x1>=0 && x1<field.get_n() && y1>=0 && y1<field.get_m())
                            {
                                Vertex v;
                                v.x=x1;
                                v.y=y1;
                                v.name=field.matrix_field[x1][y1];
                                v.neighbours=neighbours(field,field.get_n(),field.get_m(), x1, y1, 3);
                                G.graph.push_back(v);
                            }
                        }
                    }
                    if (time_without_food>time_full_food && this->sex=="F")
                    {
                        G.BFS(this->x_coo(), this->y_coo(), 20, 21, 30, this->vision);
                        if (!G.path1.empty() && !G.path2.empty())
                        {
                            if(G.path1.size()<G.path2.size())
                            {
                                if (G.path1.size()<=speed+1)
                                {
                                    int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                    if (index==-1)
                                        return;
                                    field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                    objects[index]->death();
                                    if (objects[index]->reproduction_pair!= nullptr)
                                    {
                                        objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                        objects[index]->reproduction_pair->set_stage(0);
                                    }
                                    delete objects[index];
                                    objects.erase(objects.begin()+index);
                                    this->time_without_food=0;
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                                else
                                {
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                            }
                            else{
                                if (G.path2.size()<=speed+1)
                                {
                                    int index=find(objects, G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                    if (index==-1)
                                        return;
                                    field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                    objects[index]->death();
                                    if (objects[index]->reproduction_pair!= nullptr)
                                    {
                                        objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                        objects[index]->reproduction_pair->set_stage(0);
                                    }
                                    delete objects[index];
                                    objects.erase(objects.begin()+index);
                                    this->time_without_food=0;
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                                else
                                {
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path2[speed][0], G.path2[speed][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                            }
                        }
                        else if(!G.path1.empty())
                        {
                            if (G.path1.size()<=speed+1)
                            {
                                int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                objects[index]->death();
                                if (objects[index]->reproduction_pair!= nullptr)
                                {
                                    objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                    objects[index]->reproduction_pair->set_stage(0);
                                }
                                delete objects[index];
                                objects.erase(objects.begin()+index);
                                this->time_without_food=0;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                            else
                            {
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else if(!G.path2.empty())
                        {
                            if (G.path2.size()<=speed+1)
                            {
                                int index=find(objects, G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                objects[index]->death();
                                if (objects[index]->reproduction_pair!= nullptr)
                                {
                                    objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                    objects[index]->reproduction_pair->set_stage(0);
                                }
                                delete objects[index];
                                objects.erase(objects.begin()+index);
                                this->time_without_food=0;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                            else
                            {
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path2[speed][0], G.path2[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else if (!G.path3.empty())
                        {
                            if (G.path3.size()<=speed+2)
                            {
                                int index=find(objects, G.path3[G.path3.size()-1][0], G.path3[G.path3.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path3[G.path3.size()-2][0], G.path3[G.path3.size()-2][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                                this->stage=1;
                                this->reproduction_pair= objects[index];
                                objects[index]->set_stage(1);
                                objects[index]->reproduction_pair=this;
                            }
                            else
                            {
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path3[speed][0], G.path3[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else{
                            int x1=this->x_coo();
                            int y1=this->y_coo();
                            field.pop(x1,y1);
                            for(int i=0; i<speed; i++)
                            {
                                std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                                if (neigh.empty())
                                    break;
                                int c =rand()%neigh.size();
                                x1=neigh[c][0];
                                y1=neigh[c][1];
                            }
                            this->Set_coordinates(x1,y1);
                            if (this->sex=="F")
                                field.upgrade_field(31, x_coo(), y_coo());
                            else
                                field.upgrade_field(30, x_coo(), y_coo());
                        }
                    }
                    else if (time_without_food>time_full_food && this->sex=="M")
                    {
                        G.BFS(this->x_coo(), this->y_coo(), 20, 21, 31, this->vision);
                        if (!G.path1.empty() && !G.path2.empty())
                        {
                            if(G.path1.size()<G.path2.size())
                            {
                                if (G.path1.size()<=speed+1)
                                {
                                    int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                    if (index==-1)
                                        return;
                                    field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                    objects[index]->death();
                                    if (objects[index]->reproduction_pair!= nullptr)
                                    {
                                        objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                        objects[index]->reproduction_pair->set_stage(0);
                                    }
                                    delete objects[index];
                                    objects.erase(objects.begin()+index);
                                    this->time_without_food=0;
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                                else
                                {
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                            }
                            else{
                                if (G.path2.size()<=speed+1)
                                {
                                    int index=find(objects, G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                    if (index==-1)
                                        return;
                                    field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                    objects[index]->death();
                                    if (objects[index]->reproduction_pair!= nullptr)
                                    {
                                        objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                        objects[index]->reproduction_pair->set_stage(0);
                                    }
                                    delete objects[index];
                                    objects.erase(objects.begin()+index);
                                    this->time_without_food=0;
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                                else
                                {
                                    field.pop(x_coo(),y_coo());
                                    this->Set_coordinates(G.path2[speed][0], G.path2[speed][1]);
                                    if (this->sex=="F")
                                        field.upgrade_field(31, x_coo(), y_coo());
                                    else
                                        field.upgrade_field(30, x_coo(), y_coo());
                                }
                            }
                        }
                        else if(!G.path1.empty())
                        {
                            if (G.path1.size()<=speed+1)
                            {
                                int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                objects[index]->death();
                                if (objects[index]->reproduction_pair!= nullptr)
                                {
                                    objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                    objects[index]->reproduction_pair->set_stage(0);
                                }
                                delete objects[index];
                                objects.erase(objects.begin()+index);
                                this->time_without_food=0;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                            else
                            {
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else if(!G.path2.empty())
                        {
                            if (G.path2.size()<=speed+1)
                            {
                                int index=find(objects, G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                                objects[index]->death();
                                if (objects[index]->reproduction_pair!= nullptr)
                                {
                                    objects[index]->reproduction_pair->reproduction_pair= nullptr;
                                    objects[index]->reproduction_pair->set_stage(0);
                                }
                                delete objects[index];
                                objects.erase(objects.begin()+index);
                                this->time_without_food=0;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path2[G.path2.size()-1][0], G.path2[G.path2.size()-1][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                            else
                            {
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path2[speed][0], G.path2[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else if (!G.path3.empty())
                        {
                            if (G.path3.size()<=speed+2)
                            {
                                int index=find(objects, G.path3[G.path3.size()-1][0], G.path3[G.path3.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path3[G.path3.size()-2][0], G.path3[G.path3.size()-2][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                                this->stage=1;
                                this->reproduction_pair= objects[index];
                                objects[index]->set_stage(1);
                                objects[index]->reproduction_pair=this;
                            }
                            else
                            {
                                field.pop(x_coo(), y_coo());
                                this->Set_coordinates(G.path3[speed][0], G.path3[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else{
                            int x1=this->x_coo();
                            int y1=this->y_coo();
                            field.pop(x1,y1);
                            for(int i=0; i<speed; i++)
                            {
                                std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                                if (neigh.empty())
                                    break;
                                int c =rand()%neigh.size();
                                x1=neigh[c][0];
                                y1=neigh[c][1];
                            }
                            this->Set_coordinates(x1,y1);
                            if (this->sex=="F")
                                field.upgrade_field(31, x_coo(), y_coo());
                            else
                                field.upgrade_field(30, x_coo(), y_coo());
                        }
                    }
                    else if (this->sex=="F")
                    {
                        G.BFS(this->x_coo(), this->y_coo(), 30, 30, 30, this->vision);
                        if (!G.path1.empty())
                        {
                            if (G.path1.size()<=speed+2)
                            {
                                int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[G.path1.size()-2][0], G.path1[G.path1.size()-2][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                                this->stage=1;
                                this->reproduction_pair= objects[index];
                                objects[index]->set_stage(1);
                                objects[index]->reproduction_pair=this;
                            }
                            else
                            {
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else
                        {
                            int x1=this->x_coo();
                            int y1=this->y_coo();
                            field.pop(x1,y1);
                            for(int i=0; i<speed; i++)
                            {
                                std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                                if (neigh.empty())
                                    break;
                                int c =rand()%neigh.size();
                                x1=neigh[c][0];
                                y1=neigh[c][1];
                            }
                            this->Set_coordinates(x1,y1);
                            if (this->sex=="F")
                                field.upgrade_field(31, x_coo(), y_coo());
                            else
                                field.upgrade_field(30, x_coo(), y_coo());
                        }
                    }
                    else
                    {
                        G.BFS(this->x_coo(), this->y_coo(), 31, 31, 31, this->vision);
                        if (!G.path1.empty())
                        {
                            if (G.path1.size()<=speed+2)
                            {
                                int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                                if (index==-1)
                                    return;
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[G.path1.size()-2][0], G.path1[G.path1.size()-2][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                                this->stage=1;
                                this->reproduction_pair= objects[index];
                                objects[index]->set_stage(1);
                                objects[index]->reproduction_pair=this;
                            }
                            else
                            {
                                field.pop(x_coo(),y_coo());
                                this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                                if (this->sex=="F")
                                    field.upgrade_field(31, x_coo(), y_coo());
                                else
                                    field.upgrade_field(30, x_coo(), y_coo());
                            }
                        }
                        else
                        {
                            int x1=this->x_coo();
                            int y1=this->y_coo();
                            field.pop(x1,y1);
                            for(int i=0; i<speed; i++)
                            {
                                std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                                if (neigh.empty())
                                    break;
                                int c =rand()%neigh.size();
                                x1=neigh[c][0];
                                y1=neigh[c][1];
                            }
                            this->Set_coordinates(x1,y1);
                            if (this->sex=="F")
                                field.upgrade_field(31, x_coo(), y_coo());
                            else
                                field.upgrade_field(30, x_coo(), y_coo());
                        }
                    }
                }
                else
                {
                    if (reproduction_pair!= nullptr)
                    {
                        if (reproduction_pair->is_live())
                        {
                            this->current_time_reproduction++;
                            //reproduction_pair->upgrade_current_time_reproduction();
                            if (current_time_reproduction==time_for_reproduction && reproduction_pair->get_current_time_reproduction()==time_for_reproduction)
                            {
                                stage=0;
                                reproduction_pair->set_stage(0);
                                current_time_reproduction=0;
                                reproduction_pair->clear_current_time_reproduction();
                                std::vector<std::vector<int>> neigh;
                                if (this->get_sex()=="M")
                                    neigh= neighbours(field,field.get_n(), field.get_m(), reproduction_pair->x_coo(), reproduction_pair->y_coo(), 0);
                                else
                                    neigh= neighbours(field,field.get_n(), field.get_m(), this->x_coo(), this->y_coo(), 0);
                                reproduction_pair->reproduction_pair= nullptr;
                                reproduction_pair= nullptr;
                                if (!neigh.empty())
                                {
                                    Wolf* p = new Wolf(info_game);
                                    int c =rand()%neigh.size();
                                    p->Set_coordinates(neigh[c][0], neigh[c][1]);
                                    if (p->get_sex()=="F")
                                        field.upgrade_field(31, p->x_coo(), p->y_coo());
                                    else
                                        field.upgrade_field(30, p->x_coo(), p->y_coo());
                                    objects.push_back(p);
                                }
                            }
                        }
                        else
                        {
                            reproduction_pair= nullptr;
                            stage=0;
                        }
                    }
                    else
                        stage=0;
                }
            }

void Animal::clear_statistic() {
    number_died_animals=0;
    number_born_animals=0;
    age_old_animal=0;
}

void Wolf::clear_statistic() {
    Animal::clear_statistic();
    number_born_wolfs=0;
    number_died_wolfs=0;
    age_old_wolf=0;
}

void Rabbit::clear_statistic() {
    number_died_rabbits=0;
    number_born_rabbits=0;
    age_old_rabbit=0;
}

void Grass::clear_statistic() {
    number_born_grass=0;
    number_died_grass=0;
    age_old_grass=0;
}

void Rabbit::move(Field& field, std::vector<Animal*>& objects, const Info& info_game)
{
    field.upgrade_infected(vision, x_coo(), y_coo());
    if (stage==0)
    {
        Graph G;
        for (int x1 = this->x_coo() - vision; x1 <= (this->x_coo() + vision); x1++)
        {
            for (int y1 = this->y_coo() - vision; y1 <= (this->y_coo() + vision); y1++) {
                if (x1 >= 0 && x1 < field.get_n() && y1 >= 0 && y1 < field.get_m()) {
                    Vertex v;
                    v.x = x1;
                    v.y = y1;
                    v.name = field.matrix_field[x1][y1];
                    v.neighbours = neighbours(field, field.get_n(), field.get_m(), x1, y1, 2);
                    G.graph.push_back(v);
                }
            }
        }
        if(time_without_food>time_full_food && sex=="F")
        {
            G.BFS(this->x_coo(), this->y_coo(), 1, 20, 20, this->vision);
            if(!G.path1.empty())
            {
                if (G.path1.size()<=speed+1)
                {
                    int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                    if (index==-1)
                        return;
                    field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                    objects[index]->death();
                    if (objects[index]->reproduction_pair!= nullptr)
                    {
                        objects[index]->reproduction_pair->reproduction_pair= nullptr;
                        objects[index]->reproduction_pair->set_stage(0);
                    }
                    delete objects[index];
                    objects.erase(objects.begin()+index);
                    this->time_without_food=0;
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
                else
                {
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
            }
            else if (!G.path3.empty())
            {
                if (G.path3.size()<=speed+2)
                {
                    int index=find(objects, G.path3[G.path3.size()-1][0], G.path3[G.path3.size()-1][1]);
                    if (index==-1)
                        return;
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path3[G.path3.size()-2][0], G.path3[G.path3.size()-2][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                    this->stage=1;
                    this->reproduction_pair= objects[index];
                    objects[index]->set_stage(1);
                    objects[index]->reproduction_pair=this;
                }
                else
                {
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path3[speed][0], G.path3[speed][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
            }
            else{
                int x1=this->x_coo();
                int y1=this->y_coo();
                field.pop(x1,y1);
                for(int i=0; i<speed; i++)
                {
                    std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                    if (neigh.empty())
                        break;
                    int c =rand()%neigh.size();
                    x1=neigh[c][0];
                    y1=neigh[c][1];
                }
                this->Set_coordinates(x1,y1);
                if (this->sex=="F")
                    field.upgrade_field(21, x_coo(), y_coo());
                else
                    field.upgrade_field(20, x_coo(), y_coo());
            }
        }
        else if(time_without_food>time_full_food && sex=="M")
        {
            G.BFS(this->x_coo(), this->y_coo(), 1, 21, 21, this->vision);
            if(!G.path1.empty())
            {
                if (G.path1.size()<=speed+1)
                {
                    int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                    if (index==-1)
                        return;
                    field.pop(objects[index]->x_coo(),objects[index]->y_coo());
                    objects[index]->death();
                    if (objects[index]->reproduction_pair!= nullptr)
                    {
                        objects[index]->reproduction_pair->reproduction_pair= nullptr;
                        objects[index]->reproduction_pair->set_stage(0);
                    }
                    delete objects[index];
                    objects.erase(objects.begin()+index);
                    this->time_without_food=0;
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
                else
                {
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
            }
            else if (!G.path3.empty())
            {
                if (G.path3.size()<=speed+2)
                {
                    int index=find(objects, G.path3[G.path3.size()-1][0], G.path3[G.path3.size()-1][1]);
                    if (index==-1)
                        return;
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path3[G.path3.size()-2][0], G.path3[G.path3.size()-2][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                    this->stage=1;
                    this->reproduction_pair= objects[index];
                    objects[index]->set_stage(1);
                    objects[index]->reproduction_pair=this;
                }
                else
                {
                    field.pop(x_coo(),y_coo());
                    this->Set_coordinates(G.path3[speed][0], G.path3[speed][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
            }
            else{
                int x1=this->x_coo();
                int y1=this->y_coo();
                field.pop(x1,y1);
                for(int i=0; i<speed; i++)
                {
                    std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                    if (neigh.empty())
                        break;
                    int c =rand()%neigh.size();
                    x1=neigh[c][0];
                    y1=neigh[c][1];
                }
                this->Set_coordinates(x1,y1);
                if (this->sex=="F")
                    field.upgrade_field(21, x_coo(), y_coo());
                else
                    field.upgrade_field(20, x_coo(), y_coo());
            }
        }
        else if (this->sex=="F")
        {
            G.BFS(this->x_coo(), this->y_coo(), 20, 20, 20, this->vision);
            if (!G.path1.empty())
            {
                if (G.path1.size()<=speed+2)
                {
                    int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                    if (index==-1)
                        return;
                    field.pop(x_coo(), y_coo());
                    this->Set_coordinates(G.path1[G.path1.size()-2][0], G.path1[G.path1.size()-2][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                    this->stage=1;
                    this->reproduction_pair= objects[index];
                    objects[index]->set_stage(1);
                    objects[index]->reproduction_pair=this;
                }
                else
                {
                    field.pop(x_coo(), y_coo());
                    this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
            }
            else
            {
                int x1=this->x_coo();
                int y1=this->y_coo();
                field.pop(x_coo(), y_coo());
                for(int i=0; i<speed; i++)
                {
                    std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                    if (neigh.empty())
                        break;
                    int c =rand()%neigh.size();
                    x1=neigh[c][0];
                    y1=neigh[c][1];
                }
                this->Set_coordinates(x1,y1);
                if (this->sex=="F")
                    field.upgrade_field(21, x_coo(), y_coo());
                else
                    field.upgrade_field(20, x_coo(), y_coo());
            }
        }
        else
        {
            G.BFS(this->x_coo(), this->y_coo(), 21, 21, 21, this->vision);
            if (!G.path1.empty())
            {
                if (G.path1.size()<=speed+2)
                {
                    int index=find(objects, G.path1[G.path1.size()-1][0], G.path1[G.path1.size()-1][1]);
                    if (index==-1)
                        return;
                    field.pop(x_coo(), y_coo());
                    this->Set_coordinates(G.path1[G.path1.size()-2][0], G.path1[G.path1.size()-2][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                    this->stage=1;
                    this->reproduction_pair= objects[index];
                    objects[index]->set_stage(1);
                    objects[index]->reproduction_pair=this;
                }
                else
                {
                    field.pop(x_coo(), y_coo());
                    this->Set_coordinates(G.path1[speed][0], G.path1[speed][1]);
                    if (this->sex=="F")
                        field.upgrade_field(21, x_coo(), y_coo());
                    else
                        field.upgrade_field(20, x_coo(), y_coo());
                }
            }
            else
            {
                int x1=this->x_coo();
                int y1=this->y_coo();
                field.pop(x1, y1);
                for(int i=0; i<speed; i++)
                {
                    std::vector<std::vector<int>>neigh= neighbours(field,field.get_n(), field.get_m(), x1, y1, 0);
                    if (neigh.empty())
                        break;
                    int c =rand()%neigh.size();
                    x1=neigh[c][0];
                    y1=neigh[c][1];
                }
                this->Set_coordinates(x1,y1);
                if (this->sex=="F")
                    field.upgrade_field(21, x1, y1);
                else
                    field.upgrade_field(20, x1, y1);
            }
        }
    }
    else
    {
        if (reproduction_pair!= nullptr)
        {
            if (reproduction_pair->is_not_killed(field))
            {
                this->current_time_reproduction++;
                //reproduction_pair->upgrade_current_time_reproduction();
                if (current_time_reproduction==time_for_reproduction && reproduction_pair->get_current_time_reproduction()==time_for_reproduction)
                {
                    stage=0;
                    reproduction_pair->set_stage(0);
                    current_time_reproduction=0;
                    reproduction_pair->clear_current_time_reproduction();
                    std::vector<std::vector<int>> neigh;
                    if (this->get_sex()=="M")
                        neigh= neighbours(field,field.get_n(), field.get_m(), reproduction_pair->x_coo(), reproduction_pair->y_coo(), 0);
                    else
                        neigh= neighbours(field,field.get_n(), field.get_m(), this->x_coo(), this->y_coo(), 0);
                    reproduction_pair->reproduction_pair= nullptr;
                    reproduction_pair= nullptr;
                    if (!neigh.empty())
                    {
                        auto* p = new Rabbit(info_game);
                        int c =rand()%neigh.size();
                        p->Set_coordinates(neigh[c][0], neigh[c][1]);
                        if (p->get_sex()=="F")
                            field.upgrade_field(21, p->x_coo(), p->y_coo());
                        else
                            field.upgrade_field(20, p->x_coo(), p->y_coo());
                        objects.push_back(p);
                    }
                }
            }
            else
            {
                reproduction_pair= nullptr;
                stage=0;
            }
        }
        else
            stage=0;
    }
}


void Grass::move(Field& field, std::vector<Animal*>& objects, const Info& info_game)
{
    if (stage==0) {
        std::vector<std::vector<int>> neigh = neighbours_grass(field, field.get_n(), field.get_m(), x_coo(), y_coo());
        for (int i = 0; i < neigh.size(); i++) {
            int index = find(objects, neigh[i][0], neigh[i][1]);
            if (index==-1)
                return;
            //if (((Grass *) &objects[index])->reproduction_pair == nullptr)
            if (objects[index]->reproduction_pair== nullptr)
            {
                this->stage = 1;
                this->reproduction_pair = objects[index];
                objects[index]->set_stage(1);
                objects[index]->reproduction_pair = this;
                break;
            }
        }
    }
    else
    {
        if (reproduction_pair!= nullptr)
        {
            if (reproduction_pair->is_not_killed(field))
            {
                this->current_time_reproduction++;
                //reproduction_pair->upgrade_current_time_reproduction();
                if (current_time_reproduction==time_for_reproduction && reproduction_pair->get_current_time_reproduction()==time_for_reproduction)
                {
                    stage=0;
                    reproduction_pair->set_stage(0);
                    current_time_reproduction=0;
                    reproduction_pair->clear_current_time_reproduction();
                    std::vector<std::vector<int>> neigh;
                    neigh= neighbours(field,field.get_n(), field.get_m(), reproduction_pair->x_coo(), reproduction_pair->y_coo(), 0);
                    if(neigh.empty())
                    {
                        neigh= neighbours(field,field.get_n(), field.get_m(), this->x_coo(), this->y_coo(), 0);
                    }
                    reproduction_pair->reproduction_pair= nullptr;
                    reproduction_pair= nullptr;
                    if (!neigh.empty())
                    {
                        auto* p = new Grass(info_game);
                        int c =rand()%neigh.size();
                        p->Set_coordinates(neigh[c][0], neigh[c][1]);
                        field.upgrade_field(1, p->x_coo(), p->y_coo());
                        objects.push_back(p);
                    }
                }
            }
            else
            {
                reproduction_pair= nullptr;
                stage=0;
            }
        }
        else
            stage=0;
    }
}