#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;

int main()
 {
 	//declares a records object
 records obj;
 //Tests the functions with new nodes
 
 
  struct node a = {"Kwang","Lee","123","Trenton","NJ",21,10,2000,21,10,2000,NULL};
 obj.new_entry(a);

  
 
 struct node b = {"Pappa","Richard","33 Corinthians Ln","Petersville","Caelum",23,10,2005,23,10,2001,NULL};
 obj.new_entry(b);
 
 struct node c = {"Augustine","Hippo","33 Street","Hippo","Africa",24,10,2000,24,10,2001,NULL};
 obj.new_entry(c);
 struct node d = {"Const","Pax","Domini Ave","Rome","Italy",24,10,2009,24,10,2001,NULL};
 obj.new_entry(d);
 struct node e =
{"Johnny","Bravo","267","Jupiter","Space",25,10,2010,25,10,1997,NULL};
 obj.new_entry(e);
 
 int choice; 
 
 //Continues to run while the exit program # isn't chosen
 do
 {
 do{ 
 cout<<endl<<"***********Menu************"<<endl;
 cout<<"Enter a new name into the address book(Enter 1)\n";
 cout<<"Change a name or date in the address book(Enter 2)\n";
 cout<<"Delete a name from the address book(Enter 3)\n";
 cout<<"Display the whole address book(Enter 4)\n";
 cout<<"Generate birthday cards(Enter 5)\n";
 cout<<"Generate anniversary cards(Enter 6)\n";
 cout<<"Exit the card program(Enter 7): ";
 //accepts an int from the user to indicate which function they want to run
 cin>>choice; 
 //checks to see if the input is within a valid range
 if(choice<=0||choice>=8) 
 {
 cout<<"The value entered is invalid. Valid numbers are from 1 to 7.";
 }
 //loops until they input a valid choic
 }while(choice<=0||choice>=8);
 cout<<endl;
 //Takes the inputtd integer from the user
 switch(choice)
 {
 	//if they chose a number then return the corresponding function
 case 1: 
 struct node temp;
 takeinput(temp);
 obj.new_entry(temp);
 break;
 case 2:obj.changerecord();
 break;
 case 3:obj.delrecord();
 break;
 case 4:obj.display();
 break;
 case 5:obj.gen_b_cards();
 break;
 case 6:obj.gen_a_cards();
 break;
 }
 // continue to loop until the number 7 is selected 
 }while(choice!=7);
 
 return 0;
 }
 
 
 //-------New Entry-------//
 //Function takes in a node as a parameter and places it in alphabetical order using first and last name.
void records::new_entry(struct node& a)
{
	//Initializes a new instance of node
    struct node *temp = new struct node;
    //Sets temp == our passed in node
     *temp = a;
 
    //Checks to see if the list is empty 
    if(head==NULL)
 {
 	//Inserts the node at the beginning of the list if the list is empty
 	head = temp;
 	temp->next = NULL;
 }
    //Iterates through the list and places the the node in alphabetical order
 	else
 {
 	//Creates two instances of node 
 	struct node *trav,*prev;
 	
 	//Sets the first node equal to the start 
 	trav = head;
 	//Creates a predLoc node
 	prev = NULL;
 	//Loops through the list while it is not empty 
 	while(trav!=NULL)
 {
 	

 	//Checks to see if the last and first name of the traversing node is greater than the passed in node
 	if((strcmp(trav->lname,temp->lname)>0) || ((strcmp(trav->lname,temp->lname)==0) && (strcmp(trav->fname,temp->fname)>0)) )
 		//If this is the case then break and insert into list
 		break;
 	else
    {
 		//Sets pred Loc to the current position and iterates to the next position 
 		prev = trav;
		trav = trav->next;
    }
}
	//Checks to see if the node has to be inserted at the first position of the list
 	if(prev == NULL)
 {
 	//Inserts the node at the beginning of the list
	 temp->next = head;
 	head = temp;
 }
 	// If the node does not need to be placed in the beginning of the list
 	else
 {
 	//Inserts the node into its proper place behind the node which was greater than it 
 	temp->next = prev->next;
 	prev->next = temp;
 }
 }
} 

