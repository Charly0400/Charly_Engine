#pragma once

#ifdef CHARLY_PLATFORM_WINDOWS
extern Charly::Aplication* Charly::CreateApplication();

int main(int arc, char** arcv) {

	Charly::Log::Init();
	auto app = Charly::CreateApplication();

	/*auto app = Charly::CreateApplication();
	Charly::Log* log = new Charly::Log("TestLog");
	log->Print("Entry point print", __FILE__, __LINE__);
	LOG("Entry point print");
	LOG_TEST("{0} {1} random numbers", 20, 32);
	PRINT_LOG("Log");
	PRINT_INFO("Info");
	PRINT_ERROR("Error");*/
	app->Run();
	delete app;
	}
#else 
	#error Only support Windows
#endif
