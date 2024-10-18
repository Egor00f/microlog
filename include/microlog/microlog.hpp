#ifndef __MICROLOG_HPP__
#define __MICROLOG_HPP__

#include <fstream>

/**
 * @brief microlog libarry namespace
 * @details idk.
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
		 * @brief Fatal error
		 */
		Fatal,

		/**
		 * @brief Error
		 */
		Error,

		/**
		 * @brief Warning
		 */
		Warning,

		/**
		 * @brief Info message
		 */
		Info,

		/**
		 * @brief Debug message
		 */
		Debug
	};

	/**
	 * @brief logger
	 */
	class logger
	{
	public:
		/**
		 * @brief Constructor
		 * @param path pfth to log file
		 */
		logger(const std::string& path);

		/**
		 * @brief Destructor
		 */
		~logger();

		/// @brief Print log message
		/// @tparam T
		/// @param output 
		/// @return 
		template< class T >
		logger& operator << (const T& output)
		{

			if(file.is_open())
			{
				file << output;
			}

			if(_currentLogLevel != LogLevel::Info)
				file.flush();

			return *this;
		}	


		/**
		 * @brief flush
		 */
		void flush();

		/// @brief Make end of line
		/// @param log 
		/// @param var 
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
		LogLevel _currentLogLevel;
	};

	logger& operator << (logger &log, const LogLevel& output);

	logger& operator << (logger& log, std::ostream& (*var)(std::ostream&));
		
} // namespace microlog
/**
 * @example example.cpp
 * Example of use this lib
 */

#endif // __MICROLOG_HPP__
