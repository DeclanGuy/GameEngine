workspace "Hazel"
	architecture "x64"
	startproject "Sandbox"
	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"Hazel/src/**.h",
		"Hazel/src/**.cpp"
	}

	includedirs {
		"Hazel/vendor/spdlog/include" -- FIXED: Absolute relative path to vendor
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		toolset "msc-v145"
		buildoptions { "/utf-8" } 

		defines {
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL"
		}
		postbuildcommands {
			
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"") 
}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"

	filter {} -- Resets filter scope

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"Sandbox/src/**.h",
		"Sandbox/src/**.cpp"
	}

	includedirs {
		"Hazel/vendor/spdlog/include", -- FIXED: Pointing to engine's spdlog
		"Hazel/src"                    -- FIXED: Pointing to engine's source for Hazel.h
	}

	links {
		"Hazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		toolset "msc-v145"
		buildoptions { "/utf-8" } 

		defines {
			"HZ_PLATFORM_WINDOWS" -- Fixed: No HZ_BUILD_DLL here
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"