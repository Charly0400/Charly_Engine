#pragma once

#include "Engine/Core.h"
#include "Event.h"
#include <sstream>

namespace Charly {
	class CHARLY_API KeyEvent : public Event {
	public:
		inline int GetKeycode() { return _keyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryInput)

	protected:
		KeyEvent(int keyCode) : _keyCode(keyCode){}
		int _keyCode;
	};

	class CHARLY_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeateCount) 
			: KeyEvent(keyCode), _repeatCount(repeateCount) {}

		std::string ToString() {
			std::stringstream ss;
			ss << "Key Pressed Event: " << _keyCode << "(" << _repeatCount << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(keyPressed)
	private:
		int _repeatCount;
	};

	class CHARLY_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode){}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Key Released Event: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}