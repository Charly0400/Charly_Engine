#include "charlypch.h"
#include "Aplication.h"
#include "log.h"
#include <GLFW/glfw3.h>

namespace Charly {
#define BIND_EVENT_FN(x) std::bind(&Aplication::x, this, std::placeholders::_1)

	Aplication::Aplication() {
		_Window = std::unique_ptr<Window>(Window::Create());
		_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Aplication:: ~Aplication() {

	}

	void Aplication::Run() {
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_Window->OnUpdate();
		}
	}

	void Aplication::OnEvent(Event& e) {
		if (e.GetEventType() == EventType::WindowClose) {
			OnwindowClosed(*(WindowcloseEvent*)&e);
		}
		LOG("{0}", e.ToString());
	}

	bool Aplication::OnwindowClosed(WindowcloseEvent& e) {
		_running = false;
		return false;
	}

}