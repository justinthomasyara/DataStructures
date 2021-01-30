//////i worked on this project and collaberated with my tutor david

#include <iostream>
#include <string>
#include "hotel.hpp"

using namespace std;

void displayMenu()
{
    cout << " |===========Main Menu==========|" << endl;
    cout << " |1.         Check In           |" << endl;
    cout << " |2.         Check Out          |" << endl;
    cout << " |3.         Add Guest          |" << endl;
    cout << " |4.     Print Check In List    |" << endl;
    cout << " |5.     Print Check Out List   |" << endl;
    cout << " |6.     Print Amenity List     |" << endl;
    cout << " |7.   Print Guest Information  |" << endl;
    cout << " |8.   Change Account Balance   |" << endl;
    cout << " |9.  Delete Guest From Network |" << endl;
    cout << " |10.    Add Example Guests     |" << endl;
    cout << " |11.          Quit             |" << endl;
    cout << " |==============================|" << endl;
    cout << "   What would you like to do?" << endl;
    cout << "Please enter a number from 1 to 10: " << endl;
}

int main(){
  Hotel h;
  displayMenu();
  string input;
  string last;
  string first;
  float bal;
  bool finished = false;
  getline(cin, input);
  while (!finished){
    bool satisfied = false;
    if (input == "1"){
      cout << "Guest Check In" << endl << "Please enter guest's last name: " << endl;
      getline(cin, last);
      cout << "Please enter guest's first name: " << endl;
      getline(cin, first);
      h.checkIn(last, first);

      displayMenu();
      getline(cin, input);
    }

    if (input == "2"){
      cout << "Guest Check Out" << endl << "Please enter guest's last name: " << endl;
      getline(cin, last);
      cout << "Please enter guest's first name: " << endl;
      getline(cin, first);
      h.checkOut(last, first);

      displayMenu();
      getline(cin, input);
    }

    if (input == "3"){
      string in;
      string out;
      string nights;
      string rate;
      string am;
      string ex;
      string notes;
      bool exec = false;
      cout << "Adding Guest to Network" << endl << "Please enter guest's last name: " << endl;
      getline(cin, last);
      cout << "Please enter guest's first name: " << endl;
      getline(cin, first);
      cout << "Please enter guest's check-in date (MMDDYYYY): " << endl;
      getline(cin, in);
      cout << "Please enter guest's check-out date (MMDDYYYY): " << endl;
      getline(cin, out);
      while (!satisfied){
        cout << "Is the guest an executive member? (Y/N)" << endl;
        getline(cin, ex);
        if (ex == "Y" || ex == "y"){
          exec = true;
          satisfied = true;
        }
        else if (ex == "N" || ex == "n"){
          exec = false;
          satisfied = true;
        }
        else
          cout << "Invalid entry. Please enter either (Y/N)" << endl;
      }
      cout << "Please enter number of nights guest will be staying: " << endl;
      getline (cin, nights);
      cout << "Please enter nightly rate: " << endl;
      getline (cin, rate);
      float n = stof(nights);
      float r = stof(rate);
      bal = n * r;
      cout << "      What amentiy will the guest be receiving during their stay?" << endl;
      cout << "(If the guest does not have an amenity delivery scheduled enter: 'none')" << endl;
      getline (cin, am);
      cout << "Please enter any notes the guest would like the staff to be aware of (allergies, preferences, etc...): " << endl;
      getline (cin, notes);
      h.addGuest(last, first, bal, in, out, exec, am, notes);

      displayMenu();
      getline(cin, input);
    }

    if (input == "4"){
      string in;
      cout << "Please enter date for check-in list (MMDDYYYY): " << endl;
      getline(cin, in);
      cout << "Guests who are checking in on " << in << " are as follows: " << endl;
      h.printCheckInList(in);

      displayMenu();
      getline(cin, input);
    }
    if (input == "5"){
      string out;
      cout << "Please enter date for check-out list (MMDDYYYY): " << endl;
      getline(cin, out);
      cout << "Guests who are checking out on " << out << " are as follows: " << endl;
      h.printCheckOutList(out);

      displayMenu();
      getline(cin, input);
    }

    if (input == "6"){
      string amen;
      cout << "Please enter today's date (MMDDYYYY): " << endl;
      getline(cin, amen);
      cout << "Guests who are receiving an amenity on " << amen << " are as follows: " << endl;
      h.printAmenityList(amen);

      displayMenu();
      getline(cin, input);
    }

    if (input == "7"){
      cout << "Guest Notes" << endl << "Please enter guest's last name: " << endl;
      getline(cin, last);
      cout << "Please enter guest's first name: " << endl;
      getline(cin, first);
      h.printGuestInfo(last, first);

      displayMenu();
      getline(cin, input);
    }


    if (input == "8"){
      cout << "Please enter guest's last name: " << endl;
      getline(cin, last);
      cout << "Please enter guest's first name: " << endl;
      getline(cin, first);
      string balance;
      string mon;
      float money;
      cout << "Will there be a charge to the account or a credit?" << endl;
      cout << " (Please enter '+' for charge or '-' for credit)" << endl;
      getline(cin, balance);
      cout << "Please enter the amount that will be charged or credited: " << endl;
      getline(cin, mon);
      money = stof(mon);
      if (balance == "+"){
        h.changeAccountBalance(last, first, money);

        displayMenu();
        getline(cin, input);
      }
      else if(balance == "-"){
        money = -money;
        h.changeAccountBalance(last, first, money);

        displayMenu();
        getline(cin, input);
      }
      else{
        cout << "Incorrect entry." << endl;
      }
    }

    if (input == "9"){
      string prompt;
      cout << "Removing a guest will completely delete their record in the hotel. " << endl;
      cout << "If you would like to check a guest out, please select 'N' on the... "<< endl;
      cout << "...following prompt and select the check out option from the main menu." << endl;
      while (!satisfied){
        cout << "Are you sure you would like to remove this guest? (Y/N)" << endl;
        getline(cin, prompt);
        if (prompt == "Y" || prompt == "y"){
          satisfied = true;
          cout << "Please enter guest's last name: " << endl;
          getline(cin, last);
          cout << "Please enter guest's first name: " << endl;
          getline(cin, first);
          h.removeGuest(last, first);
        }
        else if (prompt == "N" || prompt == "n"){
          satisfied = true;
        }
        else
          cout << "Invalid entry. Please enter either (Y/N)" << endl;
      }

      displayMenu();
      getline(cin, input);
    }

    if (input == "10"){
      string in1 = "12052019";
      string in2 = "12242019";
      string out1 = "12262019";
      string out2 = "12272019";
      h.addGuest("Yara", "Justin", 500, in1, out2, false, "beer basket", "none");
      h.addGuest("Kenobi", "Ben", 600, in2, out1, true, "light saber batteries", "severe peanut allergy");
      h.addGuest("Rogers", "Steve", 5000, in1, out1, true, "shield waxing kit", "none");
      h.addGuest("Jones", "Indiana", 584, in2, out2, true, "gluten free gift basket", "gluten allergy");
      h.addGuest("Man", "Spider", 10, in1, out2, true, "none", "not a real spider");
      cout << "                                      Example Guests Added. "<< endl;
      cout << "         Check-in dates are either 1252019 or 12242019 to use with other functions." << endl;
      cout << "        Check-out dates are either 1252019 or 12242019 to use with other functions." << endl;
      cout << "Names for the guests are: Yara, Justin...Kenobi, Ben...Rogers, Steve...Jones, Indiana... Man, Spider" << endl;

      displayMenu();
      getline(cin, input);
    }

    if (input == "11"){
      finished = true;
      cout << "Goodbye." << endl;
    }

    if (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8" && input != "9" && input != "10" && input != "11"){
      cout << "Incorrect input.  Please enter a value between 1 and 10." << endl;
      getline(cin, input);
    }
  }
}
