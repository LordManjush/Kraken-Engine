#pragma once
#include "ProjectManager.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui/imgui_internal.h>


#include <imgui/imgui_stdlib.h>
#include <imgui/ImGuiFileDialog.h>
#include <filesystem>
#include <iostream>
#include <imgui\imgui_impl_glfw.h>
#include <imgui\imgui_impl_opengl3.h>
#include <imgui\IconsFontAwesome6.h>
#include<glad/glad.h>
#include <include/GLFW/glfw3.h>
#include <include\GLFW\glfw3native.h>

#define STB_IMAGE_IMPLEMENTATION
#include<stb/stb_image.h>

int width, height, nrComponents;
unsigned int IconId;

namespace fs = std::filesystem;

std::string ProjectName = "NewProject";
std::string ProjectPath = "Documents/KrakenProjects/";

Kraken::Panels currentPanel = Kraken::Panels::About;




 void Kraken::ProjectManager::LoadIconImage() {


   
    
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(".\\Data\\Logo\\Logo.png", &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format{};
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glGenTextures(1, &IconId);
        glBindTexture(GL_TEXTURE_2D, IconId);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
        
    }
    else {
        

        stbi_image_free(data);
    }
}

static void ChoosePath()
{
    if (ImGuiFileDialog::Instance()->Display("ChooseFolderForProject"))
    {
        if (ImGuiFileDialog::Instance()->IsOk())
        {
            ProjectPath = ImGuiFileDialog::Instance()->GetCurrentPath();
        }
        ImGuiFileDialog::Instance()->Close();
    }
}
static void CreateProject()
{
    fs::create_directory(ProjectPath + "/" + ProjectName);
    ProjectName = "New Project";
}
void Kraken::ProjectManager::AboutPanel()
{
    ImGui::Text("About");
}

void Kraken::ProjectManager::OpenProjectsPanel()
{
    ImGui::Text("Open Project");
    ImGui::Separator();

    if (ImGui::Button("Choose file"))
    {
        ImGuiFileDialog::Instance()->OpenDialog("ChooseFolderForProject", "Choose Folder", nullptr, ".");
    }
    ImGui::InputText("##FolderPath", &ProjectPath);
    if (ImGui::Button("Open"))
    {
        //Import
    }
}

void Kraken::ProjectManager::NewProjectPanel()
{
    ImGui::Text("Create Project");
    ImGui::InputText("ProjectName", &ProjectName);
    ImGui::InputText("ProjectPath", &ProjectPath);
    ImGui::SameLine();
    if (ImGui::Button("Browse"))
    {
        ImGuiFileDialog::Instance()->OpenDialog("ChooseFolderForProject", "Choose Folder", nullptr, ".");
    }
    if (ImGui::Button("Create") && ProjectName.length() != 0 && ProjectPath.length() != 0)
    {
        CreateProject();
    }
}

void Kraken::ProjectManager::LearnEnginePanel()
{
    ImGui::Text("Learn");
    ImGui::Separator();
}

void Kraken::ProjectManager::run(GLFWwindow* window)
{
    
    glfwSetWindowTitle(window, "Kraken Project manager");

    
    ImGui::DockSpaceOverViewport();
    ImGui::SetNextWindowPos(ImVec2(1920 * 0.0f, 0));
    ImGui::SetNextWindowSize(ImVec2(1920 * 0.15f, 1080 * 0.936f));

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 15));
    ImGui::Begin("",NULL,ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_DockNodeHost);
    
    ChoosePath();
    ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(IconId)), ImVec2(width, height));
    ImGui::Dummy(ImVec2(0.0f, 0.07f));
    if (ImGui::Selectable("New Project",false,0))
    {
        currentPanel = New;
    }
    ImGui::Separator();
    if (ImGui::Selectable("Open Project",false, 0))
    {
        currentPanel = Open;
    }
    ImGui::Separator();
    if (ImGui::Selectable("Learn"))
    {
        currentPanel = Learn;
    }
    ImGui::Separator();
    if (ImGui::Selectable("About"))
    {
        currentPanel = About;
    }
    ImGui::Dummy(ImVec2(0.0f, 749.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
    if(ImGui::Button(ICON_FA_GEAR, ImVec2(45.0f, 45.0f)));
    {

    }
    ImGui::PopStyleVar();
    //ImGui::Dummy(ImVec2(0.0f, 580.0f));
    //ImGui::BulletText("Version 0.01");
    
    
    

    //ImGui::ImageButton() // change to settngs buton //I don't know how lol

    ImGui::PopStyleVar();


    ImGui::DockSpaceOverViewport();
    ImGui::SetNextWindowPos(ImVec2(1920 * 0.15f, 0));
    ImGui::SetNextWindowSize(ImVec2(1920 * 0.86f, 1080 * 0.936f));
    ImGui::Begin("Project list", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize );
    ImGui::End();
}