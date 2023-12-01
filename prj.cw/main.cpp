#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <ImGuiFileDialog.h>


float sliderOx = 0.0f;
float sliderOy = 0.0f;
float sliderOz = 0.0f;
int selectedCircle = 0;

std::string img;
cv::Mat image;

bool isOpen1 = false;

void renderMainMenu()
{
    //cv::Mat image;

    ImGui::Begin("Main MENU");

    if (ImGui::TreeNode("Open image"))
    {

        ImGui::Indent();
        if (ImGui::Button("Choose a photo from the computer"))
        {
            isOpen1 = true;
        }
        if (isOpen1)
        {
            static char path[256] = "";
            ImGui::InputText("Image path", path, sizeof(path));
            img = path;

            if (ImGui::Button("Ok"))
            {
                isOpen1 = false;
                cv::Mat image = cv::imread(img);
                cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
                cv::imshow("Display window", image);
            }
            if (ImGui::GetIO().WantCaptureKeyboard)
            {
                if (ImGui::IsKeyPressed(ImGuiKey_O) && ImGui::GetIO().KeyCtrl) //клавиши "Ctrl+O"
                {
                    isOpen1 = false;
                    cv::Mat image = cv::imread(img);
                    cv::namedWindow("Your Image", cv::WINDOW_AUTOSIZE);
                    cv::imshow("Your Image", image);
                }
            }
            ImGui::SameLine();
            ImGui::Text("Ctrl+O"); //Отображение горячей клавиши
        }
        ImGui::Unindent();
        ImGui::TreePop();
    }


    if (ImGui::TreeNode("Rotation"))
    {
        ImGui::Indent();

        ImGui::SliderFloat("Ox", &sliderOx, 0.0f, 360.0f);
        ImGui::SliderFloat("Oy", &sliderOy, 0.0f, 360.0f);
        ImGui::SliderFloat("Oz", &sliderOz, 0.0f, 360.0f);

        ImGui::Unindent();

        ImGui::TreePop();
    }


    if (ImGui::TreeNode("Color sistem"))
    {
        ImGui::Indent();

        if (ImGui::RadioButton("RGB", selectedCircle == 0))
        {
            selectedCircle = 0;
        }
        if (ImGui::RadioButton("CMY", selectedCircle == 1))
        {
            selectedCircle = 1;
        }

        if (ImGui::RadioButton("HSV", selectedCircle == 2))
        {
            selectedCircle = 2;
        }
        if (ImGui::RadioButton("HSL", selectedCircle == 3))
        {
            selectedCircle = 3;
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

        if (ImGui::Button("plane_3"))
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

    //cv::Mat iamge = cv::imread("/Users/balabashka/Downloads/diagram-2.png");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();// Начало кадра
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        renderMainMenu();//главное меню


        ImGui::Render();// Отрисовка кадра Imgui
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
