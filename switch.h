#pragma once

#include <systemc.h>
#include "interface.h"

using namespace std;
using namespace sc_core;

class Switch: public sc_module
	//public my_interface
{
public:
	//sc_port<my_interface> p_switch;
	//sc_signal<int> s_switch;
	sc_out<int> s_switch_out;
	sc_in<int> s_switch_in;

	SC_HAS_PROCESS(Switch);

	Switch(sc_module_name name) : sc_module(name) {
		//Switch(s_switch);
		SC_THREAD(selfWrite);
		SC_THREAD(selfRead);
		sensitive << s_switch_in;
		dont_initialize();
	//	SC_THREAD(outsideWrite);
	}

	void selfWrite() {
		int val = 1;
		while (true) {
			cout << "self write" << endl;
			s_switch_out.write(val++);
			wait(1, SC_SEC);
		}
	}
	void selfRead() {
		while (true) {
			cout << sc_time_stamp() << ": read from own channel, val = " << s_switch_in.read() <<endl;
			wait();
		}
	} /*
	void outsideWrite() {
		int val = 1;
		while (true) {
			//p_switch->writeToPort(val++);
			s_switch_out->writeToPort(val++);
			//p_switch->write(val++);
			//p_switch->write();
			wait(1, SC_SEC);
		}

	}
	void writeToPort(int data) {
		cout << "this is my value of switch: " << data << endl;
		//p_switch->write();
	}
	int readToPort() {
		return 1;
	}*/
};