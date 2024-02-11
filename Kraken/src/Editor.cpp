

#include "Editor.h"
#include <imgui/imgui.h>

#include <imgui/imgui_stdlib.h>
#include <imgui/ImGuiFileDialog.h>
#include <filesystem>
#include <iostream>
#include <imgui\imgui_impl_glfw.h>
#include <imgui\imgui_impl_opengl3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <EditorUi\stb_image.h>
#include <imgui\IconsFontAwesome6.h>
#include<glad/glad.h>
#include <include/GLFW/glfw3.h>
#include <include\GLFW\glfw3native.h>
#include <imgui/tweeny-3.2.0.h>

using namespace std;

auto defwidth = 1920;
auto defheight = 1080;
int row;

bool ShowOverViewWindow = true;
bool ShowassetmanagerWindow = false;
bool ShowViewPanel = false;
bool ShowHomePanel = false;
bool ShowModelPanel = false;
bool ShowEditPanel = false;



void Kraken::KrakenEditor::OverviewPanel()
{
    if (ShowOverViewWindow)
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
        
        ImGui::Dummy(ImVec2(0.1, 1));
        if (ImGui::Checkbox(ICON_FA_LIST, &ShowOverViewWindow))
        {

        }
        ImGui::End();


        
    }



   

}


void Kraken::KrakenEditor::HomeTitlePanel()
{

    if (ShowHomePanel) {
        
        ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f, defheight * 0.017f));
        ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.06f));



        ImGui::Begin("HomeTitlePanel", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
        
        {

           


            ImGui::BeginChild("ClipBoard", ImVec2(180.0f, 55.0f), true);
            if (ImGui::Button(ICON_FA_PASTE, ImVec2(40, 40)))
            {

            }

            ImGui::SameLine(0.0f, -2.0f);
            if (ImGui::Button(ICON_FA_COPY, ImVec2(40, 40)))
            {

            }
            ImGui::SameLine(0.0f, -2.0f);
            if (ImGui::Button(ICON_FA_SCISSORS, ImVec2(40, 40)))
            {

            }
            ImGui::SameLine(0.0f, -2.0f);
            if (ImGui::Button(ICON_FA_CLONE, ImVec2(40, 40)))
            {

            }

            ImGui::EndChild();


            ImGui::SameLine(-0.0f, -10.0f);

            ImGui::BeginChild("Tools", ImVec2(180.0f, 55.0f), true, ImGuiWindowFlags_NoScrollbar);
            if (ImGui::Button(ICON_FA_ARROW_POINTER, ImVec2(40, 40)))
            {

            }
            ImGui::SameLine(0.0f, -2.0f);
            if (ImGui::Button(ICON_FA_ARROWS_UP_DOWN_LEFT_RIGHT, ImVec2(40, 40)))
            {

            }
            ImGui::SameLine(0.0f, -2.0f);
            if (ImGui::Button(ICON_FA_EXPAND, ImVec2(40, 40)))
            {

            }
            ImGui::SameLine(0.0f, -2.0f);
            if (ImGui::Button(ICON_FA_ARROWS_ROTATE, ImVec2(40, 40)))
            {

            }
            ImGui::EndChild();

            ImGui::SameLine(0.0f, -99.0f);
            ImGui::BeginChild("Insert", ImVec2(118.0f, 55.0f), true, ImGuiWindowFlags_NoScrollbar);
            if (ImGui::Button(ICON_FA_CUBE, ImVec2(35, 30)))
            {

                //ImGui::OpenPopup("Parts");
            }

            ImGui::SameLine(0.0f, 9.0f);
            if (ImGui::CollapsingHeader("Parts"))
            {

            }
           /// if (ImGui::BeginPopupModal("Parts",NULL,ImGuiWindowFlags_NoCollapse)) {
              //  ImGui::Selectable("Part",ImGuiSelectableFlags_DontClosePopups);
              //  ImGui::Selectable("Cylinder", ImGuiSelectableFlags_DontClosePopups);
               // ImGui::Selectable("Sphere", ImGuiSelectableFlags_DontClosePopups);
               // ImGui::Selectable("Capsule", ImGuiSelectableFlags_DontClosePopups);
              ///  ImGui::EndPopup();
           /// }

            
            ImGui::EndChild();


        }
        ImGui::SeparatorText("ClipBoard");
        ImGui::SameLine (0.0f, 160.0f);
        ImGui::SeparatorText("Tools");
        ImGui::SameLine(0.0f, 145.0f);
        ImGui::SeparatorText("Insert");
        ImGui::End();



    }





}


void Kraken::KrakenEditor::ModelTitlePanel()
{

    if (ShowModelPanel) {
       
        ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f, defheight * 0.017f));
        ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.06f));



        ImGui::Begin("ModelPanel", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);

        ImGui::End();



    }





}


void Kraken::KrakenEditor::EditTitlePanel()
{

    if (ShowEditPanel) {
        
        ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f, defheight * 0.017f));
        ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.06f));



        ImGui::Begin("EditPanel", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);

        ImGui::End();



    }





}



void Kraken::KrakenEditor::OpenpanelBar()// this will open the asset manager and also hide it (just like ue5 content drawer)
{


    ImGui::SetNextWindowPos(ImVec2(defwidth * 0.0f,defheight * 0.9f));
    ImGui::SetNextWindowSize(ImVec2(defwidth * 1.0f, defheight * 0.04f));

   

 
   
    ImGui::Begin("jake", NULL,  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoTitleBar);
    ImGui::Dummy(ImVec2(0.0f, -2.0f));
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
            ShowModelPanel = false;
            ShowHomePanel = false;
            ShowEditPanel = false;
                
            
            ImGui::EndMenu();
        }

        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("Home"))
        {
            if (ImGui::MenuItem("Open Home panel"))
                
                ShowHomePanel = !ShowHomePanel;
            ShowModelPanel = false;
            ShowViewPanel = false;
            ShowEditPanel = false;
            ImGui::EndMenu();
        }
        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("Model"))
        {
            if (ImGui::MenuItem("Open Model panel"))
            
                ShowModelPanel = !ShowModelPanel;
                ShowHomePanel = false;
                ShowViewPanel = false;
                ShowEditPanel = false;
            ImGui::EndMenu();
        }
        ImGui::Dummy(ImVec2(40.0f, 0.0f));
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Open Edit panel"))

                ShowEditPanel = !ShowEditPanel;
            ShowHomePanel = false;
            ShowViewPanel = false;
            ShowModelPanel = false;

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}


void Kraken::KrakenEditor::run()
{
    
    //ImGui::DockSpaceOverViewport();
   // TitleBar();
    //EditTitlePanel();
   // ModelTitlePanel();
    //HomeTitlePanel();
   // ViewTitlePanel();
    
    //AssetManager();
    //OverviewPanel();
    //OpenpanelBar()
    
    
    
   //ImGui::ShowDemoWindow();
    
    //Add the functions here
}