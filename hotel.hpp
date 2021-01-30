//////i worked on this project and collaberated with my tutor david


#include <iostream>
#include <string>

struct Guest
{
  std::string lastName;
  std::string firstName;
  std::string checkInDate;
  std::string checkOutDate;
  float balance;
  bool exec;
  bool checkedIn = false;
  std::string amenity;
  std::string notes;
  struct Guest* next;

  Guest(){}

  Guest(std::string l, std::string f, float b, bool e, bool c, std::string a, std::string n)
  : lastName(l), firstName(f), balance(b), exec(e), checkedIn(c), amenity(a), notes(n), next(NULL) {}

};


struct Name
{
    Guest *head = NULL;
};

class Hotel {
    private:
        //Guest* head;
        Name* Table;
    public:
        Hotel();
        bool isEmpty(int index);
        void addGuest(std::string lastName, std::string firstName, float balance, std::string checkInDate, std::string checkOutData, bool exec, std::string amenity, std::string notes);
        Guest* searchNetwork(std::string lastName, std::string firstName);
        void checkIn(std::string lastName, std::string firstName);
        void checkOut(std::string lastName, std::string firstName);
        void printCheckInList(std::string date);
        void printCheckOutList(std::string date);
        void printAmenityList(std::string date);
        void printGuestInfo(std::string lastName, std::string firstName);
        void removeGuest(std::string lastName, std::string firstName);
        void changeAccountBalance(std::string lastName, std::string firstName, float transaction);

};
