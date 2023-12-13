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

void ChoosePath()
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
    ImGui::Dummy(ImVec2(50, 20));
    if (ImGui::Button("Create") && ProjectName.length() != 0 && ProjectPath.length() != 0)
    {
        fs::create_directory(ProjectPath + "/" + ProjectName);
        ProjectName = "New Project";
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

    ImGui::Begin("ProjectManager");

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

    ImGui::End();

    ImGui::Begin("Projects");

    switch (currentPanel)
    {
    case Kraken::About:
        AboutPanel();
        break;
    case Kraken::Open:
        OpenProjectsPanel();
        break;

    case Panels::New:
        NewProjectPanel();
        break;
    case Panels::Learn:
        LearnEnginePanel();
        break;
    }

    ImGui::End();
}
