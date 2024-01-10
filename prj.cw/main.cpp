#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>
#include <string>
//#include <json/json.h>
#include <fstream>

float sliderOx = 0.0f;
float sliderOy = 0.0f;
float sliderOz = 0.0f;
int selectedCircle = 0;
int counter = 0;

/*
void writeDataToJson(float sliderOx, float sliderOy, float sliderOz, int counter) {
    Json::Value data;
    data["sliderOx"] = sliderOx;
    data["sliderOy"] = sliderOy;
    data["sliderOz"] = sliderOz;
    data["counter"] = counter;

    std::ofstream file("data.json");
    if (file.is_open()) {
        file << data;
        file.close();
        std::cout << "Data has been written to data.json" << std::endl;
    } else {
        std::cerr << "Unable to open file data.json for writing" << std::endl;
    }
}

void readDataFromJson(float& sliderOx, float& sliderOy, float& sliderOz, int& counter) {
    std::ifstream file("data.json");
    if (file.is_open()) {
        Json::Value data;
        file >> data;
        file.close();

        if (!data["sliderOx"].isNull()) {
            sliderOx = data["sliderOx"].asFloat();
        }
        if (!data["sliderOy"].isNull()) {
            sliderOy = data["sliderOy"].asFloat();
        }
        if (!data["sliderOz"].isNull()) {
            sliderOz = data["sliderOz"].asFloat();
        }
        if (!data["counter"].isNull()) {
            counter = data["counter"].asInt();
        }

        std::cout << "Data has been read from data.json" << std::endl;
    } else {
        std::cerr << "Unable to open file data.json for reading" << std::endl;
    }
}
*/

std::string img_path;
std::string filetext;
cv::Mat image;

bool isOpen1 = false;
bool isOpen2 = false;

void renderMainMenu()
{
    //cv::Mat image;

    ImGui::Begin("Main MENU");

    if (ImGui::TreeNode("Open image"))
    {

        ImGui::Indent();
        if (ImGui::Button("Choose a photo..."))
        {
            isOpen1 = true;
        }
        if (isOpen1)
        {
            static char path1[256] = "";
            ImGui::InputText("Image path", path1, sizeof(path1));
            img_path = path1;

            if (ImGui::Button("Ok"))
            {
                //isOpen1 = false;
                cv::Mat img = cv::imread(img_path);
                cv::namedWindow("Your Image", cv::WINDOW_AUTOSIZE);
                cv::imshow("Your Image", img);
                path1[0] = '\0';
            }
            if (ImGui::GetIO().WantCaptureKeyboard)
            {
                if (ImGui::IsKeyPressed(ImGuiKey_O) && ImGui::GetIO().KeyCtrl)
                {
                    //isOpen1 = false;
                    cv::Mat img = cv::imread(img_path);
                    cv::namedWindow("Your Image", cv::WINDOW_AUTOSIZE);
                    cv::imshow("Your Image", img);
                    path1[0] = '\0';
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

        ImGui::SameLine();

        if (ImGui::Button("plane_2"))
        {
        }

        if (ImGui::Button("plane_3"))
        {
        }

        ImGui::Unindent();

        ImGui::TreePop();
    }

    if (ImGui::TreeNode("Scale"))
    {
        if (ImGui::Button("+"))
        {
            counter++;
        }
        if (ImGui::GetIO().WantCaptureKeyboard)
        {
            if (ImGui::IsKeyPressed(ImGuiKey_1) && ImGui::GetIO().KeyCtrl)
            {
                counter++;
            }
        }
        ImGui::SameLine();

        ImGui::Text("Ctrl+1"); //Отображение горячей клавиши

        ImGui::SameLine();

        if (ImGui::Button("-"))
        {
            counter--;
        }
        if (ImGui::GetIO().WantCaptureKeyboard)
        {
            if (ImGui::IsKeyPressed(ImGuiKey_2) && ImGui::GetIO().KeyCtrl)
            {
                counter--;
            }
        }
        ImGui::SameLine();
        ImGui::Text("Ctrl+2"); //Отображение горячей клавиши

        ImGui::Unindent();

        ImGui::TreePop();
    }

    if (ImGui::TreeNode("Save"))
    {
        ImGui::Indent();
        if (ImGui::Button("Text"))
        {
            isOpen2 = true;
        }
        if(isOpen2){
            static char path2[256] = "";
            ImGui::InputText("name.txt", path2, sizeof(path2));

            filetext = path2;

            if (ImGui::Button("Ok"))
            {
                std::ofstream outputfile(filetext);
                if (outputfile.is_open())
                {
                    outputfile << "Ox: " << std::endl;
                    outputfile << "Oy: " << std::endl;
                    outputfile << "Oz: " << std::endl;
                    outputfile << "scale" << std::endl;
                }
                outputfile.close();
                path2[0] = '\0';
            }
            
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
