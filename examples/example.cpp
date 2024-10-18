#include <microlog/microlog.hpp>


microlog::logger logger("log.log");

int main()
{

	logger << microlog::LogLevel::Info << "HelloWorld";

	logger << microlog::LogLevel::Warning << "Warning";

	return 0;
}