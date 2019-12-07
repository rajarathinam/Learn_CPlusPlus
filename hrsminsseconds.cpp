#include "stub.h"

#define SECS_PER_HOUR 3600
#define SECS_PER_MIN 60

class MyClock
{
public:
    explicit MyClock(int sec);
    MyClock(const MyClock& );
    MyClock& operator=(const MyClock&);
    ~MyClock();

    friend ostream& operator<<(ostream& out, MyClock&);
private:
    int seconds;
    int hours;
    int minutes;

};
ostream& operator<<(ostream& out, MyClock& rhs)
{
    out << "\nHours:" << rhs.hours <<"\nMinutes: " << rhs.minutes << "\nSeconds: " << rhs.seconds;
    return out;
}

MyClock::MyClock(int sec)
{

    this->hours = sec / SECS_PER_HOUR;
    this->minutes = sec/SECS_PER_MIN;
    this->minutes = this->minutes % SECS_PER_MIN;
    this->seconds = sec%SECS_PER_MIN;


}

MyClock::MyClock(const MyClock &rhs)
{
    this->hours = rhs.hours;
    this->minutes = rhs.minutes;
    this->seconds = rhs.seconds;

}

MyClock &MyClock::operator=(const MyClock &rhs)
{
    if( this != &rhs)
    {
        this->hours = rhs.hours;
        this->minutes = rhs.minutes;
        this->seconds = rhs.seconds;
    }
    return *this;

}
MyClock::~MyClock(){}

int wdjiej3o()
{

  MyClock time(3652);
  cout << time;



    cout << endl;
    return 0;
}
