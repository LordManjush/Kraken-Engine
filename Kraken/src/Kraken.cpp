#include <filesystem>
#include "Kraken.h"
#include <limo.h>
#include <stdio.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include<iostream>
#include<glad/glad.h>
#include <imgui\IconsFontAwesome6.h>
#include <string>

using std::filesystem::exists;
using namespace std;
using std::string;
using std::filesystem::current_path;

void CustomStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.5f;
	style.WindowPadding = ImVec2(9.100000381469727f, 0.0f);
	style.WindowRounding = 0.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(20.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 0.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(0.0f, 0.0f);
	style.FrameRounding = 0.0f;
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(3.200000047683716f, 8.800000190734863f);
	style.ItemInnerSpacing = ImVec2(11.89999961853027f, 4.0f);
	style.CellPadding = ImVec2(6.699999809265137f, 2.0f);
	style.IndentSpacing = 0.0f;
	style.ColumnsMinSpacing = 0.0f;
	style.ScrollbarSize = 10.80000019073486f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 11.60000038146973f;
	style.GrabRounding = 11.39999961853027f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 0.0f;
	style.TabMinWidthForCloseButton = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.03353390097618103f, 0.0f, 0.09012877941131592f, 1.0f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(9.999999974752427e-07f, 9.999899930335232e-07f, 9.999899930335232e-07f, 0.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(9.999999974752427e-07f, 9.999899930335232e-07f, 9.999899930335232e-07f, 0.9399999976158142f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.2681943476200104f, 0.0f, 0.4806867241859436f, 1.0f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2352941185235977f, 0.03529411926865578f, 0.4235294163227081f, 1.0f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.062745101749897f, 0.0f, 0.168627455830574f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.0f, 0.0f, 0.0f, 0.5099999904632568f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1411764770746231f, 0.0f, 0.2745098173618317f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.5299999713897705f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.2446340173482895f, 0.2446327209472656f, 0.2446351647377014f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.8100425601005554f, 0.2599999904632568f, 0.9800000190734863f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.2431372553110123f, 0.2431372553110123f, 0.2431372553110123f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.3529411852359772f, 0.09411764889955521f, 0.6039215922355652f, 1.0f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.4118910729885101f, 0.1063751503825188f, 0.7081544995307922f, 1.0f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.3529411852359772f, 0.09411764889955521f, 0.6039215922355652f, 1.0f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3955868184566498f, 0.08653685450553894f, 0.6952790021896362f, 1.0f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.3717327415943146f, 0.371733546257019f, 0.3991416096687317f, 0.5f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.5367239713668823f, 0.1929672658443451f, 0.8326179981231689f, 1.0f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.3529411852359772f, 0.09411764889955521f, 0.6039215922355652f, 1.0f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.5372549295425415f, 0.1921568661928177f, 0.8313725590705872f, 1.0f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.3529411852359772f, 0.09411764889955521f, 0.6039215922355652f, 1.0f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.5372549295425415f, 0.1921568661928177f, 0.8313725590705872f, 1.0f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.4823529422283173f, 0.1725490242242813f, 0.7490196228027344f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.06666667014360428f, 0.1019607856869698f, 0.1450980454683304f, 0.9724000096321106f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1333333402872086f, 0.2588235437870026f, 0.4235294163227081f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.0f, 1.0f, 0.2156863212585449f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.1846526861190796f, 0.07296139001846313f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.8787679672241211f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.3499999940395355f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
	style.WindowMenuButtonPosition = ImGuiDir_None;
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
	glViewport(0, 0, 1920, 1080);
	glfwSwapBuffers(&window);
}



void Kraken::Kraken::InitalizeImGui(GLFWwindow& window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui_ImplGlfw_InitForOpenGL(&window, true);
	ImGui_ImplOpenGL3_Init("#version 120");

	
	//first i assign the path
	string fontsPath = (current_path()).string() + "..\\Fonts\\Kanit-SemiBold.ttf";
	//then i assign the output to check if the file actually exists
	string output = exists(fontsPath) ? "Font path " + fontsPath + " exists!" : "Font path " + fontsPath + " does not exist!";
	//then i print the output
	cout << output << "\n\n";
	//then if the file does exist i clear the fonts and actually assign fontsPath and font size
	if (exists(fontsPath))
	{
		io.Fonts->Clear();
		io.Fonts->AddFontFromFileTTF((fontsPath).c_str(), 16.0f);
		io.Fonts->Build();
	}
	std::cout << output << std::endl;
	ImFontConfig config;
	config.MergeMode = true;
	config.GlyphMinAdvanceX = 13.0f; // Use if you want to make the icon monospaced
	

	static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };




	io.Fonts->AddFontFromFileTTF(".\Data\Fonts\Forkawesome-webfont.ttf", 1.5f, &config, icon_ranges);
	io.Fonts->Build();


	//ImGui::StyleColorsDark();//Style
	CustomStyle();

	Limo::InfoLog("Kraken current Opengl version '120'");
}

void Kraken::Kraken::clear()
{
	//gl
	glClearColor(0.10f, 0.69f, 0.15f, 1.0f);
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
	Limo::SucessLog("Kraken Closed");
	Limo::init();
}
