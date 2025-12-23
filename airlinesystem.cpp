#include<iostream>
#include<vector>
using namespace std;
class Flight
{
private:
string flightNo, departure,destination;
int capacity,reserved;
public:
Flight(string fno,string dep,string des,int cap){
    flightNo=fno;
    departure=dep;
    destination=des;
    capacity=cap;
    reserved=0;
}
bool reserveSeat()
{
if(reserved<capacity)
{
reserved++;
return true;
}
return false;
}
int availableSeats()
{
return capacity-reserved;
}
friend class ReservationSystem;
};

class ReservationSystem{
vector<Flight>flights;
public:
void add(string fno,string dep,string des,int cap)
{
    flights.push_back(Flight(fno,dep,des,cap));
}
void showFlights()
{
if(flights.empty())
{
    cout<<"No Flights Available\n";
    return;
}
cout<<"\n Available Flights\n";
for(int i=0;i<flights.size();i++)
{
    cout<<"Flight No:\t"<<flights[i].flightNo<<endl;
    cout<<"From:\t"<<flights[i].departure<<endl;
    cout<<"To:\t"<<flights[i].destination<<endl;
    cout<<"AvailableSeats:\t"<<flights[i].availableSeats()<<endl;
    cout<<"--------------\n";
}
}

void reserve_seat()
{
string fn;
cout<<"Enter Flight No:";
cin>>fn;

for(int i=0;i<flights.size();i++)
{
if(fn==flights[i].flightNo)
{
if(flights[i].reserveSeat())
cout<<"You have reserved seat on Flight"<<flights[i].flightNo<<endl;
else
cout<<"Sorry! No seats available\n"<<endl;
return;
}
}
cout<<"Invalid Flight Number!\n";
}

void adminAddFlight()
{
string fno,dep,des;
int cap;
    cout<<"Enter Flight No";
    cin>>fno;
    cout<<"Enter Departure";
    cin>>dep;
    cout<<"Enter Destination";
    cin>>des;
    cout<<"Enter Capacity";
    cin>>cap;
add(fno,dep,des,cap);
cout<<"Flight added successfully!\n";
}
void menu()
{
int choice;
do
{
    cout<<"\n --- AIRLINE RESERVATION SYSTEM---\n";
    cout<<"1.View Flights\n";
    cout<<"2.Reserve Flights\n";
    cout<<"3.Admin-Add Flights\n";
    cout<<"4.Exit\n";
    cout<<"Enter choice";
    cin>>choice;
switch(choice)
{
case 1:
showFlights();
break;
case 2:
    cin.ignore();
reserve_seat();
break;
case 3:
adminAddFlight();
break;
case 4:
cout<<"Thank you for using the system!\n";
break;
default:
cout<<"Invalid choice!Try again!\n";
}
}while (choice!=4);
}
};

int main()
{
ReservationSystem rs;
rs.add("F101","UAE","USA",100);
rs.add("F102","India","USA",100);
rs.menu();
return 0;
}
