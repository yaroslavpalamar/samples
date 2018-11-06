#include <iostream>
#include <string>

using namespace std;

/* Abstract base class */
// The abstract Coffee class defines the functionality of Coffee implemented by decorator
struct Coffee {
	virtual double getCost() = 0; // Returns the cost of the coffee
	virtual string getIngredients() = 0; // Returns the ingredients of the coffee
	virtual ~Coffee() = 0;
};
inline Coffee::~Coffee() { }
 
/* SimpleCoffee class. */
// Extension of a simple coffee without any extra ingredients
struct SimpleCoffee : public Coffee {
	virtual double getCost() override {
		return 1.0;
	}
 
	virtual std::string getIngredients() override {
		return "Coffee";
	}
};
 
/* Decorators */
// Decorator Milk that adds milk to coffee.
struct MilkDecorator : Coffee {
	explicit MilkDecorator (Coffee *basicCoffee) : basicCoffee(basicCoffee) {}
 
	virtual double getCost() override { // Providing methods defined in the abstract superclass
		return basicCoffee->getCost() + 0.5;
	}

  	virtual std::string getIngredients() override {
		return basicCoffee->getIngredients() + ", " + "Milk";
	}
private:
	Coffee *basicCoffee;
};
 
// Decorator Whip that adds whip to coffee
struct WhipDecorator : Coffee {
	explicit WhipDecorator (Coffee *basicCoffee) : basicCoffee(basicCoffee) {}
 
	virtual double getCost() override {
		return basicCoffee->getCost() + 0.7;
	}

 	virtual std::string getIngredients() override {
		return basicCoffee->getIngredients() + ", " + "Whip";
	}
private:
	Coffee *basicCoffee;
};


int main()
{
	SimpleCoffee s;
	cout << "Cost: " << s.getCost() << "; Ingredients: " << s.getIngredients() << endl;
 
	// decorate simple with milk:
	MilkDecorator m(&s);
	cout << "Cost: " << m.getCost() << "; Ingredients: " << m.getIngredients() << endl;
 
	// decorate simple with whip:
	WhipDecorator w(&s);
	cout << "Cost: " << w.getCost() << "; Ingredients: " << w.getIngredients() << endl;
 
	// Note that you can stack decorators
	// (for example you pass whip object instead of simple):
	MilkDecorator milkAndWhip(&w);
	cout << "Cost: " << milkAndWhip.getCost() << "; Ingredients: " << milkAndWhip.getIngredients() << endl;
   
	return 0;
}

