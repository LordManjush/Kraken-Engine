
#include <imgui/imgui.h>

#include <ProjectManager.h>
#include <Kraken.h>
#include <Editor.h>

int main() 
{
	Kraken::Kraken kraken;
	Kraken::ProjectManager projectManager;
	Kraken::KrakenEditor editor;

	kraken.init();
	GLFWwindow* window = glfwCreateWindow(800, 800, "Kraken", NULL, NULL);
	kraken.CheckError(*window);

	kraken.InitalizeImGui(*window);

	while (!glfwWindowShouldClose(window))
	{
		//ImGui::PushFont(fancyFont);
		kraken.clear();

		//projectManager.run(window);
		editor.run();

		kraken.windowEventHandle(*window);

	}

	kraken.Delete(*window);
	return 0;
}