#include "Kraken.h"
#include <limo.h>
#include <stdio.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include<iostream>
#include<glad/glad.h>

void CustomStyle()
{

}

void Kraken::Kraken::init()
{
	Limo::init();
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	Limo::SucessLog("Completed initialization of GLFW");
}

void Kraken::Kraken::CheckError(GLFWwindow& window)
{
	if (&window == NULL)
	{
		Limo::ErrorLog("Failed to create window");
		glfwTerminate();
	}
	else
	{
		Limo::InfoLog("Completed creation of GLFW");
	}
	glfwMakeContextCurrent(&window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);
	glfwSwapBuffers(&window);
}

void Kraken::Kraken::InitalizeImGui(GLFWwindow& window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontDefault = io.Fonts->AddFontFromFileTTF(
		"./Data/fonts/NotoSans-Regular.ttf", 20);
	ImGui_ImplGlfw_InitForOpenGL(&window, true);
	ImGui_ImplOpenGL3_Init("#version 120");

	ImGui::StyleColorsDark();//Style
	//CustomStyle();

	Limo::InfoLog("Kraken current Opengl version '120'");
}

void Kraken::Kraken::clear()
{
	//gl
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//im
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Kraken::Kraken::windowEventHandle(GLFWwindow& window)
{
	ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(&window);

	glfwPollEvents();
}

void Kraken::Kraken::Delete(GLFWwindow& window)
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(&window);
	glfwTerminate();
	Limo::SucessLog("Quixel Closed");
	Limo::init();
}
