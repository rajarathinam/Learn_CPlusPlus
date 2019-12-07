#include "stub.h"

class Observer {

public:

    /**
     * Update the state of this observer
     * @param temp new temperaure
     * @param humidity new humidity
     * @param pressure new pressure
     */
    virtual void update(float temp, float humidity, float pressure) = 0;

};

class Subject {

public:

    /**
     * Register an observer
     * @param observer the observer object to be registered
     */
    virtual void registerObserver(Observer *observer) = 0;

    /**
     * Unregister an observer
     * @param observer the observer object to be unregistered
     */
    virtual void removeObserver(Observer *observer) = 0;

    /**
     * Notify all the registered observers when a change happens
     */
    virtual void notifyObservers() = 0;

};

class WeatherData : public Subject {
    std::vector<Observer *> observers; // observers

    float temp = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;

public:

    void registerObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notifyObservers() override;

    /**
     * Set the new state of the weather station
     * @param temp new temperature
     * @param humidity new humidity
     * @param pressure new pressure
     */
    void setState(float temp, float humidity, float pressure);

};



class Client : public Observer {

    int id;

public:

    Client(int id);

    virtual void update(float temp, float humidity, float pressure) override;

};

void Client::update(float temp, float humidity, float pressure) {
    // print the changed values
    std::cout << "---Client (" << id << ") Data---\tTemperature: " << temp
              << "\tHumidity: " << humidity
              << "\tPressure: " << pressure
              << std::endl;
}

Client::Client(int id) {
    this->id = id;
}

void WeatherData::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void WeatherData::removeObserver(Observer *observer) {
    // find the observer
    auto iterator = std::find(observers.begin(), observers.end(), observer);

    if (iterator != observers.end()) { // observer found
        observers.erase(iterator); // remove the observer
    }
}

void WeatherData::notifyObservers() {
    for (Observer *observer : observers) { // notify all observers
        observer->update(temp, humidity, pressure);
    }
}

void WeatherData::setState(float temp, float humidity, float pressure) {
    this->temp = temp;
    this->humidity = humidity;
    this->pressure = pressure;
    std::cout << std::endl;
    notifyObservers();
}

 class AA
 {
 public:
     AA() { std::cout << "A";}
 };
 class BB:virtual public AA
 {
 public:
     BB() { std::cout << "B";}

 };
 class CC:virtual public AA
 {
 public:
     CC() { std::cout << "C";}

 };
 class DD:public BB, public CC
 {
 public:
     DD() { std::cout << "D";}

 };

int shuwhs() {
     DD d;
    WeatherData weatherStation;
    Client one(1), two(2), three(3);

    float temp, humidity, pressure;

    weatherStation.registerObserver(&one);
    weatherStation.registerObserver(&two);
    weatherStation.registerObserver(&three);

   // std::cout << "Enter Temperature, Humidity, Pressure (seperated by spaces) << ";
   // std::cin >> temp >> humidity >> pressure;

    weatherStation.setState(10,20,30);

    weatherStation.removeObserver(&two);

    std::cout << "\n\nEnter Temperature, Humidity, Pressure (seperated by spaces) << ";
    std::cin >> temp >> humidity >> pressure;

    weatherStation.setState(temp,humidity,pressure);

    return 0;
}
