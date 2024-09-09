#pragma once
#include "Core.h"
#include "Event//Event.h"
#include "Event/ApplicationEvent.h"
#include "Engine/Window.h"


namespace Charly {
		class CHARLY_API Aplication {
		
		public:
			Aplication();
			virtual ~Aplication();
			void Run();

			void OnEvent(Event& e);

		private:
			bool OnwindowClosed(WindowcloseEvent& e);

			std::unique_ptr<Charly::Window> _Window;
			bool _running = true;
	};

		Aplication* CreateApplication();
}