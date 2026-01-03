#pragma once

#include "GraphicComponent.h"

namespace Micro
{
class MeshComponent : public GraphicComponent
{
public:
    raylib::Mesh ObjectMesh;
    raylib::Material ObjectMaterial;

    MeshComponent();

    void OnRender() override;
};
}  // namespace Micro
