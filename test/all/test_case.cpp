#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "test_case.hpp"
#include "test_success.h"

#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

// ================ TestCaseList: Initialization ================
TestCaseList::TestCaseList(std::initializer_list<std::string> init) 
:completion_list_pointer(0)
{
    if (init.size() < 1) {
        throw std::invalid_argument("A TestCaseList must be initalized with "
                                    "at least one element");
    }

    auto it   = init.begin();
    list_name = *(it++);

    if (*it == UNIT_Success) {
        list_type = TestCaseListType::SUCCESS_FAILURE;
        did_succeed = true;
    } else {
        list_type = TestCaseListType::COMPLETION;
        did_succeed = false;
        for (; it!=init.end(); ++it) {
            completion_list.push_back(*it);
        }
    }
}

std::string      TestCaseList::name() { return list_name; }
TestCaseListType TestCaseList::type() { return list_type; } 

int TestCaseList::size() {
    switch (list_type) {
        case TestCaseListType::COMPLETION:
            return completion_list.size();

        case TestCaseListType::SUCCESS_FAILURE:
            return success_failure_list.size();

        default: return 0;
    }
}


// ================ TestCaseList: Operations ================
void TestCaseList::checkMessage(std::string message) {
    switch (list_type) {
        case TestCaseListType::COMPLETION: {
            if (!did_succeed && 
                completion_list[completion_list_pointer] == message) 
            {
                completion_list_pointer++;
                
                if (completion_list_pointer >= completion_list.size()) {
                    did_succeed = true;
                }
            }
            break;
        }

        case TestCaseListType::SUCCESS_FAILURE: {
            if (message == UNIT_Success) {
                success_failure_list.push_back(true);
            } else if (message == UNIT_Failure) {
                success_failure_list.push_back(false);
                did_succeed = false;
            }
            break;
        }

        default: break;
    }
}

bool TestCaseList::didSucceed() { return did_succeed; }

bool TestCaseList::didCheckSucceed(int i) {
    if (i < 0 || i >= success_failure_list.size()) {
        std::cerr << "didCheckSucceed: Invalid index" << std::endl;
        return false;
    }

    if (list_type != TestCaseListType::SUCCESS_FAILURE) {
        std::cerr << "didCheckSucceed: Cannot call this funciton on a non "
                     "SUCCESS_FAILURE list" << std::endl;
        return false;
    }

    return success_failure_list[i];
}


int TestCaseList::totalSuccess() {
    switch (list_type) {
        case TestCaseListType::COMPLETION:
            return completion_list_pointer;

        case TestCaseListType::SUCCESS_FAILURE: {
            int total = 0;
            for (int i=0; i<success_failure_list.size(); i++) {
                if (success_failure_list[i]) {
                    total++;
                }
            }
            return total;
        }

        default: return 0;
    }
}


// ================ TestSuite: Initialization ================
TestSuite::TestSuite(std::string path, 
                     std::initializer_list<TestCaseList> cases)
:program_log_path(path),
 test_case_lists(cases) {}


// ================ TestSuite: Evaluation ================
void TestSuite::evaluate() {
    // Open log
    std::ifstream program_log(program_log_path);
    if (!program_log.is_open()) {
        std::cerr << "Failed to open the log " << program_log_path 
                  << std::endl;
        return;
    }

    // Evaluate tests
    size_t pos;
    std::string line;
    std::string message;
    while (std::getline(program_log, line)) {
        pos = line.find("-SUC- ");
        if (pos == std::string::npos)
            pos = line.find("-ERR- ");

        if (pos != std::string::npos) {
            message = line.substr(pos+6);

            for (int i=0; i<test_case_lists.size(); i++) {
                test_case_lists[i].checkMessage(message);
            }
        }
    }

    // Print results
    for (int i=0; i<test_case_lists.size(); i++) {
        std::cout << test_case_lists[i].name() << " --- ";
        if (test_case_lists[i].didSucceed()) {
            std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
            continue;
        } 

        std::cout << RED << "FAILED" << RESET;

        switch (test_case_lists[i].type()) {
            case TestCaseListType::COMPLETION: {
                std::cout << ": stopped at " 
                          << test_case_lists[i].totalSuccess() 
                          << std::endl;
                break;
            }

            case TestCaseListType::SUCCESS_FAILURE: {
                std::cout << ":" << std::endl;
                int N = test_case_lists[i].size();

                int char_num = std::to_string(N).length();
                for (int j=0; j<N; j++) {
                    std::cout << "Trial: " 
                              << std::setw(char_num) << j 
                              << " --- ";
                    if (test_case_lists[i].didCheckSucceed(j)) {
                        std::cout << GREEN << "success" << RESET << std::endl;
                    } else {
                        std::cout << RED << "failure" << RESET << std::endl;
                    }
                }
                break;
            }

            default: break;
        }
    }
}
