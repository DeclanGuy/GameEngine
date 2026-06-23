#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"


using logger_ptr_t = std::shared_ptr<spdlog::logger>;

namespace Hazel {
	class HAZEL_API Log
	{
	public:
		static void Init();
		inline static logger_ptr_t& GetCoreLogger() { return s_CoreLogger; }
		inline static logger_ptr_t& GetClientLogger() { return s_ClientLogger; }
	private:
		static logger_ptr_t s_CoreLogger;
		static logger_ptr_t s_ClientLogger;
	};

}

//Core log macros
#define HZ_CORE_TRACE(...)      ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)       ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)       ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)      ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)      ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//Client log macros
#define HZ_TRACE(...)      ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)       ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)       ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)      ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)      ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)