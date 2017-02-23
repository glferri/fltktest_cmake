#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <memory>
#include <vector>
#include <iostream>

#include "fltktest_config.h"

int main(int argc, char **argv) {
    auto window = std::make_shared<Fl_Window>(340,180);
    auto box = std::make_shared<Fl_Box>(20,40,300,100,"Hello, World!");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    window->end();
    window->show(argc, argv);
   
    #ifdef DUMP_INFO 
    std::cout << "FLTKTEST " << fltktest_VERSION_MAJOR << "." << fltktest_VERSION_MINOR << std::endl;

    //test some c++11 
    std::vector<std::string> strings{"asdas","Awsda","asdasd"};
    for (auto str: strings)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    #endif
    return Fl::run();
}