//---- Delete Record----//

//Deletes a record in the list 
void records::delrecord()
 {
	//declares two char types with max length of 20
 char first[20],last[20];
 //declares two node types
 struct node *trav, *prev;
 // prompts the user for input in 
 cout<<"Enter the following information to delete the record."<<endl;
 cout<<"Enter the first name: ";
 //stores the input in the first variable
 cin>>first;
 cout<<"Enter the last name: ";
 //stores the input in a last variable
 cin>>last;
 //initializes the traversal and pred loc variables
 trav = head;
 prev = NULL;
 //Loops through the list until the last node
 while(trav!=NULL)
 {
 	//Checks to see if the passed in variables match the current position in the list
 if(strcmp(first,trav->fname)==0 && strcmp(last,trav->lname)==0)
 {
 	//checks to see if the match occured in the first node
 if(prev == NULL) 
 {
 //points the head to the next node 
 head = trav->next; 
 }
 else
 {
 //deletes the current position by linking the pred loc to the next position 
 prev->next = trav->next; 
 }
 //Deletes the current position to free the meomory and indicates a successful deletion
 delete trav; 
 cout<<"The record has been deleted.\n"<<endl;
 break;
 }
 //If the string is not equal then traverse to the next position in the list
 else
 {
 prev = trav;
 trav = trav->next;//
 } 
 } 
 //Checks to see if the end of the list has been reached and indicates a failure message
 if(trav==NULL) 
 {
 cout<<"The Record Is Not In the List Or Has Been Misspelled."<<endl;
 }
 }
 
 
 // ---- ChangeRecord -----//
 //Edits the existing record 
void records::changerecord()
 {
 //declares two char types with max length of 20
 char first[20],last[20]; 
 //declares four node types
 struct node* temp, *trav, *prev;
 struct node a;
 // Prompts the user for the first and last name and stores it in two char variables 
 cout<<"Enter the first name of the person whose record has to be changed: ";
 cin>>first;
 cout<<"Enter the last name of the person whose record has to be changed: ";
 cin>>last;
 //Initialzes the head and predloc nodes
 trav = head;
 prev = NULL;
 //Traverses the list until the end 
     while(trav!=NULL)
 {
 //Checks to see if the passed in variables match the current position in the list
	 if(strcmp(first,trav->fname)==0 && strcmp(last,trav->lname)==0)
 {
	//Checks to see if the list is empty
 	if(prev == NULL)
 {	//skip over the current node to remove it from the list
	 head = trav->next;
 }
	 else
 {	//skip over the current node to remove it from the list
 	prev->next = trav->next;
 }
 //dealocates the memory of the current position
 	delete trav;
 	break;
 }
 //if the value hasn't been found then traverse to the next node
 	else
 {
 	prev = trav;
 	trav = trav->next;//
 } 
 
 } 
 	//checks to see if the end of the list is reached and prompt the user with an error message
 	if(trav==NULL)
 {
 cout<<"Sorry there was no record."<<endl;
 }
 	//If the record was found then create a new node and input it in the list 
 	else
 {
 	cout<<"Record has been scrubbed, ready for new input"<<endl;
//creates a new node with user input values 
 takeinput(a); 
 //Inserts the node into its proper place post the changes
 new_entry(a); 
 }
 }
 
 
