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
#include <imgui\IconsFontAwesome5.h>


auto defwidth = 1920;
auto defheight = 1080;

void init()

{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    auto font = io.Fonts->AddFontFromFileTTF(
        "C:\Windows\Fonts\"RabbidHighwaySignII.ttf", 20.0f);
    ImFontConfig config;
    config.MergeMode = false;
    config.GlyphMinAdvanceX = 13.0f; // Use if you want to make the icon monospaced
    static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
    io.Fonts->AddFontFromFileTTF("../../Lomus/Resources/Font/forkawesome-webfont.ttf", 50.0f, &config, icon_ranges);
    
    
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


    ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f,defheight * 0.87f));
    ImGui::SetNextWindowSize(ImVec2(defwidth * 0.01f, defheight * 0.08f));

   

 
   
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