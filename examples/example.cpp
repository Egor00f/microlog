#include <microlog/microlog.hpp>


microlog::logger logger("log.log");

int main()
{

	logger << microlog::LogLevel::Info << "HelloWorld" << std::endl;

	logger << "HelloWorld again!" << std::endl;

	for(std::size_t i = 0; i < 16; i++)
	{
		logger << "message ";
	}

	logger << microlog::LogLevel::Warning << "Warning";

	logger << microlog::LogLevel::Error << "Error!";

	logger << microlog::LogLevel::Debug << "Debug!" << std::endl;

	logger << microlog::LogLevel::Fatal << "Fatal Error!";

	return 0;
}