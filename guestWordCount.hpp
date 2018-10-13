#ifndef GUESTWORDCOUNT_HPP
#define GUESTWORDCOUNT_HPP

std::vector<std::string> inputReader(std::ifstream& file);

std::vector< std::pair <std::string,int> > map(std::vector<std::string> inputReaderVec); 

std::vector< std::pair <std::string,int> > reduce(std::vector< std::pair <std::string,int> > wordPairs); 

void output(std::vector< std::pair <std::string,int> > wordPairsReduced); 

#endif