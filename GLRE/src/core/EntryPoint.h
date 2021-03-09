#pragma once

#ifdef GLRE_PLATFORM_WINDOWS

extern GLRE::App* GLRE::CreateApp();

int main(int argc, char** argv)
{
	GLRE::Log::Init();
	GLRE_CORE_WARN("Initialized Log!");
	GLRE_INFO("Initialized Log!");
	auto app = GLRE::CreateApp();
	app->Run();
	delete app;
}


#else
	#error GLRE only supports Windows.
#endif