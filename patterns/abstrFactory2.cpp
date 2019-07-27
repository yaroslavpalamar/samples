#include <iostream>
#include <memory>
#include <random>

class Widget 
{
public:
	Widget() = default;
	virtual ~Widget() = default;

	virtual int doStuff() = 0;

};

class WidgetFactory
{
public:
	using WidgetPtr = std::unique_ptr<Widget>;
	WidgetFactory() = default;
	virtual ~WidgetFactory() = default;
	
	virtual WidgetPtr createWidget() const = 0;
	//virtual Widget* createWidget() const = 0;
};

class Gadget final
{
public:
	explicit Gadget(const WidgetFactory &factory) 
		: mFactory{factory}
	{
	}
	~Gadget() = default;
	
	int doStuffOnWidgets() const
	{
		auto result = 0;
		for  (auto i=0; i < 3; ++i) {
			const auto widget = mFactory.createWidget();
			result += widget->doStuff();
		}
		return result;
	}
private:
	const WidgetFactory &mFactory;
};

class ConcreteWidget final
	: public Widget
{
public:
	ConcreteWidget() = default;
	virtual ~ConcreteWidget() = default;

	virtual int doStuff() override {
		std::random_device rd;
		std::uniform_int_distribution<> dist;
		return dist(rd);
	}
};

class ConcreteWidgetFactory final
	: public WidgetFactory
{
public:
	ConcreteWidgetFactory() = default;
	virtual ~ConcreteWidgetFactory() = default;

	virtual WidgetPtr createWidget() const override {
	//virtual Widget* createWidget() const override {

		return std::make_unique<ConcreteWidget>();
		//return new ConcreteWidget();
	}
};

class TestWidget final
	: public Widget
{
public:
	TestWidget() = default;
	virtual ~TestWidget() = default;

	virtual int doStuff() override {
		return 0;
	}
};

class TestWidgetFactory final
	: public WidgetFactory
{
public:
	TestWidgetFactory() = default;
	virtual ~TestWidgetFactory() = default;

	virtual WidgetPtr createWidget() const override {
	//virtual Widget* createWidget() const override {
		return std::make_unique<TestWidget>();
		//return new TestWidget();
	}
};


int 
main()
{
	//TestWidgetFactory factory;
	ConcreteWidgetFactory factory;
	Gadget g(factory);  // we can use TestWidgetFactory or ConcreteWidgetFactory and nothing in Gadget changed
	std::cout << g.doStuffOnWidgets() << "\n";
	return 0;
}

