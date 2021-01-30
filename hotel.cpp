//////i worked on this project and collaberated with my tutor david

#include "hotel.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


Hotel::Hotel()
{
  Table = new Name[26]; //hash table ... 26 spots.. one for each letter of alphabet
  //head = nullptr;
}


bool Hotel::isEmpty(int index)
{
  if(Table[index].head == nullptr){ //checks if empty , indecies are used in this data structure so we check the index of head
    return true;
  }
  else
    return false;
}

//hash table , made with 26 spots, one for each letter of the alphabet with linked lists attached to each of them to have
//all of the guests in alphabetical order. 
//main guest struct's information consists of guest's name, account balance, check in/out dates, ... 
//functions can manipulate information, change the hierarchy, delete, ect


void Hotel::addGuest(string lastName, string firstName, float balance, string checkInDate, string checkOutDate, bool exec, string amenity, string notes)
{
  char letter = lastName.at(0); // takes first letter of last name //ascii table
  int index = int(letter) - 65; // subtract 65 to put A at spot 0
  Guest *temp = new Guest;
  temp->lastName = lastName; //creating new struct , head of thelinked list
  temp->firstName = firstName;
  temp->checkInDate = checkInDate;
  temp->checkOutDate = checkOutDate;
  temp->balance = balance;
  temp->exec = exec;
  temp->amenity = amenity;
  temp->notes = notes;
  if(Table[index].head == NULL){

    Table[index].head = temp; //if th start is null(empty) CREATEing a new spot 
    temp->next = nullptr;

  }
  else{

    Guest *tracer = Table[index].head; //tracer special key word, keeping track of where we are in the hash table 
    Guest *prev = tracer; //alphabetizing , seeing if last name is bigger than previous
    if (tracer->next != nullptr && lastName.compare(tracer->lastName) > 0){
      tracer = tracer->next; //these two are first check on the table, and once we get the first check we assign tracer and prev variables
    }
    else{
      temp->next = Table[index].head;//once it has variables it can iterate through the table 
      Table[index].head = temp;
      return;
    }
    while (tracer != nullptr && lastName.compare(tracer->lastName) > 0){ //where it iterates as many times as it needs to 
      tracer = tracer->next;
      prev = prev->next;
    }
    temp = prev->next;
    temp->next = tracer;
    return;
  }
}


Guest* Hotel::searchNetwork(string lastName, string firstName)//
{
  char letter = lastName.at(0);//takes the letter by itself 
  int index = int(letter) - 65;//finding first letter 
  Guest *returnName = nullptr;
  Guest *temp = Table[index].head;

  bool found = false;

  while(!found && temp != nullptr){
    if (temp->lastName == lastName && temp->firstName == firstName){
      found = true;
      returnName = temp;
    }
    else{
      temp = temp->next;
    }
  }
  return returnName;
}


void Hotel::checkIn(string lastName, string firstName)//using search network function
{
  if(searchNetwork(lastName, firstName) == nullptr){//search for the guest in the network
    //once it finds th guest it changes the boolean value to true instead of false 
    cout << "Guest not found" << endl;
    return;
  }
  else{
    Guest *temp = searchNetwork(lastName, firstName);
    temp->checkedIn = true;
    if (temp->exec == true)
      cout << "Please welcome our EXECUTIVE member." << endl;
    else
      cout << "Guest has been checked in." << endl;
    if (temp->amenity != "none"){
      cout << "Guest will receive amenity: " << temp->amenity << endl;
      cout << "Please mark 'yes' under the checked-in section of the amenity sheet." << endl;
    }
  }
}

void Hotel::checkOut(string lastName, string firstName) //same, looks for guest, shows different descriptions of the struct, like balance 
{
  if(searchNetwork(lastName, firstName) == nullptr){
    cout << "Guest not found" << endl;
    return;
  }
  else{
    Guest *temp = searchNetwork(lastName, firstName);
    temp->checkedIn = false;
    cout << "Guest has been checked-out." << endl;
    cout << "Balance on the account: $" << temp->balance << endl;
    cout << "Would you like to settle account?" << endl << "(Y/N): ";
    string answer;
    getline(cin, answer);
    if (answer == "Y"){
      temp->balance = 0.00;
      cout << "Account has been settled." << endl;
    }
  }
}

void Hotel::printCheckInList(string date) //goes through the for loop, 26 times for each letter of the the alph, and goes through each part 
{
  for (int i = 0; i < 26; i++){
    Guest *temp = Table[i].head;
    while (temp != nullptr){
      if(temp->checkInDate == date){
        cout << temp->lastName << ", " << temp->firstName << " ... " << "Notes: " << temp->notes << endl;
      }
      temp = temp->next;
    }
  }
}

void Hotel::printCheckOutList(string date)//same thing, prints different items 
{
  for (int i = 0; i < 26; i++){
    Guest *temp = Table[i].head;
    while (temp != nullptr){
      if(temp->checkOutDate == date){
        cout << temp->lastName << ", " << temp->firstName << " ... " << "Notes: " << temp->notes << endl;
      }
      temp = temp->next;
    }
  }
}

void Hotel::printAmenityList(string date)
{
  for (int i = 0; i < 26; i++){
    Guest *temp = Table[i].head;
    while (temp != nullptr){
      if(temp->amenity != "none" && temp->checkInDate == date){
        cout << temp->lastName << ", " << temp->firstName << " ... " << "Amenity: " << temp->amenity << " .... Checked-in (Y/N):________" << endl;
      }
      temp = temp->next;
    }
  }
}

void Hotel::printGuestInfo(string lastName, string firstName)
{
  if(searchNetwork(lastName, firstName) == nullptr){
    cout << "Guest not found" << endl;
    return;
  }
  else{
    Guest *temp = searchNetwork(lastName, firstName);
      cout << temp->lastName << ", " << temp->firstName << endl;
      cout << "Check-in date: " << temp->checkInDate << " Check-out date: " << temp->checkOutDate << endl;
      cout << "Guest balance: " << temp->balance << endl;
      if (temp->exec != false)
        cout << "Guest is an executive member." << endl;
      else
        cout << "Guest is not an executive member." << endl;
      if (temp->checkedIn != false)
        cout << "Guest is checked-in. " << endl;
      else
        cout << "Guest is not checked-in. " << endl;
      cout << "Amenity: " << temp->amenity << endl;
      cout << "Notes: " << temp->notes << endl;
  }
}

void Hotel::removeGuest(string lastName, string firstName) //delete someone from network
{
  if(searchNetwork(lastName, firstName) == nullptr){
    cout << "Guest not found" << endl;
    return;
  }
  else{
    Guest *temp = searchNetwork(lastName, firstName);
    char letter = lastName.at(0);
    int index = int(letter) - 65;
    // redo this
    Guest *prev = Table[index].head;
    if (prev->next != nullptr && prev->next->lastName != temp->lastName && prev->next->firstName != temp->firstName){
      prev = prev->next;
    }
    while (prev->next != nullptr && prev->next->lastName != temp->lastName && prev->next->firstName != temp->firstName){
      prev = prev->next;
    }
    prev->next = temp->next;
    delete temp;
  }
}
void Hotel::changeAccountBalance(string lastName, string firstName, float transaction)
{
  if(searchNetwork(lastName, firstName) == nullptr){
    cout << "Guest not found" << endl;
    return;
  }
  else{
    Guest *temp = searchNetwork(lastName, firstName);
    temp->balance = temp->balance + transaction;
  }
}
