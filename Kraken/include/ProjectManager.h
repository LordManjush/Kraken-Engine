#pragma once
#include <GLFW/glfw3.h>
#define PROJECT_MANAGER

#ifdef PROJECT_MANAGER

namespace Kraken {

	enum Panels
	{
		About = 0,
		Open = 1,
		New = 2,
		Learn = 3
	};

	struct ProjectManager
	{
		void LoadIconImage();
		void AboutPanel();
		void OpenProjectsPanel();
		void NewProjectPanel();
		void LearnEnginePanel();

		void run(GLFWwindow* window);

	};

}

#endif // PROJECT_MANAGER
