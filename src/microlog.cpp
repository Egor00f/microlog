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
	_ksys_debug_putc('\n');

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

void microlog::logger::PrintLogLevel()
{
	std::string output = "[";

	switch (_currentLogLevel)
	{
	case microlog::LogLevel::Info:

		output += "Info";

		break;

	case microlog::LogLevel::Debug:

		output += "Debug";

		break;

	case microlog::LogLevel::Warning:

		output += "Warning";

		break;

	case microlog::LogLevel::Error:

		output += "Error";

		break;

	case microlog::LogLevel::Fatal:

		output += "Fatal";

		break;

	default:
		output += "IDK";

		break;
	}

	output += "] ";
  
	_ksys_debug_puts(output.c_str());

	if (file.is_open())
		file << output;
}

microlog::logger &microlog::operator<<(logger &log, const LogLevel &output)
{
	log._currentLogLevel = output;

	log << std::endl;

	return log;
}

microlog::logger &microlog::operator<<(logger &log, std::ostream &(*)(std::ostream &))
{
	log.newLine = true;

	return log;
}
