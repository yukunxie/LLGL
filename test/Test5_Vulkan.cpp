/*
 * Test5_Vulkan.cpp
 *
 * This file is part of the "LLGL" project (Copyright (c) 2015-2017 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include "Helper.h"


//#define TEST_RENDER_TARGET
//#define TEST_QUERY
//#define TEST_STORAGE_BUFFER


int main()
{
    try
    {
        // Load render system module
        auto renderer = LLGL::RenderSystem::Load("Vulkan");

        // Create render context
        LLGL::RenderContextDescriptor contextDesc;

        contextDesc.videoMode.resolution        = { 800, 600 };
        //contextDesc.videoMode.fullscreen        = true;

        contextDesc.multiSampling.enabled       = true;
        contextDesc.multiSampling.samples       = 8;

        contextDesc.vsync.enabled               = true;

        LLGL::WindowDescriptor windowDesc;
        {
            windowDesc.size     = contextDesc.videoMode.resolution;
            windowDesc.centered = true;
            windowDesc.visible  = true;
        }
        auto window = std::shared_ptr<LLGL::Window>(std::move(LLGL::Window::Create(windowDesc)));

        auto context = renderer->CreateRenderContext(contextDesc, window);

        // Print renderer information
        const auto& info = renderer->GetRendererInfo();
        const auto& caps = renderer->GetRenderingCaps();

        std::cout << "Renderer: " << info.rendererName << std::endl;
        std::cout << "Device: " << info.deviceName << std::endl;
        std::cout << "Vendor: " << info.vendorName << std::endl;
        std::cout << "Shading Language: " << info.shadingLanguageName << std::endl;

        auto input = std::make_shared<LLGL::Input>();
        window->AddEventListener(input);

        while (window->ProcessEvents() && !input->KeyDown(LLGL::Key::Escape))
        {


            context->Present();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        #ifdef _WIN32
        system("pause");
        #endif
    }

    return 0;
}
