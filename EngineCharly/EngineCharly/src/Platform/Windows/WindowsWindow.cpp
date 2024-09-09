#include "charlypch.h"
#include "WindowsWindow.h"
#include "Engine/Log.h"

#include "Engine/Event/ApplicationEvent.h"
#include "Engine/Event/Event.h"
#include "Engine/Event/KeyEvent.h"
#include "Engine/Event/MouseEvent.h"

namespace Charly {
	static bool _GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		LOG("GLFW Error {0}: {1}", error, description);
	}

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
		_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return _Data.VSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		_Data.Title = props.Title;
		_Data.Width = props.Width;
		_Data.Height = props.Height;

		//Add debuf for screen size
		if (!_GLFWInitialized) {
			int succes = glfwInit();
			CHARLY_CORE_ASSERT(success. "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			//Add Error callback
			_GLFWInitialized = true;
		}

		_Window = glfwCreateWindow((int)props.Width, (int)props.Height, _Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_Window);
		glfwSetWindowUserPointer(_Window, &_Data);
		SetVSync(true);

		//GLFW Callbacks
		glfwSetWindowSizeCallback(_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowResizeEvent event(width, height);
			data.Width = width;
			data.Height = height;
			data.EventCallBack(event);
			});

		glfwSetWindowCloseCallback(_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowcloseEvent event;
			data.EventCallBack(event);
			});

		glfwSetKeyCallback(_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
			case GLFW_PRESS: {
				KeyPressedEvent event(key, 0);
				data.EventCallBack(event);
				break;
			}
			case GLFW_RELEASE: {
				KeyReleasedEvent event(key);
				data.EventCallBack(event);
				break;
			}
			case GLFW_REPEAT: {
				KeyPressedEvent event(key, 1);
				data.EventCallBack(event);
				break;
			}
			}
			});

		glfwSetMouseButtonCallback(_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
			case GLFW_PRESS: {
				MouseButtonPressedEvent event(button);
				data.EventCallBack(event);
				break;
			}
			case GLFW_RELEASE: {
				MouseButtonPressedEvent event(button);
				data.EventCallBack(event);
				break;
			}
			}
			});

		glfwSetScrollCallback(_Window, [](GLFWwindow* window, double  xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallBack(event);
			});

		glfwSetScrollCallback(_Window, [](GLFWwindow* window, double  xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xPos, (float)yPos);
			data.EventCallBack(event);
			});

	}
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(_Window);
	}

}