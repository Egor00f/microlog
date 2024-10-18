#ifndef __MICROLOG_HPP__
#define __MICROLOG_HPP__

#include <fstream>
#include <iostream>

/**
 * @brief microlog libarry namespace
 * @details idk
 * @author Egor00f
 */
namespace microlog
{
	/**
	 * @brief
	 */
	enum class LogLevel
	{
		/**
		 * @brief 
		 */
		Fatal,

		/**
		 * @brief
		 */
		Error,

		/**
		 * @brief
		 */
		Warning,

		/**
		 * @brief
		 */
		Info,

		/**
		 * @brief
		 */
		Debug
	};

	/**
	 * @brief 
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

		template< class T >
		logger& operator << (const T& output)
		{
			file.open(_logfile, std::ios::app);

			if(file.is_open())
			{
				file << output;
			}

			if(_currentLogLevel != LogLevel::Info)
				file.flush();

			return *this;
		}	


		void flush();

		friend logger& operator << (logger& log, std::ostream& (*var)(std::ostream&));

		friend logger& operator << (logger &log, const LogLevel& output);

	private:

		void PrintLogLevel();

		std::ofstream file;
		std::string _logfile;
		LogLevel _currentLogLevel;
	};

	logger& operator << (logger &log, const LogLevel& output);

	logger& operator << (logger& log, std::ostream& (*var)(std::ostream&));
		
} // namespace microlog


#endif // __MICROLOG_HPP__
