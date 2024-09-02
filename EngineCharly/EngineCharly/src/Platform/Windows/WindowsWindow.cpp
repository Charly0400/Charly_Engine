#include "charlypch.h"
#include "WindowsWindow.h"
#include "Engine/Log.h"

#include "Engine/Event/ApplicationEvent.h"
#include "Engine/Event/Event.h"
#include "Engine/Event/KeyEvent.h"
#include "Engine/Event/MouseEvent.h"

namespace Charly {
	static bool _GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	Charly::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
	}

	Charly::WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}	

	void Charly::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		_Data.Vsync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return _Data.Vsync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		_Data.Title = props.Title;
		_Data.Width = props.Width;
		_Data.Height = props.Height;

		//Add debuf for screen size
		if (!_GLFWInitialized) {
			int succes = glfwInit();
			//Add Error callback
			_GLFWInitialized = true;
		}

		_Window = glfwCreateWindow((int)props.Width, (int)props.Height, _Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_Window);
		glfwSetMonitorUserPointer(_Window, &_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(_Window);
	}

}