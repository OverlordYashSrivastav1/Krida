#pragma once
#include "Core.h"
#include <memory.h>
#include "spdlog/spdlog.h"

namespace Krida {

	class KRIDA_API Log
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


//core log macros
#define KD_CORE_ERROR(...) :: Krida::Log::GetCoreLogger()-> error(__VA_ARGS__)
#define KD_CORE_WARN(...)  :: Krida::Log::GetCoreLogger()-> warn(__VA_ARGS__)
#define KD_CORE_INFO(...)  :: Krida::Log::GetCoreLogger()-> info(__VA_ARGS__)
#define KD_CORE_TRACE(...) :: Krida::Log::GetCoreLogger()-> trace(__VA_ARGS__)
#define KD_CORE_FATAL(...) :: Krida::Log::GetCoreLogger()-> fatal(__VA_ARGS__)

//client log macros

#define KD_ERROR(...) :: Krida::Log::GetClientLogger()-> error(__VA_ARGS__)
#define KD_WARN(...)  :: Krida::Log::GetClientLogger()-> warn(__VA_ARGS__)
#define KD_INFO(...)  :: Krida::Log::GetClientLogger()-> info(__VA_ARGS__)
#define KD_TRACE(...) :: Krida::Log::GetClientLogger()-> trace(__VA_ARGS__)
#define KD_FATAL(...) :: Krida::Log::GetClientLogger()-> fatal(__VA_ARGS__)



