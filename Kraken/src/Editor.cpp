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

void init()

{
    ImGuiIO& io = ImGui::GetIO();

    auto font = io.Fonts->AddFontFromFileTTF(
        "C:\Windows\Fonts\"RabbidHighwaySignII.ttf", 1.5f);
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


    ImGui::SetNextWindowPos(ImVec2(1920 * 0.0f,1080 * 0.87f));
    ImGui::SetNextWindowSize(ImVec2(1920 * 0.15f, 1080 * 0.08f));

   

 
    ImGui::SetWindowFontScale(50.0f);
    ImGui::Begin("", NULL,  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        
    ImGui::Text("jake");
    
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
            ImGui::EndMenu();
        }
        ImGui::Dummy(ImVec2(280.0f, 0.0f));
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