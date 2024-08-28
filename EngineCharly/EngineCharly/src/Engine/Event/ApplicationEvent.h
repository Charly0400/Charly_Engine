#pragma once

#include "Engine/Core.h"
#include "Event.h"
#include "charlypch.h"

namespace Charly {
	class CHARLY_API WindowResizeEvent : public Event {

	public:
		WindowResizeEvent(unsigned int width, unsigned int height) 
		: _widht(width), _height(height) {}

		inline unsigned int GetWidht() { return _widht; }
		inline unsigned int GetHeight() { return _height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Window resize event " << _widht << ", " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)


	private:
		unsigned int _widht;
		unsigned int _height;

	};
		class CHARLY_API WindowcloseEvent : public Event {
		public:
			WindowcloseEvent(){}

			EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};
}