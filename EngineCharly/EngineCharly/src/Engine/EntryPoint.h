#pragma once

#ifdef CHARLY_PLATFORM_WINDOWS
extern Charly::Aplication* Charly::CreateApplication();

int main (int arc, char** arcv){
	auto app = Charly::CreateApplication();
	app->Run();
	delete app;
	}
#else 
	#error Only support Windows
#endif
