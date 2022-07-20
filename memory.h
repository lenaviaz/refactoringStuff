#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>

int getSize();

bool checkAddress(int address);

void initialize(int address, std::string word);

int read(int address);

void write(int address, int a);

#endif