#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

fstream data;

int xy[2] = {0,0};
int aim = 0;

    data.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (data.is_open()){ //checking whether the file is open
      string bd;

      while(getline(data, bd)){ //read data from file object and put it into string.
         cout << bd << " --"; //print the data of the string

         if (bd.find("up")!=string::npos) {
            aim-= bd[bd.find_first_of(" ")+1]-'0';
         } 
         
         else if (bd.find("down")!=string::npos) {
            aim+= bd[bd.find_first_of(" ")+1]-'0';
         }
         
         else if (bd.find("forward")!=string::npos) {
            xy[1]+= aim*(bd[bd.find_first_of(" ")+1]-'0');
            xy[0]+= bd[bd.find_first_of(" ")+1]-'0';
         }
        

      }
        cout<<"\nThe coordinates are: \nX: "<<xy[0]<<"\nY:"<<xy[1]<<"\n";
        cout<<"\nThe answer is: "<<xy[0]*xy[1]<<"\n";
      }
}