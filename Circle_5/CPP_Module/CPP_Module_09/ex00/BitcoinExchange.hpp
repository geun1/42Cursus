#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
#include <map>
#include <cstring>
#include <string>
#include <exception>

void	btc(const char *dataBase, const char *inputFile);
void	checkArg(int ac, char **av);

#endif