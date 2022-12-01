#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int increases = 0;
int value = 0;
int pre_value = 0;
int amount_of_values = 1;

int main() {


    fstream data;

    data.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (data.is_open()){ //checking whether the file is open
      string bd;
      (getline(data,bd));
      pre_value=stoi(bd);

      while(getline(data, bd)){ //read data from file object and put it into string.
         cout << bd << " "; //print the data of the string
         amount_of_values+=1;
          if (stoi(bd)>pre_value) {
            increases+=1;
          }
          pre_value=stoi(bd);
      }
      }
        cout<<"\nThe amount of increases is: "<<increases<<"\n";


        int arr[amount_of_values];
        int a = 0;
        int b = 0;
        
        fstream data2;
        data2.open("input.txt",ios::in); //open a file to perform read operation using file object
    if (data2.is_open()){ //checking whether the file is open
      string bd2;
        int i = 0;
        int group_increases = 0;

      while(getline(data2, bd2)){ //read data from file object and put it into string.
            arr[i]=stoi(bd2);
            i++;
            
      }
        int j = 0;

      while (j < (amount_of_values-2)) {

            a = arr[j]+arr[j+1]+arr[j+2];
            b = arr[j+1]+arr[j+2]+arr[j+3];
                if (b>a) {
                    group_increases+=1;
                }
            cout<<"\n The group values are A: "<<a<<" and B: "<<b;
            j++;
      }


      cout<<"\nThe amount of group increases is: "<<group_increases<<"\n";
      }




    return 0;
}
