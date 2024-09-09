#include "charlypch.h"
#include "Log.h"

CHARLY_API Charly::Log* Charly::Log::_globalLog;

Charly::Log::Log(std::string name) {

	_name = name;
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Charly::Log::Log() {
	_name = "Generic Log";
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Charly::Log::~Log() {

}

void Charly::Log::Init() {
	if (!_globalLog)
		_globalLog = new Log("Static Charly Log");
}

void Charly::Log::Print(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)_selectedColor);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}

/*void Charly::Log::Print(std::string text, const char* file, int line, ConsoleColor color)
{
	SetConsoleTextAttribute(_hConsole, (int)color);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
} */

void Charly::Log::Print_Log(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::GREEN);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}

void Charly::Log::Print_Info(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::CYAN);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}

void Charly::Log::Print_Error(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::RED);
	std::cout << _name << " (" << file << " , " << line << ")" << ": " << text << std::endl;
}