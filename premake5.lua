workspace "GLRE"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "GLRE"
	location "GLRE"
	kind "SharedLib" -- DLL
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	-- to apply certain properties to specific platforms
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"GLRE_PLATFORM_WINDOWS",
			"GLRE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")	-- {command}
		}
	
	filter "configurations:Debug"
		defines "GLRE_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "GLRE_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "GLRE_DIST"
		optimize "on"


-- Projects using glRE DLL

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp" -- DLL
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"GLRE/vendor/spdlog/include",
		"GLRE/src"
	}

	-- to apply certain properties to specific platforms
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"GLRE_PLATFORM_WINDOWS"
		}
	
	links
	{
		"GLRE"
	}

	filter "configurations:Debug"
		defines "GLRE_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "GLRE_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "GLRE_DIST"
		optimize "on"





