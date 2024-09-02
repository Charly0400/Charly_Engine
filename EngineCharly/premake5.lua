workspace "EngineCharly"
	architecture "x64"
	startproject "Sanbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

IncludeDir = {}
IncludeDir ["GLFW"] = "EngineCharly/vendor/GLWF/include"

include "EngineCharly/vendor/GLFW"


project "EngineCharly"
	location "EngineCharly"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "charlypch.h"
	pchsource "EngineCharly/src/charlypch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{IncludeDir.GLWF}"
	}
	
	links{
		"GLWF",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		runtime "Release"
		systemversion "latest"

		defines{
			"CHARLY_PLATFORM_WINDOWS",
			"CHARLY_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sanbox")
		}

	filter "configurations:Debug"
		defines "CHARLY_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CHARLY_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "CHARLY_DIST"
		buildoptions "/MD"
		symbols "On"

project "Sanbox"
	location "Sanbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"EngineCharly/src"
	}

	links {
		"EngineCharly"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "off"
		runtime "Release"
		systemversion "latest"

		defines{
			"CHARLY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHARLY_DEBUG"
				buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CHARLY_RELEASE"
				buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "CHARLY_DIST"
				buildoptions "/MD"
		symbols "On"

