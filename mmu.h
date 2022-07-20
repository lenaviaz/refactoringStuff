#ifndef MMU_H
#define MMU_H
#include "memory.cpp"
#include <string>

// Memory Management Unit Class
// handles all requests to read and write to memory and redirrects them to the appropriate memory module

int getSize();

bool checkAddressBounds(int address, memory &mem);

bool checkMap(int address, memory &mem);

void attach(int address, memory &mem);

void initialize(int address, std::string word);

int read(int address);

void write(int address, int a);

#endif