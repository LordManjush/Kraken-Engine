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
#include <imgui/tweeny-3.2.0.h>

using namespace std;

auto defwidth = 1920;
auto defheight = 1080;

bool ShowassetmanagerWindow = false;
bool ShowViewPanel = false;
bool ShowHomePanel = false;


void Kraken::KrakenEditor::OverviewPanel()
{

    ImGui::Begin("Overview", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    ImGui::Dummy(ImVec2(9999.0f, 0.0f));
    ImGui::BeginTabBar("hh");
    
    if (ImGui::BeginTabItem("Scene"))
    {
        ImGui::Text("Jake");
        
        ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Properties"))
    {
        ImGui::Text("god is great");
        ImGui::EndTabItem();
    }

    ImGui::EndTabItem();
    ImGui::End();

}


void Kraken::KrakenEditor::AssetManager()
{


    if (ShowassetmanagerWindow) {
        ImGui::Begin("AssetManager");

        ImGui::End();
    }
    
   
}
void Kraken::KrakenEditor::ViewTitlePanel()
{
 
    if (ShowViewPanel) {
        ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f, defheight * 0.017f));
        ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.06f));

       

        ImGui::Begin("ViewPanel",NULL,ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoDocking|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoTitleBar);

        ImGui::End();


        
    }



   

}


void Kraken::KrakenEditor::HomeTitlePanel()
{

    if (ShowHomePanel) {

        ShowViewPanel = false;
        ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f, defheight * 0.017f));
        ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.06f));



        ImGui::Begin("HomeTitlePanel", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);

        ImGui::End();



    }





}
void Kraken::KrakenEditor::OpenpanelBar()// this will open the asset manager and also hide it (just like ue5 content drawer)
{


    ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f,defheight * 0.9f));
    ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.04f));

   

 
   
    ImGui::Begin("jake", NULL,  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoTitleBar);
    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    if (ImGui::Button(ICON_FA_FOLDER))
    {
        ShowassetmanagerWindow = !ShowassetmanagerWindow; // Toggle the value
    }

    
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

            if (ImGui::MenuItem("Save"))
            {
                //Do something
            }

            if (ImGui::MenuItem("Save As"))
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

            if (ImGui::MenuItem("New"))
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
        if (ImGui::BeginMenu("View")) {
            if (ImGui::MenuItem("Open View panel"))
                ShowViewPanel = !ShowViewPanel;
                
            
            ImGui::EndMenu();
        }

        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("Home"))
        {
            if (ImGui::MenuItem("Open Home panel"))
                ShowHomePanel = !ShowHomePanel;
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
    
    ImGui::DockSpaceOverViewport();
    TitleBar();
    HomeTitlePanel();
    ViewTitlePanel();
    OpenpanelBar();
    AssetManager();
    OverviewPanel();
    OpenpanelBar();
    
    
    
  // ImGui::ShowDemoWindow();
    
    //Add the functions here
}