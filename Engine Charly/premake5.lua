workspace "Engine Charly"
	architecture "x64"
	startproject "Sanbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine Charly"
	location "Engine Charly"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CHARLY_PLATFORM_WINDOWS",
			"CHARLY_BUILD_DLL"
		}

		postbuildcommands{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sanbox")
		}

	filter "configurations:Debug"
		defines "CHARLY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CHARLY_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CHARLY_DIST"
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
		"Engine Charly/src"
	}

	links {
		"Engine Charly"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CHARLY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CHARLY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CHARLY_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CHARLY_DIST"
		symbols "On"

