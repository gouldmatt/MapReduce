#ifndef GUESTWORDCOUNT_HPP
#define GUESTWORDCOUNT_HPP

std::vector<std::string> inputReader(std::ifstream& file);

void map(); 

void reduce(); 

void output(); 

#endif