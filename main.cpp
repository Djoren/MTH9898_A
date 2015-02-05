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
#include <vector>

//Timer Macros
#define START_TIMER std::chrono::system_clock::time_point t0 = std::chrono::system_clock::now();
#define END_TIMER std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
#define ELAPSED_TIME_MS std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
#define ELAPSED_TIME_NS std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()


//Dataholder for one tick
struct Record{
	std::string _t_stmp = "";
	double _price = 0.0;
	int _vol = 0.0;

	Record() {}
	Record(std::string& t, double p, int v) : _t_stmp(t), _price(p), _vol(v) {}
	bool isNoise(double p_mu, double p_sd, double vol_mu, double vol_sd) const; //Check record for noise
};

//Check is record is noise
bool Record::isNoise(double p_mu, double p_sd, double vol_mu, double vol_sd) const{
	if(_price <= 0) return true;
	if(_vol <= 0) return true;
	if(_price < p_mu - 4*p_sd || _price > p_mu + 4*p_sd ) return true;
	if(_vol < vol_mu - 4*vol_sd || _vol > vol_mu + 4*vol_sd ) return true;
	return false;
}

//Scrubs block of data for noise
void scrub(std::vector<Record>& block){


}

//Parse line of text
void parseLine(std::string& s, std::vector<Record>& block, int i){
	std::stringstream ss(s);
	std::string t, p, v;
	getline(ss, t, ',');
	getline(ss, p, ',');
	getline(ss, v);
	block[i] = Record(t, std::stod(p), std::stoi(v));
}

//Parse blocks of data sequentially
void parseBlocks(std::ifstream& f, std::vector<Record>& block){
	int index = 0;
	std::string line;

	while(true){
		for(int i=0; i<50; i++){
			if(!getline(f, line)) return;
			parseLine(line, block, index++);
		}
		scrub(block);
		index = 0;
	}
}


int main(int argc, char** argv){

	START_TIMER;

	std::ifstream file("data100k.txt");
	std::vector<Record> block(50, Record());
	std::cout << block.size() << std::endl;

	if(file){
		parseBlocks(file, block);
	}

	/*char data[0x1000];
	//while (file)
	//{
	  file.read(data, 0x1000);
	//}

	  std::cout << data << std::endl;
	*/


	END_TIMER;
	std::cout << ELAPSED_TIME_MS << std::endl;
	std::cout << ELAPSED_TIME_NS << std::endl;;
}

