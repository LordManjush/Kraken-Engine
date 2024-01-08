#include "Editor.h"
#include <imgui/imgui.h>
#include <imgui/imgui_stdlib.h>
#include <imgui/ImGuiFileDialog.h>
#include <filesystem>
#include <iostream>
#include <imgui\imgui_impl_glfw.h>
#include <imgui\imgui_impl_opengl3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <imgui\stb_image.h>
#include <imgui\IconsFontAwesome6.h>
#include <include/GLFW/glfw3.h>
#include <include\GLFW\glfw3native.h>



auto defwidth = 1920;
auto defheight = 1080;

void init()

{
 ;

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    
    
}
void Kraken::KrakenEditor::OverviewPanel()
{
    ImGui::Begin("Overview", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    ImGui::Dummy(ImVec2(0, 920));
    ImGui::BeginTabBar("hh");

    if (ImGui::BeginTabItem("Scene"))
    {
        
        ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Properties"))
    {
        
        ImGui::EndTabItem();
    }

    ImGui::EndTabItem();
    ImGui::End();

}


void Kraken::KrakenEditor::AssetManager()
{



    
    ImGui::Begin("AssetManager");

    ImGui::End();
} 


void Kraken::KrakenEditor::OpenpanelBar()// this will open the asset manager and also hide it (just like ue5 content drawer)
{


    ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f,defheight * 0.9f));
    ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.04f));

   

 
   
    ImGui::Begin("", NULL,  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        
    ImGui::Button(ICON_FA_BELL);

    
    ImGui::End();
   
    
}

void Kraken::KrakenEditor::TitleBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New"))
            {
                //Do something
            }


            if (ImGui::MenuItem("Open"))
            {
                //Do something
            }


            if (ImGui::MenuItem("Open Recent"))
            {
                //Do something
            }

            if (ImGui::MenuItem("Peferences"))
            {
                //Do something
            }
            ImGui::EndMenu();
        }
        ImGui::Dummy(ImVec2(280.0f, 0.0f));
        if (ImGui::BeginMenu("Help"))
        {

        }
        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("View"))
        {

        }

        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("Home"))
        {

        }
        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("Model"))
        {

        }
        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("Edit"))
        {

        }

        ImGui::EndMainMenuBar();
    }
}


void Kraken::KrakenEditor::run()
{
    init();
    ImGui::DockSpaceOverViewport();
    AssetManager();
    OpenpanelBar();
    OverviewPanel();
    TitleBar();
    
    
    //Add the functions here
}