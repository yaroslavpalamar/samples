#include "main.h"
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
#include <string>
// there are other ways of getting a path relative to the executable, but this
// one is part of the STL soon (if you can talk about soon in c++ development)
#include <boost/filesystem.hpp>
using boost::filesystem::absolute;

// when testing, the main of gtest and this main function will collide,
// this prevents the collision, but it's an ugly hack like all ifdef branches
#ifdef UNIT_TESTS
#define MAIN not_main
#else
#define MAIN main
#endif


#include <boost/asio.hpp>
#include <chrono>
#include <ctime>
namespace ba = boost::asio;

void timer_expired(std::string id)
{
	auto start = std::chrono::system_clock::now();
	std::time_t ttp = std::chrono::system_clock::to_time_t(start);	
	std::cout << std::ctime(&ttp) << " " << id << " : enter \n";

	std::this_thread::sleep_for(std::chrono::seconds(3));
	
	start = std::chrono::system_clock::now();
	ttp = std::chrono::system_clock::to_time_t(start);	
	std::cout << std::ctime(&ttp) << " " << id << " : exit \n";
}

void test1()
{
	ba::io_service service;
	ba::deadline_timer timer(service, boost::posix_time::seconds(5));
	timer.async_wait ([](auto ... vn)
				{
					auto start = std::chrono::system_clock::now();
					std::time_t ttp = std::chrono::system_clock::to_time_t(start);	
					std::cout << std::ctime(&ttp) << " : timer expored. \n";
				}
		);
	auto start = std::chrono::system_clock::now();
	std::time_t ttp = std::chrono::system_clock::to_time_t(start);
	std::cout << std::ctime(&ttp) << " : calling run \n";

	service.run();
	
	start = std::chrono::system_clock::now();
	ttp = std::chrono::system_clock::to_time_t(start);
	std::cout << std::ctime(&ttp) << " : done. \n";
}

void test2 ()
{	
	ba::io_service service;
	ba::deadline_timer timer1(service, boost::posix_time::seconds(5));
	ba::deadline_timer timer2(service, boost::posix_time::seconds(5));
	timer1.async_wait ([](auto ... vn) {timer_expired("timer1"); });
	timer2.async_wait ([](auto ... vn) {timer_expired("timer2"); });

	std::thread butler([&]() {service.run();} );
	butler.join();
	
	std::cout << "done. \n";
}

void test3()
{
	ba::io_service service;
	service.post([]() {std::cout<<"eat"<<"\n";});
	service.post([]() {std::cout<<"drink"<<"\n";});

	std::thread butler([&]() {service.run();} );
	butler.join();
	
	std::cout << "done. \n";

}

void test2_two_threads_not_sync ()
{	
	ba::io_service service;
	ba::deadline_timer timer1(service, boost::posix_time::seconds(5));
	ba::deadline_timer timer2(service, boost::posix_time::seconds(5));
	timer1.async_wait ([](auto ... vn) {timer_expired("timer1"); });
	timer2.async_wait ([](auto ... vn) {timer_expired("timer2"); });

	std::thread butler1([&]() {service.run();} );

	std::thread butler2([&]() {service.run();} );


	butler1.join();
	butler2.join();
	
	std::cout << "done. \n";
}

void test2_two_threads_not_sync_fixed ()
{
	ba::io_service service;
	ba::io_service::strand strand(service);
	ba::deadline_timer timer1(service, boost::posix_time::seconds(5));
	ba::deadline_timer timer2(service, boost::posix_time::seconds(5));
	timer1.async_wait (
		strand.wrap([](auto ... vn) {timer_expired("timer1"); })
	);
	timer2.async_wait (
		strand.wrap([](auto ... vn) {timer_expired("timer2"); })
	);

	std::thread butler1([&]() {service.run();} );

	std::thread butler2([&]() {service.run();} );


	butler1.join();
	butler2.join();
	
	std::cout << "done. \n";
}

void test4_three_threads_not_sync_fixed ()
{
	ba::io_service service;
	ba::io_service::strand strand(service);
	ba::deadline_timer timer1(service, boost::posix_time::seconds(3));
	ba::deadline_timer timer2(service, boost::posix_time::seconds(3));
	ba::deadline_timer timer3(service, boost::posix_time::seconds(6));
	timer1.async_wait (
		strand.wrap([](auto ... vn) {timer_expired("timer1"); })
	);
	timer2.async_wait (
		strand.wrap([](auto ... vn) {timer_expired("timer2"); })
	);
	timer3.async_wait (
		[](auto ... vn) {timer_expired("timer3"); }
	);

	std::thread butler1([&]() {service.run();} );

	std::thread butler2([&]() {service.run();} );


	butler1.join();
	butler2.join();
	
	std::cout << "done. \n";
}



int MAIN(int argc, char** argv) {

	//test1();
	//test2();
	//test3();
	//test2_two_threads_not_sync_fixed(); 
	test4_three_threads_not_sync_fixed(); 


  // this way you can have a path relative to the executable
  // the absolute also gets rid of symlinks, so it should work pretty stable
  auto resource_path = absolute(argv[0]).parent_path() / "resources";
  std::fstream resource1((resource_path / "resource1").string());
  std::string line;
  while(resource1) {
    std::getline(resource1, line);
    cout << line << endl;
  }
  return EXIT_SUCCESS;
}


// just some function to have something that can be test
#include <exception>

void GetFrobnicationInterval() {
  throw std::string("InvalidOperation: frobnication interval can't be retrieved");
}
