#pragma once

#include <include/GLFW/glfw3.h>


namespace Kraken 
{
	struct Kraken 
	{
		void init();
		void CheckError(GLFWwindow& window);
		void InitalizeImGui(GLFWwindow& window);
		void clear();
		void windowEventHandle(GLFWwindow& window);
		void Delete(GLFWwindow& window);
	};
}