void records::display()//pointer trav will traverse the linked list and print each node till itis null.
 { 
 // creates new instance of node type
 struct node *temp;
 // sets temp equal to the first node in the list
 temp = head;
 //declares a character variable 
 char c;
 // initializes an integer and sets it equal to 1 
 int user_num = 1;
 // checks to see if there are no nodes in the list 
 if(temp == NULL)
 {
 cout<<"The record list is empty."<<endl;
 }
 // iterates through the list while it is not empty
 while(temp!=NULL)
 { 
 
 //Prints the information stored in each node
 cout<<"***********Record "<<user_num<<"************"<<endl;
 cout<<temp->lname<<", "<<temp->fname<<endl;
 cout<<temp->city;
 cout<<", ";
 cout<<temp->state<<endl;
 cout<<"Birthday: ";
 //Checks to see if there is a birth year stored
 if(temp->by!=-1)
 {
 	//Outputs Birth year
 cout<<temp->by<<" ";
 }
 //outputs the string value of the month associated with the inputed value
 cout<<getmonth[(temp->bm)-1]<<" "<<temp->bd<<endl; 
 cout<<"Anniversary: ";
 if(temp->ay!=-1)
 {
 cout<<temp->ay<<" ";
 }
 
 cout<<getmonth[(temp->am)-1]<<" "<<temp->ad<<endl;
 //Printing Complete
 user_num++;
 temp = temp->next;
 }
 
 }
 
 //-----Generate Birthday Cards-----//
 
void records::gen_b_cards()
 {
 	//declares a boolean variable and initializes it to false
 bool flag = false;
 //declares a instance of time_t
 time_t seconds;
 // declares two ints to hold the day and month value 
 int day,month;
 //sets the seconds variable equal to the maximum value since 1970
 seconds = time(NULL);
 //creates time variable which stores a pointer to the current time
 time_t t = time(0); // get time now - inbuilt function.
 // declares a new object of tm type which translates the seconds since 1970 into the local time and stores it in the data variables of tm
 struct tm * now = localtime( & t );
 // stores the month of the current day 
 month = (now->tm_mon + 1); 
 //stores current day value from the now instance of tm 
 day = now->tm_mday; 
 // decalres a new instance of node type
 struct node *temp;
 //sets the new instance equal to the first node 
 temp = head; 
 //loops through the list until the end
 while(temp!=NULL)
 {
 	//Checks to see the day and month of the node are equal to the current day and month 
 if(temp->bd == day && temp->bm == month)
 {
 	//Outputs a birthday message if it is the current day 
 flag = true;
 cout<<"Dear\ "<<temp->fname<<" "<<temp->lname<< "\n"" \nAge is mind over matter, if you don't mind it won't matter. Happy Birthday!.\n\nBest Regards,\n\nMe  \n";
 }
 //if no match is found then iterate through to the next node 
 temp = temp->next;
 }
 //if the end of the list is reached and there is no birthday then output a failure message
 if(!flag)
 cout<<"There Is no birthday today."<<endl;
 }
 
 //function that generates anniversary cards 
void records::gen_a_cards()
 {

 	//declares a boolean variable and initializes it to false
 bool flag = false;
 //declares a instance of time_t
 time_t seconds;
 // declares two ints to hold the day and month value 
 int day,month;
 //sets the seconds variable equal to the maximum value since 1970
 seconds = time(NULL);
 //creates time variable which stores a pointer to the current time
 time_t t = time(0); // get time now - inbuilt function.
 // declares a new object of tm type which translates the seconds since 1970 into the local time and stores it in the data variables of tm
 struct tm * now = localtime( & t );
 // stores the month of the current day 
 month = (now->tm_mon + 1); 
 //stores current day value from the now instance of tm 
 day = now->tm_mday; 
 // decalres a new instance of node type
 struct node *temp;
 //sets the new instance equal to the first node 
 temp = head; 
 //loops through the list until the end
 while(temp!=NULL)
 {
 	//Checks to see the day and month of the node are equal to the current day and month 
 if(temp->ad == day && temp->am == month)
 {
 	//outputs an Anniversary message
 cout<<"Dear "<<temp->fname<<" "<<temp->lname<<"\n""\n It looks like its your anniversary, thats great. \n\n Best Regards,\n\n Your Programmer \n";
 flag = true;
 }
//if no match is found then iterate through to the next node 
 temp = temp->next;
 }
 if(!flag)
 cout<<"There is no anniversary today "<<endl;
 }
 
 // ----Take InPut----//
 
 //Helper function 
