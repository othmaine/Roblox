#include <iostream>
#include <vector>
#define loop(i,n) for(int i=0; i<n; i++)
#define Loop(i,n) for(int i=1; i<n; i++)



class Roblox
{
    /*
     0 1 2 3

     0
     4
     2
     5
     */
    int my_n;
    std::vector<std::vector<std::vector<int>>> my_arr;
public:
    Roblox(int n)
    {
        my_n = n;
        my_arr = std::vector<std::vector<std::vector<int>>>(6,std::vector<std::vector<int>>(n,std::vector<int>(n)));
        //arr[faces][rows of columns][columns]
        loop(i,6)
            loop(j,my_n)
                loop(k,my_n)
                    my_arr[i][j][k] = i;
    }
    void display()
    {
        std::cout<<"your Roblox is now\n";
        loop(i,6)
        {
            std::cout<<"face "<<i<<"\n";
            loop(j,my_n)
            {
                loop(k,my_n)
                    std::cout<<my_arr[i][j][k]<<" ";
                std::cout<<"\n";
            }
        }
        std::cout<<"___________________________\n\n";
    }

    void rotateRow(int indx)
    {
        if(indx <0 || indx>= my_n)
        {
            std::cerr << "Invalid index\n";
            return;
        }

        std::vector<int> temp = my_arr[0][indx];

        loop(i,3)
            my_arr[i][indx] = my_arr[i+1][indx];
        my_arr[3][indx] = temp;

    }
    void rotateColumn(bool cas,int indx) // we first create a vector of the 4 columns to be shifted , shift them , and finally return them back
    {
        if(indx <0 || indx>= my_n)
        {
            std::cerr << "Invalid index\n";
            return;
        }

        std::vector<std::vector<int>> columns(4, std::vector<int>(my_n));
        std::vector<int> faces;
        if(!cas)
            faces = {0,4,2,5};
        else
            faces = {1,4,3,5};


        for(int j = 0; auto face:faces)
        {
            loop(i,my_n)
                columns[j][i] =  my_arr[face][i][indx];
            j++;
        }
        std::vector<int> temp = columns[0];
        loop(i,3)
            columns[i] = columns[i+1];
        columns[3] = temp;

        for(int j = 0; auto face:faces)
        {
            loop(i,my_n)
                my_arr[face][i][indx] = columns[j][i];
            j++;
        }
    }
};

int main()
{
    Roblox* roblox = new Roblox(3);
    roblox->display();
    roblox->rotateColumn(1,1);
    roblox->display();
}
