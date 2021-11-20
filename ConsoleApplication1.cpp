#define USE_OLD_CODE

#include <systemc.h>
#include "interface.h"
#include "engine.h"
#include "switch.h"

using namespace sc_core;
using namespace std;

#ifndef USE_OLD_CODE
SC_MODULE(STAGE) {
    //elaboration   
        SC_CTOR(STAGE) {
        std::cout << sc_time_stamp() << ": Elaboration: constructor" << std::endl;
      //  initialization + simulation
            SC_THREAD(thread);
    }
  //  cleanup
        ~STAGE() {
        std::cout << sc_time_stamp() << ": Cleanup: desctructor" << std::endl;
    }
    void thread() {
        std::cout << sc_time_stamp() << ": Execution.initialization" << std::endl;
        int i = 0;
        while (true) {
         //   advance - time
                wait(1, SC_SEC);
         //   evaluation
                std::cout << sc_time_stamp() << ": Execution.simulation" << std::endl;
            if (++i >= 2) {
              //  stop simulation after 2 iterations
                    sc_stop();
            }
        }
    }
    void before_end_of_elaboration() {
        std::cout << "before end of elaboration" << std::endl;
    }
    void end_of_elaboration() {
        std::cout << "end of elaboration" << std::endl;
    }
    void start_of_simulation() {
        std::cout << "start of simulation" << std::endl;
    }
    void end_of_simulation() {
        std::cout << "end of simulation" << std::endl;
    }
};
#else
int sc_main(int, char* []) {
    Switch sw("switch");
    Engine en("engine");

    sc_signal<int> s;
  //  sc_in<int> s;
    
    //sw.s_switch_in.bind(s);
    sw.s_switch_in(s);
    sw.s_switch_out(s);
    en.p_engine(s);
    sc_start(2, SC_SEC);
    return 0;
}
#endif