void takeinput(struct node& temp)
 {
 	//Sets the next location of temp ==NULL
 temp.next = NULL;
 //declares a character variable
 char c;
 
 	//Prompts the user for input and stores them in the name data variables
 cout<<"Enter the first name: ";
 cin>>temp.fname;
 cout<<"Enter the last name: ";
 cin>>temp.lname;
 // character input to remove trailing key
 c = getchar(); 
 	//Prompts the user for input and stores them in the address data variables
 cout<<"Enter the address: ";
 gets(temp.address);
 cout<<"Enter the city: ";
 gets(temp.city);
 cout<<"Enter the state: ";
 gets(temp.state); 
 
 //Loops through the input process until a valid birthday is inputed
 do
 {
 	//Prompts the user for input and stores them in the birthday data variables
 cout<<"Enter the date of birthday(1-31): ";
 cin>>temp.bd;
 cout<<"Enter the month of birthday(1-12): ";
 cin>>temp.bm; 
 //Checks to see if the inputed dates are within bounds
 if((temp.bd<1||temp.bd>31)||(temp.bm<1||temp.bm>12))
 {
 printf("Invalid Birthday. Valid inputs for date are 1-31 and for month are 1-12.\n");
 }
 //iterates through the input process until a correct value is found
 }while((temp.bd<1||temp.bd>31)||(temp.bm<1||temp.bm>12));
 
 //Prompts the user to respond to a condition
 cout<<"Do you want to enter the birthday year?(Enter y/n): ";
 cin>>c;
 //checks the user prompt for a yes response
 if(c=='y'||c=='Y')
 {
  //Loops through the input process until a valid birth year is inputed
 do
 {
 	//
 cout<<"Enter the birthday year: ";
 cin>>temp.by;
 //checks to see if the year is within bounds
 if(temp.by<1900)
 {
 cout<<"Invalid year. Valid range is greater than 1900.";
 }
 //loops through the do process again until the year is within the correct range
 }while(temp.by<1900);
 }
 //in the case a no value is selected set the birth year to NULL
 else
 {
 temp.by = -1;
 } 
  //Loops through the input process until a valid anniversary is inputed
 do
 {
 	//Prompts the user for input and stores them in the anniversary data variables
 cout<<"Enter the date of anniversary(1-31): ";
 cin>>temp.ad;
 cout<<"Enter the month of anniversary(1-12): ";
 cin>>temp.am; 
  //Checks to see if the inputed dates are within bounds
 if((temp.ad<1||temp.ad>31)||(temp.am<1||temp.am>12))
 {
 printf("Invalid anniversary date. Valid inputs are date 1-31, month 1-12 and year>1900.\n");
 } //Loops through the process if the inputed dates are out of bounds 
 }while((temp.ad<1||temp.ad>31)||(temp.am<1||temp.am>12));
 
 //Prompts the user to respond to a condition
 cout<<"Do you want to enter the anniversary year?(Enter y/n): ";
 cin>>c;
  //checks the user prompt for a yes response
 if(c=='y'||c=='Y')
 {
 	//Loops through the input process until a valid Anniversary year is inputed
 do
 {
 	
 cout<<"Enter the anniversary year: ";
 cin>>temp.ay;
//checks to see if the year is within bounds
 if(temp.ay<1900)
 {
 cout<<"Invalid year. Valid range is greater than 1900.";
 }
  //checks to see if the year is within bounds and if it is not then loop through the process again 
 }while(temp.ay<1900);
 }
 //If the user selects no then set the year value to negative
 else
 {
 temp.ay = -1;
 }
 }

