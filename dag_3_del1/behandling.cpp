#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int main() {

    fstream data;
    int amount_of_lines = 0;


    data.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (data.is_open()){ //checking whether the file is open
      string bd;

      while(getline(data, bd)){ //read data from file object and put it into string.
        amount_of_lines+=1;
      }
    }


    int arr[12][amount_of_lines];

    fstream data2;
    data2.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (data2.is_open()){ //checking whether the file is open
      string bd;
      int on_line = 0;
      int debug = 0;

      while(getline(data2, bd)){ //read data from file object and put it into string.
        for (int i=0; i<12;i++) {
          debug=(bd[i]-'0');
          arr[i][on_line]=(bd[i]-'0');
        }
        on_line++;
      }
      
    }


  int amount_of_0 = 0;
  int amount_of_1 = 0;
  int array_avg[12];

  for (int i = 0; i<12; i++) {
    for (int j = 0; j<amount_of_lines; j++) {

      if (arr[i][j]==1) {
        amount_of_1+=1;
      } else if (arr[i][j]==0) {
        amount_of_0+=1;
      }
    }

  if (amount_of_1>amount_of_0) {array_avg[i]=1;} else {array_avg[i]=0;}

  amount_of_0 = 0;
  amount_of_1 = 0;
  }

  int epsilon[12];
  for (int k=0; k<12; k++) {

    if (array_avg[k]==1) {
      epsilon[k]=0;
    } else {
      epsilon[k]=1;
    }

  }

  //find decimalværdi for arrays:
  int gamma = 0;

  for (int i=0; i<12; i++) {
    gamma+=pow(2,11-i)*array_avg[i];
  } 

  int kappa = 0;

  for (int i=0; i<12; i++) {
    kappa+=pow(2,11-i)*epsilon[i];
  } 

  cout<<"\n"<<gamma*kappa<<"\n";





  fstream data3;

  data3.open("output8.txt",ios::in); //open a file to perform read operation using file object

  if (data3.is_open()){ //checking whether the file is open
      string bd3;
      int i = 9;
      fstream output_gamma;
      output_gamma.open("output9.txt",ios::out);
      while(getline(data3, bd3)){ //read data from file object and put it into string.

        if ((bd3[i]-'0')==0) {

          if ((bd3[i+1])-'0'==0) {
            output_gamma<<bd3<<"Y\n";
          } else {
            output_gamma<<bd3<<"X\n";

          }

        }
      }

    }



}





//Del 2
//array_avg beskriver gennemsnittet for 1,2,3,4 osv. plads. Derved kan løsningen nemt udvides:

//gamma: 101111111101
//110101111111
//3455


//kappa: 010000000010
//001110010010
//914

//3157870

//3148794
//3000000











