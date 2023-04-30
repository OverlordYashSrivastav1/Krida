workspace "Krida"
	architecture "x64"
	

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	OPDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "Krida"
	
		location "Krida"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. OPDir .. "/%{prj.name}")
		objdir ("bin-int/" .. OPDir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"Krida/src",
			"Krida/vendor/spdlog/include"
			
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

		defines
		{
			"KD_PLATFORM_WINDOWS",
			"KD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. OPDir .. "\\Sandbox")
		}

		filter "configurations:Debug"
			defines "KD_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "KD_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "KD_DIST"
			optimize "On"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. OPDir .. "/%{prj.name}")
		objdir ("bin-int/" .. OPDir .. "/%{prj.name}")

		files
		{
			"%{prj.name}/src/**h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"Krida/vendor/spdlog/include",
			"Krida/src"
		}

		links
		{
			"Krida"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"KD_PLATFORM_WINDOWS"						
			}

		filter "configurations:Debug"
			defines "KD_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "KD_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "KD_DIST"
			optimize "On"
