#include <string>
#include <memory>
#include <vector>

class Engine
{
public:
	explicit Engine(int power)
		: mPower{power}
	{

	}
private:
	int mPower = 0;
};

class Wheel
{

};

class StandardWheel
	: public Wheel
{

};

class HeavyDutyWheel
	: public Wheel
{

};

class Car {
public:
	enum class Type {
		Family,
		Truck,
		Sport
	};

	using EnginePtr = std::unique_ptr<Engine>;
	using WheelPtr = std::unique_ptr<Wheel>;
	using Wheels = std::vector<WheelPtr>;

        class Builder final
        {
        public:
                using CarPtr = std::unique_ptr<Car>;
                CarPtr create() const {
                	Type type;
                	if (mPower > 500)
                		type = (mWheelCount > 4) ? (Type::Truck) : (Type::Sport);
                	else
                		type = Type::Family;

                	Wheels wheels;
                	if (mWheelCount > 4)
                		wheels = createWheels<HeavyDutyWheel>();
                	else
                		wheels = createWheels<StandardWheel>();


                	return std::make_unique<Car>(mWeight, mWidth, mDoorCount, mColor, type,
                			std::make_unique<Engine>(mPower), std::move(wheels));
                }

                Builder& setWeight(float value) noexcept {
                        mWeight = value;
                        return *this;
                }

                Builder& setWidth(float value) noexcept {
                        mWidth = value;
                        return *this;
                }

                Builder& setDoorCount(int value) noexcept {
                        mDoorCount = value;
                        return *this;
                }

                Builder& setColor(std::string value) noexcept {
                        mColor = std::move(value);
                        return *this;
                }

                Builder&  setPower(int power) noexcept {
                	mPower = power;
                	return *this;
                }

                Builder&  setWheelCount(int wheelCount) noexcept {
                	mWheelCount = wheelCount;
                	return *this;
                }

        private:
                float mWeight = 2;
                float mWidth = 4;
                int mDoorCount = 4;
                std::string mColor = "black";
                int mPower = 100;
                int mWheelCount = 4;

                template <class T>
                Wheels createWheels() const
                {
                	Wheels wheels;
                	for (auto i = 0; i < mWheelCount; ++i)
                		wheels.emplace_back(std::make_unique<T>());
                	return wheels;
                }
        };

        Car(float weight, float width, int doorCount, std::string color,
        		Type type, EnginePtr engine, Wheels wheel)
			: mWeight{weight}
			, mWidth{width}
			, mDoorCount{doorCount}
			, mColor{std::move(color)}
			, mType{type}
			, mEngine{std::move(engine)}
			, mWheels{std::move(wheel)}
		{
		}
private:
		float mWeight = 0;
		float mWidth = 0;
		int mDoorCount = 0;
		std::string mColor;
		Type mType = Type::Family;
		EnginePtr mEngine;
		Wheels mWheels;
};

int
main()
{
	auto car = Car::Builder{}
		.setColor("blue")
		.setDoorCount(2)
		.setWidth(3.5f)
		.setWheelCount(6)
		.setPower(800)
		.create();
	return 0;
}

