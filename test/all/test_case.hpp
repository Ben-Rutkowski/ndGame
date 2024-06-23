#ifndef TEST_CASE_HPP
#define TEST_CASE_HPP

#include <initializer_list>
#include <vector>
#include <string>

// ================ TestCaseList ================
class TestCaseList {

// --- Attributes ---
private:
    std::string list_name;
    std::vector<std::string> list;
    int  list_pointer;
    bool did_succeed;


// --- Initialization ---
public:
    TestCaseList(std::initializer_list<std::string> init);
    std::string name();
    int size();


// --- Operations ---
public:
    void checkMessage(std::string message);
    bool didSucceed();
    int  howManySuccess();
      
};


// ================ TestSuite ================
class TestSuite {

// --- Attributes ---
private:
    std::string program_log_path;
    std::vector<TestCaseList> test_case_lists;


// --- Initialization ---
public:
    TestSuite(std::string path, 
              std::initializer_list<TestCaseList> cases);


// --- Operations ---
public:
    void evaluate();
};


// ================ Evaluation ================
void evaulateBuild(std::string program_log_path, 
                   std::vector<TestCaseList> test_case_lists);

#endif
