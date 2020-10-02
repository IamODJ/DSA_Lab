/* DSA Lab Assignment 1
Submitted by-
Omkar D Jadhav
190010029*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> //for using string buffer in getline function

using namespace std;


void mergearr(int arr[],int low,int mid,int high)
{
int l=(mid-low) +1;
int r= high-mid;
int leftArr[l],rightArr[r]; // make two partitions 

for(int i=0;i<l;i++)
   leftArr[i]=arr[low+i];  

for(int i=0;i<r;i++)
   rightArr[i]=arr[mid+1+i];

int i=0,j=0,index=low;

while(i<l && j<r)
{
if(leftArr[i]>=rightArr[j])
    arr[index++]=rightArr[j++];
else
    arr[index++]=leftArr[i++];

}

while(i<l)        // merge the reamining elements
arr[index++]=leftArr[i++];

while(j<r)
arr[index++]=rightArr[j++];

}
void mergesort(int arr[], int low, int high)
{
    if(high>low)
     {
	int mid= low+(high-low)/2 ;
	mergesort(arr,low,mid);
	mergesort(arr,mid+1,high);
	mergearr(arr,low,mid,high);
     }

}



int main(int argc,char *argv[]) 
{
string buff;
long int counter=0,ptr=0,num;  // initialising as floats to avoid overflow
ifstream file1;
ofstream file2;
file1.open(argv[1]);
file2.open("mergesort.txt"); 

while(getline(file1,buff))
{
 counter++;                   // first count how many ints are present. 
 							 // could have used a vector for dynamic allocation, please allow its usage.
}

file1.clear();
file1.seekg(0,file1.beg);
int arr[counter];
while(getline(file1,buff))
{

 num=atoi(buff.c_str());  // converting string to int
 arr[ptr]=num;
 ptr++;
}


mergesort(arr,0,counter-1);

for(int i=0;i<counter;i++)
file2<<arr[i]<<'\n';      // finally pushing results to the file


file1.close();
file2.close();

return 0;
}
