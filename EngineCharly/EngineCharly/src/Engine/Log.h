#pragma once
#include "charlypch.h"
#include "Engine/Core.h"


namespace Charly {
	class CHARLY_API Log
	{
	private:
		enum class ConsoleColor {
			BLUE = 9,
			GREEN = 10,
			CYAN = 11,
			RED = 12,
			MAGENTA = 13,
			YELLOW = 14,
			WHITE = 15
		};

	public:
		Log(std::string name);
		Log();
		~Log();
		
		static void Init();

		inline static Log* GetLogger() { return _globalLog; }

		void Print(std::string text, const char* file, int line);
		void Print(std::string text, const char* file, int line, ConsoleColor color);
		void Print_Log(std::string text, const char* file, int line);
		void Print_Info(std::string text, const char* file, int line);
		void Print_Error(std::string text, const char* file, int line);

	private:
		std::string _name;
		HANDLE _hConsole;
		ConsoleColor _selectedColor = ConsoleColor::GREEN;
		static Log* _globalLog;
	};
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr (__FILE__, '\\') + 1 : __FILE__)

#define LOG(...) Charly::Log::GetLogger()->Print_Log(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
#define INFO(...) Charly::Log::GetLogger()->Print_Info(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
#define ERROR(...) Charly::Log::GetLogger()->Print_Error(std::format(__VA_ARGS__), __FILENAME__, __LINE__);

#define PRINT_LOG(...) log -> Print_Log(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
#define PRINT_INFO(...) log -> Print_Info(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
#define PRINT_ERROR(...) log -> Print_Error(std::format(__VA_ARGS__), __FILENAME__, __LINE__);
}

