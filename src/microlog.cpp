#include <microlog/microlog.hpp>
#include <chrono>
#include <iomanip>
#include <ctime>

microlog::logger::logger(const std::string& path)
	:	_currentLogLevel(microlog::LogLevel::Info),
		file(path, std::ios::app)
{
    auto in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	*this << "Start Log: " << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << std::endl;
}

microlog::logger::~logger()
{
	if(file.is_open())
	{
		file << std::endl;
		file.close();
	}
}

void microlog::logger::flush()
{
	file.flush();
}

microlog::logger &microlog::operator<<(logger &log, const LogLevel &output)
{
	log._currentLogLevel = output;

	log << std::endl;

	return log;
}

microlog::logger &microlog::operator<<(logger &log, std::ostream& (*var)(std::ostream&))
{
	log.file << std::endl;

	log.newLine = true;

	return log;
}

void microlog::logger::PrintLogLevel()
{
	file << "[";

	switch (_currentLogLevel)
	{
	case microlog::LogLevel::Warning:
		
		file << "Warning";

		break;
	
	case microlog::LogLevel::Error:
		
		file << "Error";

		break;

	case microlog::LogLevel::Info:
		
		file << "Info";

		break;

	case microlog::LogLevel::Fatal:
		
		file << "Fatal";

		break;

	case microlog::LogLevel::Debug:
		
		file << "Debug";

		break;

	default:
		break;
	}

	file << "] ";
}