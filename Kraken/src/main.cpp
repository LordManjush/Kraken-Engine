#include <ProjectManager.h>
#include <Kraken.h>

int main() 
{
	Kraken::Kraken kraken;
	Kraken::ProjectManager projectManager;

	kraken.init();
	GLFWwindow* window = glfwCreateWindow(800, 800, "Kraken", NULL, NULL);
	kraken.CheckError(*window);

	kraken.InitalizeImGui(*window);

	while (!glfwWindowShouldClose(window))
	{
		//ImGui::PushFont(fancyFont);
		kraken.clear();

		projectManager.run(window);

		kraken.windowEventHandle(*window);

	}

	kraken.Delete(*window);
}