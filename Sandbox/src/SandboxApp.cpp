#include <Hazel.h>

class Sandbox : public Hazel::Application {
public:
	Sandbox() {
		HZ_INFO("Sandbox Running");
#ifdef _DEBUG
		HZ_CORE_INFO("Running in debug; optimisations disabled");
#endif
	}
	~Sandbox() {

	}
};
Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}