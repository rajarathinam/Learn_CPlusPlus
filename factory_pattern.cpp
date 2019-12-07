#include<iostream>
#include<map>
using namespace std;

#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include<algorithm>
#include<vector>
#include <cstring>
using namespace std;

class Aircraft
{
public:
	virtual void name() = 0;
};
class Boeing:public Aircraft
{
public:
	void name()
	{
		cout<<"Boeing\n";
	}
};
class Gulfstream:public Aircraft
{
public:
	void name()
	{
		cout<<"Gulfstream\n";
	}
};

class Embraer:public Aircraft
{
public:
	void name()
	{
		cout<<"Embraer\n";
	}
};
class AircraftFactory
{
public:
	virtual Aircraft* manufactureAircraft(char*) = 0;
};
class Factory:public AircraftFactory
{
public:
Aircraft* manufactureAircraft(char* aircraft_name)
{
	if(strcmp(aircraft_name,"Boeing") == 0 )		
	{
		return new Boeing();
	}

   else if(strcmp(aircraft_name,"Gulfstream") == 0 )		
	{
		return new Gulfstream();
	}
	else if(strcmp(aircraft_name,"Embraer") == 0 )		
	{
		return new Embraer();
	}
	else
	{
		return NULL;
	}
     
}
};

int frgrv()
{
	AircraftFactory* ptr_AircraftFactory = new Factory();
	Aircraft* ptr_Aircraft;
	ptr_Aircraft = ptr_AircraftFactory->manufactureAircraft("Boeing");
	ptr_Aircraft->name();
		ptr_Aircraft = ptr_AircraftFactory->manufactureAircraft("Gulfstream");
	ptr_Aircraft->name();
		ptr_Aircraft = ptr_AircraftFactory->manufactureAircraft("Embraer");
	ptr_Aircraft->name();
	return 0;
}


