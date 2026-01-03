#pragma once

#include "GraphicComponent.h"

namespace Micro
{
class MeshComponent : public GraphicComponent
{
public:
    MMesh ObjectMesh;
    MMaterial ObjectMaterial;

    MeshComponent();

    void OnRender() override;
};
}  // namespace Micro
