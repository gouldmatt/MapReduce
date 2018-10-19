#ifndef GUESTPRIMENUMBERHPP
#define GUESTPRIMENUMBERHPP

std::vector<std::string> inputReader(std::ifstream& file);

std::pair <std::string,int> map(std::string element); 

std::pair <std::string,int> reduce(std::vector< std::pair <std::string,int> > matrixProductElement); 

void output(std::vector< std::pair <std::string,int> > wordPairsReduced); 

bool isPrime(int num);

#endif