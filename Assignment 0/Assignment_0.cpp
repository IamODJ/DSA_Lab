/* DSA Lab Assignment 0
Submitted by-
Omkar D Jadhav
190010029*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> //for using string buffer in getline function
#include <iomanip> // for formatting average to 2 decimal points

using namespace std;

int main(int argc,char *argv[]) 
{
string buff;
int max,min,num;
float counter=0,sum=0;  // initialising as floats to avoid overflow
ifstream file1;
ofstream file2;
file1.open(argv[1]);
file2.open("output.txt");

if(getline(file1,buff))  //initialising values of max,min and sum
{
 counter++;
 num=atoi(buff.c_str());  // converting string to integer.
 max=num;
 min=num;
 sum+=num;
}


while(getline(file1,buff))
{
 counter++;
 num=atoi(buff.c_str());
  if(num>max)
   max=num;
  if(num<min)
   min=num;

 sum+=num;
}

file2<<int(counter)<<'\n';
file2<<min<<'\n';
file2<<max<<'\n';
file2<<int(sum)<<'\n';
file2<<fixed<<setprecision(2)<<sum/counter<<'\n';

file1.close();
file2.close();

return 0;
}
