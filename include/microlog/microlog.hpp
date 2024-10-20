#ifndef __MICROLOG_HPP__
#define __MICROLOG_HPP__

#include <fstream>

/**
 * @brief microlog libary namespace
 * @details just small logger lib
 * @author Egor00f
 */
namespace microlog
{
	/**
	 * @brief Log Levels
	 */
	enum class LogLevel
	{
		/**
		 * @brief Info message
		 */
		Info = 0,

		/**
		 * @brief Debug message
		 */
		Debug,

		/**
		 * @brief Warning
		 */
		Warning,

		/**
		 * @brief Error
		 */
		Error,

		/**
		 * @brief Fatal error
		 */
		Fatal
	};

	/**
	 * @brief logger
	 */
	class logger
	{
	public:
		/**
		 * @brief Constructor
		 * @param path path to log file
		 */
		logger(const std::string& path);

		/**
		 * @brief Destructor
		 */
		~logger();

		/// @brief Print log message
		/// @tparam T
		/// @param output that you want put to log file
		/// @return 
		template< class T >
		logger& operator << (const T& output)
		{

			if(newLine)
			{
				PrintLogLevel();
				newLine = false;
			}

			if(file.is_open())
			{
				file << output;
			}

			if(_currentLogLevel > LogLevel::Info)
				file.flush();

			return *this;
		}	

		/**
		 * @brief flush
		 */
		void flush();

		/// @brief Make end of line
		/// @param log 
		/// @param var std::endl
		/// @return 
		friend logger& operator << (logger& log, std::ostream& (*var)(std::ostream&));

		/// @brief Set log level
		/// @param log 
		/// @param output log level
		/// @return 
		friend logger& operator << (logger &log, const LogLevel& output);

	private:

		void PrintLogLevel();

		/**
		 * @brief file
		 */
		std::ofstream file;

		/**
		 * @brief Current log level
		 */
		LogLevel _currentLogLevel = LogLevel::Info;
		
		/**
		 * @brief Now is new line
		 */
		bool newLine = false;
	};

	logger& operator << (logger &log, const LogLevel& output);

	logger& operator << (logger& log, std::ostream& (*var)(std::ostream&));
		
} // namespace microlog
/**
 * @example example.cpp
 * Example of use this lib
 */

#endif // __MICROLOG_HPP__
