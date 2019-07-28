#include <iostream>
#include <memory>
#include <vector>

using Values = std::vector<double>;

class GraphDrawer
{
public:
	virtual void drawGraph(const Values &valuse) const = 0;
};

class LinearGraphDrawer final
 : public GraphDrawer
{
	virtual void drawGraph(const Values &valuse) const override {
	}
};


class BarGraphDrawer final
 : public GraphDrawer
{
	virtual void drawGraph(const Values &valuse) const override {
	}
};


class Report
{
public:
	using Values = std::vector<double>;
	
	explicit Report(Values values) 
		: mValues {std::move(values)}
	{
	}

	void drawGraph(const GraphDrawer &drawer)
	{
		drawer.drawGraph(mValues);
	}

private:
	Values mValues;
};

int
main()
{
	Report report{{1,2,3}};
	report.drawGraph(LinearGraphDrawer{});
	return 0;
}
