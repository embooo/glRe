#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GLRE
{
	class GLRE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		
	};

}
	

// Engine log macros
#define GLRE_CORE_TRACE(...)   ::GLRE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GLRE_CORE_INFO(...)    ::GLRE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GLRE_CORE_WARN(...)    ::GLRE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GLRE_CORE_ERROR(...)   ::GLRE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GLRE_CORE_FATAL(...)   ::GLRE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define GLRE_TRACE(...)        ::GLRE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GLRE_INFO(...)         ::GLRE::Log::GetClientLogger()->info(__VA_ARGS__)
#define GLRE_WARN(...)         ::GLRE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GLRE_ERROR(...)        ::GLRE::Log::GetClientLogger()->error(__VA_ARGS__)
#define GLRE_FATAL(...)        ::GLRE::Log::GetClientLogger()->fatal(__VA_ARGS__)