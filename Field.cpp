#include "Field.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>


Field::Field(int n1, int m1) {
    n=n1;
    m=m1;
    for (int i=0; i<n; i++)
    {
        matrix_field.push_back(std::vector<int>(m, 0));
        infected_matrix.push_back(std::vector<int>(m, 0));
    }
}

void Field::print() const {
    for (int i=0; i<m; i++)
        std::cout<<"_";
    std::cout<<"\n";
    for (int i=0; i<n; i++)
    {
        std::cout<<"|";
        for (int j=0; j<m; j++)
        {
            if (matrix_field[i][j]==0)
            {
                std::cout<<" ";
            }
            else if (matrix_field[i][j]==1)
            {
                std::cout<<".";
            }
            else if (matrix_field[i][j]==20)
            {
//                char c=4;
//                std::cout<<c;
                std::cout<<"1";

            }
            else if (matrix_field[i][j]==21)
            {
//                char c=3;
//                std::cout<<c;
                std::cout<<"1";
            }
            else if (matrix_field[i][j]==31)
            {
//                char c=5;
//                std::cout<<c;
                std::cout<<"2";
            }
            else if (matrix_field[i][j]==30)
            {
//                char c=6;
//                std::cout<<c;
                std::cout<<"2";
            }
        }
        std::cout<<"|\n";
    }
    for (int i=0; i<m; i++)
        std::cout<<"_";
    std::cout<<"\n";
    //Sleep(10000);
    //system("cls");
}

void Field::upgrade_field(int object, int x, int y) {
    matrix_field[x][y]=object;
}

std::vector<int> Field::give_free_coordinates() {
    std::vector<int> coo;
    int k=0;
    int n1 = rand()%n;
    int m1=  rand()%m;
    if (n1<0 || n1>=n)
    {
        std::cout<<"wrong func coo";
        n1=abs(n1);
        m1=abs(m1);
    }
    for(int i=n1; i<n1+n; i++)
    {
        if (k==1)
            break;
        for (int j=m1; j<m1+m; j++)
        {
            if (matrix_field[i%n][j%m]==0)
            {
                coo.push_back(i%n);
                coo.push_back(j%m);
                k=1;
                break;
            }
        }
    }
    if (!coo.empty())
    {
        if (coo[0]<0 || coo[0]>=n || coo[1]<0 || coo[1]>=m)
        {
            std::cout<<"Smth wrong with coo";
            coo.clear();
        }
    }
    return coo;
}

void infected_coo(int x, int y, int n, int m, int vision, std::vector<std::vector<int>>& infected_matrix)
{
    for(int i=x-vision; i<=x+vision; i++)
    {
        for(int j=y-vision; j<=y+vision; j++)
        {
            if (i>=0 && i<n && j>=0 && j<m)
                infected_matrix[i][j]=1;
        }
    }
}

void Field::upgrade_infected(int vision_r, int x, int y) {
    std::vector<std::vector<int>> wolfs;
    for (int i=x-vision_r; i<=x+vision_r; i++)
    {
        for (int j=y-vision_r; j<=y+vision_r; j++)
        {
            if (i>=0 && i<n && j>=0 && j<m)
            {
                if (matrix_field[i][j]!=30 && matrix_field[i][j]!=31)
                {
                    infected_matrix[i][j]=0;
                }
                else
                {
                    std::vector<int> coo;
                    coo.push_back(i);
                    coo.push_back(j);
                    wolfs.push_back(coo);
                }
            }
        }
    }
    for(int i=0; i<wolfs.size(); i++)
    {
        infected_coo(wolfs[i][0], wolfs[i][1], this->n, this->m, 1, infected_matrix);
    }
}
