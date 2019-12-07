#include "stub.h"
class Pizza {
public:
	Pizza(){
	}
	virtual ~Pizza()
	{
	}
	virtual double getCost() = 0;
};
class RegularPizza :public Pizza {
private:
	double m_cost;
public:
	RegularPizza() {this->m_cost = 25;}
	~RegularPizza() {};
	double getCost() {return this->m_cost;}
};
class PizzaDecorator :public Pizza{
private:
	Pizza *m_wrappee;
protected:
	PizzaDecorator() {};
	PizzaDecorator(Pizza *inner) {this->m_wrappee = inner;}
public:

	~PizzaDecorator() {delete this->m_wrappee;};
	double getCost() {return this->m_wrappee->getCost();}
};
class Mozzarella : public PizzaDecorator{

private:
	double m_cost;

public:
	Mozzarella(Pizza * core) : PizzaDecorator(core) { this->m_cost = 5;}
	Mozzarella(){ }
	~Mozzarella(){ }
	double getCost() { return (PizzaDecorator::getCost() + m_cost);}
};

int deefede()
{


Pizza *regularPizza = new RegularPizza();
Pizza *pizzaWithMozzarella = new Mozzarella (regularPizza);
cout<<pizzaWithMozzarella->getCost();
	return 0;
}

