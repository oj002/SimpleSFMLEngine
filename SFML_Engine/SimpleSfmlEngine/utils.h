#pragma once
#include <intrin.h>
#include <Windows.h>
#include <iostream>

#define setConsoleTextColor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

namespace sse
{
#ifdef  __DEBUG__VS
#include <intrin.h>
#define DEBUG_BREAK __debugbreak();
#else
#define DEBUG_BREAK
#endif //!Debug


	typedef unsigned char byte;

	enum class logLevel : unsigned short
	{
		error = 0,
		warning = 1,
		info = 2
	};
	static logLevel m_logLevel = logLevel::info;

	inline void setLogLevel(logLevel logLevel)
	{
		m_logLevel = logLevel;
	}

	template<typename T>
	void logError(T str)
	{
		setConsoleTextColor(12);
		if (m_logLevel >= logLevel::error)
		{
			std::cout << "[ERROR] " << str << std::endl;
		}
		setConsoleTextColor(15);
	}

	template<typename T>
	void logWarning(T str)
	{
		setConsoleTextColor(11);
		if (m_logLevel >= logLevel::warning)
		{
			std::cout << "[WARNING] " << str << std::endl;
		}
		setConsoleTextColor(15);
	}

	template<typename T>
	void logInfo(T str)
	{
		setConsoleTextColor(14);
		if (m_logLevel >= logLevel::info)
		{
			std::cout << "[INFO] " << str << std::endl;
		}
		setConsoleTextColor(15);
	}

}