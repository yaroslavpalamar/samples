#include <string>
#include <iostream>

using namespace std;

// Сімейство елементів
// Базовий клас для всіх іграшок
class Toy
{
protected:
    string name;
public:
    Toy(string name)
    {
        this->name = name;
    }
};
// Конкретні реалізації
struct WoodenCat : public Toy
{
    WoodenCat() : Toy("Wooden Cat") { cout << this->name << '\n'; }
};
struct TeddyCat : public Toy
{
    TeddyCat() : Toy("Teddy Cat") { cout << this->name << '\n'; }
};
struct WoodenBear : public Toy
{
    WoodenBear() : Toy("Wooden Bear") { cout << this->name << '\n'; }
};
struct TeddyBear : public Toy
{
    TeddyBear() : Toy("Teddy Bear") { cout << this->name << '\n'; }
};
// Абстрактна Фабрика (Abstract Factory)
struct IToyFactory
{
    virtual Toy * GetBear() = 0;
    virtual Toy * GetCat() = 0;
};
// конкретна фабрика (concrete factory)
struct TeddyToysFactory : IToyFactory
{
    virtual Toy * GetBear()
    {
        return new TeddyBear();
    }
    virtual Toy * GetCat()
    {
        return new TeddyCat();
    }
};
// і ще одна конкретна фабрика
struct WoodenToysFactory : IToyFactory
{
    virtual Toy * GetBear()
    {
        return new WoodenBear();
    }
    virtual Toy * GetCat()
    {
        return new WoodenCat();
    }
};
// Client
void create(IToyFactory * toyFactory)
{
    Toy * bear = toyFactory->GetBear();
    Toy * cat = toyFactory->GetCat();
}

int main()
{
	WoodenToysFactory* wtf = new WoodenToysFactory();
	TeddyToysFactory* ttf = new TeddyToysFactory();
	// Спочатку створимо «дерев'яну» фабрику
	create(wtf);
	delete wtf;
	// А тепер створимо «плюшеву» фабрику,
	create(ttf);
	delete ttf;
}

