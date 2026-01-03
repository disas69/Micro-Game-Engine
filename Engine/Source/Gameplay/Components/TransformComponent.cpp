#include "TransformComponent.h"

namespace Micro
{
MMatrix TransformComponent::GetTransformMatrix() const
{
    MMatrix matScale = MatrixScale(Scale.x, Scale.y, Scale.z);
    MMatrix matRotationX = MatrixRotateX(Rotation.x * DEG2RAD);
    MMatrix matRotationY = MatrixRotateY(Rotation.y * DEG2RAD);
    MMatrix matRotationZ = MatrixRotateZ(Rotation.z * DEG2RAD);
    MMatrix matRotation = MatrixMultiply(MatrixMultiply(matRotationX, matRotationY), matRotationZ);
    MMatrix matTranslation = MatrixTranslate(Position.x, Position.y, Position.z);

    return MatrixMultiply(MatrixMultiply(matScale, matRotation), matTranslation);
}
}  // namespace Micro
