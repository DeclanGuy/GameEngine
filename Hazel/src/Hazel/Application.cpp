#include "Application.h"
#include "Log.h"

#include <chrono>
#include <windows.h>
#include <string>
namespace Hazel {
Application::Application() {

	}
Application::~Application() {

}
void Application::Run() {
	while (1) {
		/*auto start = std::chrono::high_resolution_clock::now();
		HZ_INFO("FRAME");
		auto end = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		HZ_INFO(std::to_string(1000000000.0f / diff));*/
	}
}
}