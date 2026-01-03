#pragma once

#include "Gameplay/Components/GraphicComponent.h"
#include "Gameplay/Components/Transform2dComponent.h"

namespace Micro
{
    class ImageComponent : public GraphicComponent
    {
    public:
        ImageComponent();

        void OnRender() override;

        raylib::Texture2D Texture;
        raylib::Rectangle SourceRect = {0, 0, 100, 100};

    private:
        Transform2dComponent* m_transform = nullptr;
    };
}
