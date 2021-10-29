#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
//String array which is initialzed with months of the year 
string getmonth[] ={"January","February","March","April","May","June","July","August","September","October","November", "December"};

//declars a struct node which holds our data values
struct node{
 char fname[20]; char lname[20];
 //Address data 
 char address[40]; char city[40]; char state[40];
 //Birthday Data
 int bd; int bm; int by;
 //Anniversary Data 
 int ad; int am; int ay; 
 struct node *next;
 }; 
 
 //declares class to hold our member functions
class records
 {
 private:
 	//Declares a private instance header node which points to the top of the list
 struct node *head; 
 public:
 records()
 {
 head = 0;
 }
 //declares the member functions of class records
 //adds a new entry
 void new_entry(struct node&); 
 //deletes record
 void delrecord();
 //changes record
 void changerecord();
 //displays all of the existing records
 void display();
 //
 void gen_b_cards();
 void gen_a_cards();
 };


//helper function
void takeinput(struct node& temp);
