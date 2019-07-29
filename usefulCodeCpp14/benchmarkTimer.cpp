#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

template<class Resolution = std::chrono::milliseconds>
class ExecutionTimer
{
public:
	using Clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady,
									std::chrono::high_resolution_clock,
									std::chrono::steady_clock>;
	ExecutionTimer() = default;
	~ExecutionTimer() {
		// use std::chrono::duration_cast<std::chrono::milliseconds> casting to get milliseconds
		// system_clock is not good for time measurement
		std::cout
			<< "Elapsed: "
			<< std::chrono::duration_cast<Resolution>(Clock::now() - mStart).count() << std::endl;
	}
private:
	Clock::time_point mStart = Clock::now();
};

int
main()
{
	ExecutionTimer<> timer;
	ExecutionTimer<std::chrono::seconds> timer2;
	// example of good benchmark
	std::vector<int> v(50000000);
	std::sort(std::begin(v), std::end(v));
/*
#include <ctime>
	const auto start = time(nullptr);

	// example of not good benchmark
	std::vector<int> v(50000000);
	std::sort(std::begin(v), std::end(v));

	std::cout << "Elapsed: " << (time(nullptr) - start) << "s" << "\n";
*/
	return 0;
}

