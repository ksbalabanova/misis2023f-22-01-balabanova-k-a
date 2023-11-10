#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include<opencv2/opencv.hpp>
#include<string>

float sliderOx = 0.0f;
float sliderOy = 0.0f;
float sliderOz = 0.0f;
int selectedCircle = 0;


void renderMainMenu()
{

    ImGui::Begin("Main menu");

    if (ImGui::TreeNode("Open image"))
    {
        ImGui::Indent();

        if (ImGui::Button("Choose a photo from the computer"))
        {
        }

        ImGui::Unindent();

        ImGui::TreePop();
    }


    if (ImGui::TreeNode("To get a projection"))
    {
        ImGui::Indent();
        if (ImGui::Button("plane_1"))
        {
        }

        if (ImGui::Button("plane_2"))
        {
        }
        
        ImGui::Unindent();

        ImGui::TreePop();
    }

    if (ImGui::TreeNode("Save"))
    {
        ImGui::Indent();
        if (ImGui::Button("Text"))
        {
        }

        ImGui::Indent();
        if (ImGui::Button("Protection"))
        {
        }

        ImGui::Indent();
        if (ImGui::Button("RGB_cube"))
        {
        }
        
        ImGui::Unindent();

        ImGui::TreePop();
    }

   

    ImGui::SliderFloat("Ox", &sliderOx, 0.0f, 360.0f);
    ImGui::SliderFloat("Oy", &sliderOy, 0.0f, 360.0f);
    ImGui::SliderFloat("Oz", &sliderOz, 0.0f, 360.0f);

    if (ImGui::RadioButton("RGB", selectedCircle == 0))
    {
        selectedCircle = 0;
    }
    if (ImGui::RadioButton("sRGB", selectedCircle == 1))
    {
        selectedCircle = 1;
    }
    if (ImGui::RadioButton("HSV", selectedCircle == 2))
    {
        selectedCircle = 2;
    }
    
    ImGui::End();
}

int main()
{
    // Инициализация GLFW
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "colorcube", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Инициализация Imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 120");


    // Главный цикл приложения
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Начало кадра Imgui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Рисуем главное меню
        renderMainMenu();

        // Отрисовка кадра Imgui
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Очистка ресурсов
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
