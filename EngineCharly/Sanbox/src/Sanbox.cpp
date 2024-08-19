#pragma once
#include <EngineCharly.h>

class Sanbox : public Charly::Aplication {
public:
	Sanbox() {

	}

	~Sanbox() {
	}

};

Charly::Aplication* CreateApplication() {
	return new Sanbox();
}