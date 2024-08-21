#pragma once
#include <EngineCharly.h>

class Sanbox : public Charly::Aplication {
public:
	Sanbox() {

	}

	~Sanbox() {
	}

};

Charly::Aplication* Charly::CreateApplication() {
	return new Sanbox();
}