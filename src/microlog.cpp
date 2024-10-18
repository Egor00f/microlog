#include <microlog/microlog.hpp>

microlog::logger::logger(const std::string& path)
	:	_logfile(path),
		_currentLogLevel(microlog::LogLevel::Info)
{

}

microlog::logger::~logger()
{
	if(file.is_open())
		file.close();
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

	log.PrintLogLevel();

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