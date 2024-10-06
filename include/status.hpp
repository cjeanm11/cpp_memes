#ifndef STATUS_HPP
#define STATUS_HPP

#include <string>

// Enum for status codes
enum class StatusCode {
    OK = 0,
    ERROR = 1,
    NOT_FOUND = 2,
    INVALID_ARGUMENT = 3,
};
class Status {
public:
    Status() : m_code(StatusCode::OK), m_message("") {}
    Status(StatusCode code, const std::string& message) : m_code(code), m_message(message) {}

    static Status OK() {
        return Status(StatusCode::OK, "Success");
    }

    StatusCode code() const {
        return m_code;
    }

    std::string message() const {
        return m_message;
    }

    bool IsOK() const {
        return m_code == StatusCode::OK;
    }

private:
    StatusCode m_code;
    std::string m_message;
};

#endif // STATUS_HPP