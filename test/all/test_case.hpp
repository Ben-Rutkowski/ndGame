#ifndef TEST_CASE_HPP
#define TEST_CASE_HPP

#include <initializer_list>
#include <vector>
#include <string>


enum class TestCaseListType {
    COMPLETION, SUCCESS_FAILURE
};

// ================ TestCaseList ================
class TestCaseList {

// --- Attributes ---
private:
    std::string      list_name;
    TestCaseListType list_type;
    bool did_succeed;

    std::vector<std::string> completion_list;
    int completion_list_pointer;

    std::vector<bool> success_failure_list;


// --- Initialization ---
public:
    TestCaseList(std::initializer_list<std::string> init);
    TestCaseListType type();
    std::string name();
    int size();


// --- Operations ---
public:
    void checkMessage(std::string message);
    bool didSucceed();
    bool didCheckSucceed(int i);
    int  totalSuccess();

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

#endif
