#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include<opencv2/opencv.hpp>
#include<string>

// Переменные для хранения значений ползунков и выбранного кружка
float sliderValue1 = 0.0f;
float sliderValue2 = 0.0f;
float sliderValue3 = 0.0f;
int selectedCircle = 0;


void renderMainMenu()
{
    // Начало окна Imgui
    ImGui::Begin("Main menu");

    // Вкладка 1
    if (ImGui::TreeNode("Вкладка 1"))
    {
        // Область с кнопками
        ImGui::Indent();

        if (ImGui::Button("Кнопка 1.1"))
        {
            // Действие при нажатии на кнопку 1.1
        }

        if (ImGui::Button("Кнопка 1.2"))
        {
            // Действие при нажатии на кнопку 1.2
        }

        ImGui::Unindent();

        ImGui::TreePop();
    }


    // Вкладка 2
    if (ImGui::TreeNode("v2"))
    {
        // Область с кнопкой
        ImGui::Indent();
        if (ImGui::Button("b2"))
        {
            // Действие при нажатии на кнопку
        }
        ImGui::Unindent();

        ImGui::TreePop();
    }

    // Вкладка 3
    if (ImGui::TreeNode("v3"))
    {
        // Область с кнопкой
        ImGui::Indent();
        if (ImGui::Button("b3"))
        {
            // Действие при нажатии на кнопку
        }
        ImGui::Unindent();

        ImGui::TreePop();
    }

    // Вкладка 4
    if (ImGui::TreeNode("w4"))
    {
        // Область с кнопкой
        ImGui::Indent();
        if (ImGui::Button("b4"))
        {
            // Действие при нажатии на кнопку
        }
        ImGui::Unindent();

        ImGui::TreePop();
    }

    // Ползунок 1
    ImGui::SliderFloat("Ползунок 1", &sliderValue1, 0.0f, 1.0f);

    // Ползунок 2
    ImGui::SliderFloat("Ползунок 2", &sliderValue2, 0.0f, 1.0f);

    // Ползунок 3
    ImGui::SliderFloat("Ползунок 3", &sliderValue3, 0.0f, 1.0f);

    // Кружок 1
    if (ImGui::RadioButton("Кружок 1", selectedCircle == 0))
    {
        selectedCircle = 0;
    }

    // Кружок 2
    if (ImGui::RadioButton("Кружок 2", selectedCircle == 1))
    {
        selectedCircle = 1;
    }

    // Кружок 3
    if (ImGui::RadioButton("Кружок 3", selectedCircle == 2))
    {
        selectedCircle = 2;
    }


    // Конец окна Imgui
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
