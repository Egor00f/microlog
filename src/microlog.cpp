#include <microlog/microlog.hpp>
#include <ctime>

microlog::logger::logger(const std::string &path)
	: file(path, std::ios::app)
{
	std::time_t timer = std::time(NULL);
	auto tm_info = std::localtime(&timer);

	char buffer[64];

	std::strftime(buffer, sizeof(buffer), "Start Log: %D %T", tm_info);

	*this << microlog::LogLevel::Info << buffer << std::endl;
}

microlog::logger::~logger()
{
	if (file.is_open())
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

microlog::logger &microlog::operator<<(logger &log, std::ostream &(*)(std::ostream &))
{
	if (log.file.is_open())
		log.file << std::endl;

	log.newLine = true;

	return log;
}

void microlog::logger::PrintLogLevel()
{
	std::string output = "[";

	switch (_currentLogLevel)
	{
	case microlog::LogLevel::Warning:

		output += "Warning";

		break;

	case microlog::LogLevel::Error:

		output += "Error";

		break;

	case microlog::LogLevel::Info:

		output += "Info";

		break;

	case microlog::LogLevel::Fatal:

		output += "Fatal";

		break;

	case microlog::LogLevel::Debug:

		output += "Debug";

		break;

	default:
		output += "IDK";
		
		break;
	}

	output += "] ";

	if (file.is_open())
		file << output;
}
