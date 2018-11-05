#include <iostream>
#include <string>

using namespace std;

/* Abstract base class */
// The abstract Coffee class defines the functionality of Coffee implemented by decorator
struct Coffee {
	virtual double getCost() = 0; // Returns the cost of the coffee
	virtual std::string getIngredients() = 0; // Returns the ingredients of the coffee
	virtual ~Coffee() = 0;
};
inline Coffee::~Coffee() { }
 
/* SimpleCoffee class. */
// Extension of a simple coffee without any extra ingredients
struct SimpleCoffee : public Coffee {
	virtual double getCost() {
		return 1.0;
	}
 
	virtual std::string getIngredients() {
		return "Coffee";
	}
};
 
/* Decorators */
// Decorator Milk that adds milk to coffee.
struct MilkDecorator : Coffee {
	MilkDecorator (Coffee *basicCoffee) : basicCoffee(basicCoffee) {}
 
	virtual double getCost() { // Providing methods defined in the abstract superclass
		return basicCoffee->getCost() + 0.5;
	}

  	virtual std::string getIngredients() {
		return basicCoffee->getIngredients() + ", " + "Milk";
	}
private:
	Coffee *basicCoffee;
};
 
// Decorator Whip that adds whip to coffee
struct WhipDecorator : Coffee {
	WhipDecorator (Coffee *basicCoffee) : basicCoffee(basicCoffee) {}
 
	virtual double getCost() {
		return basicCoffee->getCost() + 0.7;
	}

 	virtual std::string getIngredients() {
		return basicCoffee->getIngredients() + ", " + "Whip";
	}
private:
	Coffee *basicCoffee;
};


int main()
{
	SimpleCoffee s;
	std::cout << "Cost: " << s.getCost() << "; Ingredients: " << s.getIngredients() << std::endl;
 
	MilkDecorator m(&s);
	std::cout << "Cost: " << m.getCost() << "; Ingredients: " << m.getIngredients() << std::endl;
 
	WhipDecorator w(&s);
	std::cout << "Cost: " << w.getCost() << "; Ingredients: " << w.getIngredients() << std::endl;
 
	// Note that you can stack decorators:
	MilkDecorator m2(&w);
	std::cout << "Cost: " << m2.getCost() << "; Ingredients: " << m2.getIngredients() << std::endl;
   
	return 0;
}

