/* DSA Lab Assignment 2
Submitted by-
Omkar D Jadhav
190010029*/

#include<iostream>
#include<fstream>
#include<sstream> // for splitting the sentences read
#include<cstdlib>
#include<string> //for using string buffer in getline function

using namespace std;

ifstream file1;
ofstream file2;
ifstream file3;
ofstream file4;

int result=-1;

struct Node{   // standard node with child elements
  int key;
  struct Node *leftChild, *rightChild; 
};
struct Node *Parent =NULL;


struct Node *newChildNode(int childKey){   // generate new node called when insert is executed.
struct Node* tempChild =(struct Node *)malloc(sizeof(struct Node));
 tempChild->key=childKey;
 tempChild->leftChild=NULL;
 tempChild->rightChild=NULL;

 file2<<childKey<<" "<<"inserted\n";

return tempChild;
}

//Tried this function for searching but it is not 
//working and giving segmentation fault. TODO: ask TA's
// void Search(struct Node* rarent, int key)    
// {
//   if(Parent==NULL || Parent->key == key)
//     {
//       if(Parent->key == key)
//         file2<<key<<" found\n";
//       else
//         file2<<key<<" not found\n";

//     }

//   if(Parent->key < key)
//     Search(Parent->rightChild,key);
//   else
//     Search(Parent->leftChild,key);

// }


void Search(int key) {   // standard search function
   Node *temp = new Node;
   temp = Parent;
   while(temp != NULL) {
      if(temp->key == key) {
         file2<<key<<" found\n";
         return;
      } else if(temp->key > key)
         temp = temp->leftChild;
         else
            temp = temp->rightChild;
   }
   file2<<key<<" not found\n";  // we' ll reach here only if key is not found
   return;
}

void SearchNormal(int key) {
   Node *temp = new Node;
   temp = Parent;
   while(temp != NULL) {
      if(temp->key == key) {
         result=1;
         return;
      } else if(temp->key > key)
         temp = temp->leftChild;
         else
            temp = temp->rightChild;
   }
   result=-1;
   return;
}


struct Node* Insert(struct Node* parent, int key)
{
  if(parent==NULL)
    return newChildNode(key);

  if(parent->key >key)
      parent->leftChild= Insert(parent->leftChild,key);
  else
     parent->rightChild= Insert(parent->rightChild,key);

return parent;
}

void inordertrav(struct Node *parent)
{
  if(parent != NULL){
    inordertrav(parent->leftChild);
    file2<<parent->key<<" ";
    inordertrav(parent->rightChild);
  }

}

void preordertrav(struct Node *parent)
{
  if(parent != NULL){
    file2<<parent->key<<" ";
    preordertrav(parent->leftChild);
    preordertrav(parent->rightChild);
  }
}

void postordertrav(struct Node *parent)
{
  if(parent != NULL){
    postordertrav(parent->leftChild);
    postordertrav(parent->rightChild);
    file2<<parent->key<<" ";
  }


}

int minimum(struct Node *parent){
 if(parent->leftChild==NULL)
  return parent->key;
 else
  return minimum(parent->leftChild);
}

int maximum(struct Node *parent){
 if(parent->rightChild==NULL)
  return parent->key;
 else
  return maximum(parent->rightChild);
}

void presuc(Node* parent, Node*& predecessor, Node*& successor, int key) 
{ 
    if (parent == NULL)  return ; 
  
    if (parent->key == key)     //key present at parent 

    { 

            if (parent->leftChild != NULL) 
        { 
            Node* tmp = parent->leftChild; 
            while (tmp->rightChild) 
                tmp = tmp->rightChild; 
            predecessor = tmp ; 
        } 
  
        if (parent->rightChild != NULL) 
        { 
            Node* tmp = parent->rightChild ; 
            while (tmp->leftChild) 
                tmp = tmp->leftChild ; 
            successor = tmp ; 
        } 
        return ; 
    } 
  
    if (parent->key > key) 
    { 
        successor = parent ; 
        presuc(parent->leftChild, predecessor, successor, key) ; 
    } 
    else 
    { 
        predecessor = parent ; 
        presuc(parent->rightChild, predecessor, successor, key) ; 
    } 
} 

