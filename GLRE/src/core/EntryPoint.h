#pragma once

#ifdef GLRE_PLATFORM_WINDOWS

extern GLRE::App* GLRE::CreateApp();

int main(int argc, char** argv)
{
	printf("\u001b[42;1mGLRendering Engine");
	auto app = GLRE::CreateApp();
	app->Run();
	delete app;
}




#else
	#error GLRE only supports Windows.
#endif