
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
#include <vector>


using std::filesystem::exists;
using namespace std;
using std::string;
using std::filesystem::current_path;

void CustomStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.6000000238418579f;
	style.WindowPadding = ImVec2(6.900000095367432f, 8.0f);
	style.WindowRounding = 4.0f;
	style.WindowBorderSize = 1.0f;
	style.WindowMinSize = ImVec2(20.0f, 32.0f);
	style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 3.599999904632568f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 1.799999952316284f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(5.599999904632568f, 3.0f);
	style.FrameRounding = 0.0f;
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(2.0f, 6.599999904632568f);
	style.ItemInnerSpacing = ImVec2(11.30000019073486f, 0.8999999761581421f);
	style.CellPadding = ImVec2(6.900000095367432f, 2.0f);
	style.IndentSpacing = 0.0f;
	style.ColumnsMinSpacing = 4.900000095367432f;
	style.ScrollbarSize = 10.30000019073486f;
	style.ScrollbarRounding = 20.0f;
	style.GrabMinSize = 9.0f;
	style.GrabRounding = 0.0f;
	style.TabRounding = 3.299999952316284f;
	style.TabBorderSize = 0.0f;
	style.TabMinWidthForCloseButton = 0.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.05579400062561035f, 0.05579344183206558f, 0.05579344183206558f, 0.9399999976158142f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(9.999999974752427e-07f, 9.999899930335232e-07f, 9.999899930335232e-07f, 0.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784313753247261f, 0.0784313753247261f, 0.0784313753247261f, 0.9399999976158142f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.2575107216835022f, 0.2575081288814545f, 0.2575081288814545f, 0.5400000214576721f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3948497772216797f, 0.0f, 0.04067128524184227f, 0.4000000059604645f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.6995707750320435f, 0.3392768204212189f, 0.3749495148658752f, 0.4000000059604645f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(9.999999974752427e-07f, 9.999899930335232e-07f, 9.999899930335232e-07f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.274678111076355f, 0.0f, 1.650306876399554e-05f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.5099999904632568f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.09348119050264359f, 0.1029373928904533f, 0.1502146124839783f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.5299999713897705f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.5021458864212036f, 0.5021408796310425f, 0.5021423697471619f, 0.4000000059604645f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.6980392336845398f, 0.3411764800548553f, 0.3764705955982208f, 0.4000000059604645f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 0.0f, 6.008148193359375e-05f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.5751073360443115f, 0.0f, 3.455330079304986e-05f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.6980392336845398f, 0.3411764800548553f, 0.3764705955982208f, 0.4000000059604645f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.716738224029541f, 0.0f, 4.306269329390489e-05f, 0.4000000059604645f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.3960784375667572f, 0.0f, 0.03921568766236305f, 0.4000000059604645f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.6980392336845398f, 0.3411764800548553f, 0.3764705955982208f, 0.4000000059604645f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.1072961091995239f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3390557765960693f, 0.005820702761411667f, 0.005820702761411667f, 1.0f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.3004291653633118f, 0.0f, 1.805023021006491e-05f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(1.0f, 0.7424892783164978f, 0.8618506789207458f, 0.5f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(1.0f, 0.7411764860153198f, 0.8627451062202454f, 0.501960813999176f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(1.0f, 0.7411764860153198f, 0.8627451062202454f, 0.501960813999176f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.9764705896377563f, 0.2588235437870026f, 0.7577885985374451f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.0f, 0.4892703890800476f, 0.8437114953994751f, 0.2000000029802322f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.0f, 0.0f, 0.6939897537231445f, 0.2000000029802322f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.2532188892364502f, 0.0f, 0.1304131299257278f, 0.8619999885559082f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.4034335017204285f, 0.008657368831336498f, 0.2090823948383331f, 0.8627451062202454f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.3819742202758789f, 0.06393560767173767f, 0.2254015207290649f, 0.8627451062202454f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.06666667014360428f, 0.1019607856869698f, 0.1450980454683304f, 0.9724000096321106f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1333333402872086f, 0.2588235437870026f, 0.4235294163227081f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.6078431606292725f, 0.6078431606292725f, 0.6078431606292725f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.6980392336845398f, 0.0f, 1.0f);
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

	
	io.Fonts->Clear();
	auto font = io.Fonts->AddFontFromFileTTF(".\\Data\\Fonts\\Kanit-SemiBold.ttf", 16.0f);
	ImFontConfig config;
	config.MergeMode = true;
	config.GlyphMinAdvanceX = 13.0f; // Use if you want to make the icon monospaced
	

	static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };




	io.Fonts->AddFontFromFileTTF(".\\Data\\Fonts\\Forkawesome-webfont.ttf", 16.0f, &config, icon_ranges);
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
