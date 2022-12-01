#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int board[5][5][100];
bool check_board[5][5][100];

//Den skrevne kode overfører al data til et tredimensionelt array. [x][y][z]; x rækker, y kolonner på z bræt.

//Der mangler en funktion der drawer værdier. Det kan godt lade sig gøre, men så overskriver den filen bagefter.
//Der mangler at blive skrevet en funktion der markerer værdier, når trukket fra draw.txt.

int push_number() {
    fstream data;
    data.open("draw_copy.txt"); //open a file to perform read operation using file object

    int number_pulled;

    if (data.is_open()){ 
        string alle_numre;
        while(getline(data, alle_numre)){ 
            while (alle_numre!="") {
                if (alle_numre.find_first_of(",")==2) {
                    number_pulled = stoi(alle_numre.substr(0,2));
                    alle_numre.erase(0,2);

                    //DENNE LINJE REDIGERER IKKE DOKUMENTET. DET BØR DEN.
                    data<<alle_numre;


                    return number_pulled;
                } else if (alle_numre.find_first_of(",")==1) {
                    number_pulled = stoi(alle_numre.substr(0,1));
                    alle_numre.erase(0,2);

                    //DENNE LINJE REDIGERER IKKE DOKUMENTET. DET BØR DEN.
                    data<<alle_numre;

                    
                    return number_pulled;
                }
                else {
                    alle_numre.erase(0,1);
                }
            }
        }
    }
return 0;
}



int main () {

    fstream data;
    data.open("output2.txt",ios::in); //open a file to perform read operation using file object

   if (data.is_open()){ //checking whether the file is open
      string bd;

      int x = 0;
      int y = 0;
      int z = 0;

      int number = 0;

        while(getline(data, bd)){ //read data from file object and put it into string.
            cout<<bd<<"\n";
            while (bd!="") {
                if (bd.find_first_of(",")==2) {
                    number = stoi(bd.substr(0,2));
                    board[x][y][z]=number;
                    bd.erase(0,2);
                    x++;
                } else if (bd.find_first_of(",")==1) {
                    number = stoi(bd.substr(0,1));
                    board[x][y][z]=number;
                    bd.erase(0,2);
                    x++;
                }
                else {
                    bd.erase(0,1);
                }
            }
            if (y==5) {
                y=0;
                z++;
            } else {
                y++;
            }

            x=0;
        }
        
        
        cout<<"\n";

        for (int k=0; k<5; k++) {
            for (int j=0; j<5; j++) {
                cout<<board[j][k][99]<<" ";
            }
            cout<<"\n";
        }

    cout<<push_number()<<" "<<push_number()<<" "<<push_number()<<" "<<push_number();

}
}