#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::Sensors
    @brief returns device sensory data
*/
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"

namespace Oryol {

class Sensors {
public:
    /// does the host platform provide sensory data?
    bool Attached = false;
    /// acceleration vector including gravity in m/sec^2
    glm::vec3 Acceleration{0.0f, -9.80665f, 0.0f};
    /// device orientation: yaw
    float32 Yaw = 0.0f;
    /// device orientation: pitch
    float32 Pitch = 0.0f;
    /// device orientation: roll
    float32 Roll = 0.0f;
};

} // namespace Oryol
