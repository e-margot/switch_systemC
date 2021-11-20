#pragma once

#include <systemc.h>

class my_interface : public sc_interface {
public:
	virtual void writeToPort(int data) = 0;
	virtual int readToPort() = 0;
};