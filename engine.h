#pragma once

#include <systemc.h>
#include "interface.h"

using namespace std;
using namespace sc_core;

class Engine : public sc_module
	//public my_interface
{
public:
	//sc_port<my_interface> p_engine;
	sc_in<int> p_engine;
	SC_CTOR(Engine) {
		SC_THREAD(outsideRead);
		sensitive << p_engine;
		dont_initialize();
	}
	/*Engine(sc_module_name name) : sc_module(name) {
		SC_THREAD(connectToPort);
		SC_METHOD(connectToPort);

	}*/
	void outsideRead() {
		while (true) {
			cout << sc_time_stamp() << ": reads from MODULE switch " << p_engine->read() << endl;
			wait();
		}
	}
	/*
	int readToPort() {
		cout << "this is reading from module engine(func readToPort)" << endl;
		return 6;
	}
	void writeToPort(int data) {

	}*/
};
