#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <windows.h>
#include <iostream>

// Callback function for resizing the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Function to initialize OpenGL
void initOpenGL() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // Set background color
}

// Function to render a frame
void renderFrame() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set line width
    glLineWidth(5.0f);

    // Draw a rectangular frame
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);    // Bottom left
    glVertex2f(0.5f, -0.5f);     // Bottom right
    glVertex2f(0.5f, 0.5f);      // Top right
    glVertex2f(-0.5f, 0.5f);     // Top left
    glEnd();
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Frame", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Initialize OpenGL
    initOpenGL();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render frame
        renderFrame();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
