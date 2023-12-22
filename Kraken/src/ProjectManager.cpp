#include "ProjectManager.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui/imgui_internal.h>
#include <imgui/imgui_stdlib.h>
#include <imgui/ImGuiFileDialog.h>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::string ProjectName = "NewProject";
std::string ProjectPath = "Documents/KrakenProjects/";

Kraken::Panels currentPanel = Kraken::Panels::About;


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

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 55));
    ImGui::Begin("",NULL,ImGuiWindowFlags_NoCollapse|ImGuiWindowFlags_NoMove|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_DockNodeHost);
    
    ChoosePath();

    if (ImGui::Selectable("New Project"))
    {
        currentPanel = New;
    }
    if (ImGui::Selectable("Open Project"))
    {
        currentPanel = Open;
    }
    if (ImGui::Selectable("Learn"))
    {
        currentPanel = Learn;
    }

    if (ImGui::Selectable("About"))
    {
        currentPanel = About;
    }

    ImGui::BulletText("engine version -");
    ImGui::BulletText("0.0.0.0.1");

    //ImGui::ImageButton() // change to settngs buton //I don't know how lol

    ImGui::PopStyleVar();


    ImGui::DockSpaceOverViewport();
    ImGui::SetNextWindowPos(ImVec2(1920 * 0.15f, 0));
    ImGui::SetNextWindowSize(ImVec2(1920 * 0.86f, 1080 * 0.936f));
    ImGui::Begin("Project list", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize );
    ImGui::End();
}