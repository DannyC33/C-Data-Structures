 
 // Problem Chapter 3.5 Part B
 
 void UnsortedType::DeleteItem(ItemType item)
{
  NodeType* location;
  NodeType* tempLocation;

  location = listData;

  if (item.ComparedTo(listData->info) == EQUAL)
  {
    tempLocation = location;
    listData = listData->next;
  }
  else
  {
    while (!((item.ComparedTo((location->next)->info) == EQUAL)))
      location = location->next;

    tempLocation = location->next;
    location->next = (location->next)->next;
  }

  delete tempLocation;
  length--;
}




// Problem Chapter 3.6 part D
void UnsortedType::DeleteItem(ItemType item)
{
    NodeType* location;
  NodeType* tempLocation;

  location = listData;


  
  if (item.ComparedTo(location->info) == EQUAL)
  {
    tempLocation = location;
    listData = listData->next;
    
      delete tempLocation;
       length--;
  }
  else{
  	
  	
  	
  }
  
  
  
  
 while(location-> next != NULL){
  	
  	
	  if (item.ComparedTo((location->next)-> info) == EQUAL){
	  	
	  
    tempLocation = location->next;
    	location= (location->next) -> next;
 
    
       delete tempLocation;
       length--;
       
       
     }
     location = location -> next;
  
    
    
    }
  


}

