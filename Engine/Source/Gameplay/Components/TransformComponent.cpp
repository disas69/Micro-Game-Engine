#include "TransformComponent.h"

namespace Micro
{
raylib::Matrix TransformComponent::GetTransformMatrix() const
{
    raylib::Matrix matScale = MatrixScale(Scale.x, Scale.y, Scale.z);
    raylib::Matrix matRotationX = MatrixRotateX(Rotation.x * DEG2RAD);
    raylib::Matrix matRotationY = MatrixRotateY(Rotation.y * DEG2RAD);
    raylib::Matrix matRotationZ = MatrixRotateZ(Rotation.z * DEG2RAD);
    raylib::Matrix matRotation = MatrixMultiply(MatrixMultiply(matRotationX, matRotationY), matRotationZ);
    raylib::Matrix matTranslation = MatrixTranslate(Position.x, Position.y, Position.z);

    return MatrixMultiply(MatrixMultiply(matScale, matRotation), matTranslation);
}
}  // namespace Micro
