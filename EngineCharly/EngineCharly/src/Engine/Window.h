#pragma once
#include "charlypch.h"
#include "Engine/Core.h"
#include "Engine/Event/Event.h"

namespace Charly {
	struct WindowProps {
		std::string Title;
		unsigned int Widht;
		unsigned int Height;
		WindowProps (const std::string title = "Engine Charly",
			unsigned int width, unsigned int height) :
			Title(title), Widht(width), Height(height) {}
	};

	class CHARLY_API Window {
	public: 
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window();
		virtual void OnUpdate() const = 0;
		virtual void GetWidht() const = 0;
		virtual void GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback);
		virtual void SetVSync(bool enabled);
		virtual void IsVSync() const = 0;

		static Window* Creat(const WindowProps& props = WindowProps());

	};
}