#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "test_case.hpp"

#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

// ================ Initialization ================
TestCaseList::TestCaseList(std::initializer_list<std::string> init) 
:list_pointer(0),
 did_succeed(false)
{
    if (init.size() < 1) {
        throw std::invalid_argument("A TestCaseList must be initalized with at least one element");
    }

    auto it = init.begin();
    list_name = *(it++);

    for (; it!=init.end(); ++it) {
        list.push_back(*it);
    }
}

std::string TestCaseList::name() { return list_name; }
int TestCaseList::size() { return list.size(); }


// ================ Operations ================
void TestCaseList::checkMessage(std::string message) {
    if (!did_succeed && list[list_pointer] == message) {
        list_pointer++;
        
        if (list_pointer >= list.size()) {
            did_succeed = true;
        }
    }
}

bool TestCaseList::didSucceed()     { return did_succeed; }
int  TestCaseList::howManySuccess() { return list_pointer; }


// ================ Evaluation ================
void evaulateBuild(std::string program_log_path, 
                   std::vector<TestCaseList> test_case_lists)
{
    std::ifstream program_log(program_log_path);
    if (!program_log.is_open()) {
        std::cerr << "Failed to open the log " << program_log_path << std::endl;
        return;
    }

    size_t pos;
    std::string message;
    std::string line;
    while (std::getline(program_log, line)) {
        pos = line.find("-SUC- ");
        if (pos != std::string::npos) {
            message = line.substr(pos+6);

            for (int i=0; i<test_case_lists.size(); i++) {
                test_case_lists[i].checkMessage(message);
            }
        }
    }

    for (int i=0; i<test_case_lists.size(); i++) {
        std::cout << test_case_lists[i].name() << " --- ";
        if (test_case_lists[i].didSucceed()) {
            std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
        } else {
            std::cout << RED << "FAILED" << RESET 
                      << ": stopped at " << test_case_lists[i].howManySuccess() 
                      << std::endl;
        }
    }
}
