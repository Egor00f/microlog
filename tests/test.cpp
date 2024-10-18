#include <microlog/microlog.hpp>

microlog::logger logger("test.log");

int main()
{
    const std::string result = "\n\
[Info] HelloWorld\n\
[Info] HelloWorld again!\n\
[Info] message message message message message message message message message message message message message message message message \n\
[Warning] Warning\n\
[Error] Error!\n\
[Debug] Debug!\n\
[Fatal] Fatal Error!";

    logger << microlog::LogLevel::Info << "HelloWorld" << std::endl;

	logger << "HelloWorld again!" << std::endl;

	for(std::size_t i = 0; i < 16; i++)
	{
		logger << "message ";
	}

	logger << microlog::LogLevel::Warning << "Warning";

	logger << microlog::LogLevel::Error << "Error!";

	logger << microlog::LogLevel::Debug << "Debug!";

	logger << microlog::LogLevel::Fatal << "Fatal Error!";


    std::ifstream file("test.log");

    std::string buff;

    if(file.is_open())
    {
        while (std::getline(file, buff)){}
    }

    return buff == result;
}