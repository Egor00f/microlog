#include <microlog/microlog.hpp>
#include <ctime>

microlog::logger::logger(const std::string& path)
	:	_currentLogLevel(microlog::LogLevel::Info),
		file(path, std::ios::app)
{
	std::time_t timer = std::time(NULL);
    auto tm_info = std::localtime(&timer);

	char buffer[128];

	std::strftime(buffer, sizeof(buffer), "Start Log: %D %T", tm_info);

	*this << buffer << std::endl;
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

	if(log.file.is_open())
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