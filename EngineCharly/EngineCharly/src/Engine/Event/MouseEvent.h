#pragma once

#include "Engine/Core.h"
#include "Event.h"
#include <sstream>

namespace Charly {
	class CHARLY_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent (int x, int y)
			: _MouseX(x), _MouseY(y){}

		inline float GetX() const { return _MouseX; }
		inline float GetY() const { return _MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _MouseX << ", " << _MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _MouseX, _MouseY;
	};

	class CHARLY_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xoffset, float yoffset)
			: _Xoffset(xoffset), _Yoffset(yoffset) {}

		inline float GetXOffset() const{  return _Xoffset; }
		inline float GetYOffset() const { return _Yoffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _Xoffset << ", " << _Yoffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _Xoffset, _Yoffset;
	};

	class CHARLY_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return _button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	
	protected:
		MouseButtonEvent(int button) : _button(button){}
		int _button;

	};

	class CHARLY_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class CHARLY_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