// void findpredec(Node* parent,int key){   first try
//   if(parent==NULL)
//     return;
 
// if(parent->key==key)
// {
//   if(parent->leftChild != NULL)
//   {
//     Node* temp = parent->leftChild;
//     while (temp->rightChild)
//       temp= temp->rightChild;
//     file2<<temp->key<<'\n';
//   }
//   else{
//       file2<<"predecessor of "<<key<<" does not exist\n";

//   }
// }
// if(parent->key >key)
// 	findpredec(parent->leftChild, key);
// else
//     findpredec(parent->rightChild, key);


// }

// void findsuccess(Node* parent, int key){
//   if(parent==NULL)
//     return;

// if(parent->key==key)
// {
//   if(parent->rightChild != NULL)
//   {
//     Node* temp = parent->rightChild;
//     while (temp->leftChild)
//       temp= temp->leftChild;
//     file2<<temp->key<<'\n';
    
//   }
//   else{
//       file2<<"successor of "<<key<<" does not exist\n";
//   }
// }
// if(parent->key >key)
// 	findsuccess(parent->leftChild, key);
// else
//     findsuccess(parent->rightChild, key);

// }

int main(int argc,char *argv[]) 
{

string buff;
long int counter=0,ptr=0,num;  // initialising as floats to avoid overflow
file1.open(argv[1]);
file2.open("tempo.txt"); 

while(getline(file1,buff))
{
stringstream temp;
string tempstr,command;
temp<<buff;
temp>>command;
int intarg;
while(!temp.eof())
{
temp>>tempstr;
stringstream(tempstr)>>intarg;
}

if(command=="insert"){
	if(Parent==NULL)
	Parent=Insert(Parent,intarg);
	else
	Insert(Parent,intarg);
	
}

else if(command=="inorder"){
  if(Parent!=NULL){
  inordertrav(Parent);
  file2<<'\n';
}
  else
  file2<<'\n';
}
else if(command=="preorder"){
  if(Parent!=NULL){
  preordertrav(Parent);
  file2<<'\n';
}
  else
  file2<<'\n';
}

else if(command=="postorder"){
  if(Parent!=NULL){
  postordertrav(Parent);
  file2<<'\n';
}
  else
  file2<<'\n';
}

else if(command=="search"){
	if(Parent!=NULL)
      {Search(intarg);}
}
else if(command=="minimum"){
  if(Parent!=NULL)
  file2<<minimum(Parent)<<'\n';
  else
  file2<<'\n';
}

else if(command=="maximum"){
  if(Parent!=NULL)
  file2<<maximum(Parent)<<'\n';
  else
  file2<<'\n';
}
else if(command=="successor")
{
  SearchNormal(intarg);
   if(result==-1)
    file2<<intarg<<" does not exist\n";
  else
  {
  	Node* predecessor = NULL, *successor = NULL; 
    presuc(Parent, predecessor, successor, intarg);
    if(successor != NULL)
    file2<<successor->key<<"\n";
    else
    file2<<"successor of "<<intarg<<" does not exist\n"; 
  }
    // findsuccess(Parent,intarg);
  result=-1;
}

else if(command=="predecessor")
{
   SearchNormal(intarg);
   if(result==-1)
    file2<<intarg<<" does not exist\n";
  else
  {
  	Node* predecessor = NULL, *successor = NULL; 
    presuc(Parent, predecessor, successor, intarg);
    if(predecessor != NULL)
    file2<<predecessor->key<<"\n";
    else
    file2<<"predecessor of "<<intarg<<" does not exist\n"; 
  }
    // findsuccess(Parent,intarg);
  result=-1;
}
}
file2.close();
file1.close();
 file3.open("tempo.txt");
 file4.open("bst.txt");
    char space1,space2;
	string s;
	while(!file3.eof()){
	file3.get(space1);
	if(space1==' ')
	{
		file3.get(space2);
		if(space2=='\n')
			{
				file4.put(space2);
			}
		else{
			file4.put(space1);
			file4.put(space2);
		}
    
	}
	else{
		file4.put(space1);
	} 
    }
file3.close();
file4.close();
int status= remove("tempo.txt");
return 0;
}