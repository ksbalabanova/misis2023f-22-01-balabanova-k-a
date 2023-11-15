#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include "ImGuiFileDialog.h" 

std::string fileText;

void SaveFileButtonCallback()
{
    // Открытие диалогового окна для сохранения файла
    IGFD::FileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Save File", ".txt", ".");

    // Получение выбранного пути и сохранение текста в файл
    if (IGFD::FileDialog::Instance()->IsOk())
    {
        std::string filePath = IGFD::FileDialog::Instance()->GetFilePathName(IGFD_ResultMode_AddIfNoFileExt);



        std::ofstream file(filePath);
        file << fileText;
        file.close();
    }
    IGFD::FileDialog::Instance()->Close();
}

int main()
{
    // Инициализация GLFW и создание окна
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "ImGui Save File Example", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Инициализация ImGui и привязка к GLFW и OpenGL
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 120");

    // Главный цикл приложения
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Начало нового кадра ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Создание кнопки для сохранения файла
        if (ImGui::Button("Save File"))
        {
            SaveFileButtonCallback();
        }

        // Отображение окна ImGui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }


    // Освобождение ресурсов ImGui и GLFW
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
