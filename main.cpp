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
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <sstream>

//Timer Macros
#define START_TIMER std::chrono::system_clock::time_point t0 = std::chrono::system_clock::now();
#define END_TIMER std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
#define ELAPSED_TIME_MS std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
#define ELAPSED_TIME_NS std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()


//Dataholder for one tick
class Record{
private:
	std::string _t_stmp;
	double _price;
	double _vol;
public:
	//Record(std::string p, std::string v, std::string t) : _t_stmp(t), _price(p), _vol(v) {}
};

void parseLine(std::string s){
	//std::cout << s << std::endl;
	std::stringstream ss(s);
	std::string a, b, c;
	getline(ss, a, ',');
	getline(ss, b, ',');
	getline(ss, c, ',');
	//Record r(a, (double) b, (double) c);
}

int main(int argc, char** argv){

	START_TIMER;

	std::ifstream file("data100k.txt");
	std::string line;

	/*if(file){
		while(getline(file, line)){
			//parseLine(line);
		}
	}*/

	char data[0x1000];

	//while (file)
	//{
	  file.read(data, 0x1000);
	//}

	  std::cout << data << std::endl;

	END_TIMER;
	std::cout << ELAPSED_TIME_MS << std::endl;
	std::cout << ELAPSED_TIME_NS << std::endl;;
}

