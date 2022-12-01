#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void create_array() {
}


int main () {

    fstream data;
    data.open("input.txt",ios::in); //open a file to perform read operation using file object


   if (data.is_open()){ //checking whether the file is open
      string bd;
      while(getline(data, bd)){ //read data from file object and put it into string.

      }

}
}