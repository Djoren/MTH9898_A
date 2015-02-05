/*
 *	main.cpp
 *
 *  Created on: 	Feb 5, 2015
 *	Author: 		Dion Joren
 *
 *	Description: 	Course MTH9898 - BDiF
 *					Main file for Assignment A
 *
 *	Version:		0) Building serial version of big data scrubbing
 */

#include <iostream>
#include <chrono>
#include <thread>

//Timer Macros
#define START_TIMER std::chrono::system_clock::time_point t0 = std::chrono::system_clock::now();
#define END_TIMER std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
#define ELAPSED_TIME_MS std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
#define ELAPSED_TIME_NS std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()


int main(int argc, char** argv){


	START_TIMER;
	for(int i=0; i<1000000; i++);
	END_TIMER;
	std::cout << ELAPSED_TIME_MS << std::endl;
	std::cout << ELAPSED_TIME_NS << std::endl;;

}

