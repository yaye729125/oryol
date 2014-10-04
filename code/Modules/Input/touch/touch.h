#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::touch
    @brief internal touch event
*/
#include "Core/Types.h"
#include "Time/TimePoint.h"
#include "glm/vec2.hpp"

namespace Oryol {
namespace _priv {
    
class touch {
public:
    /// touch event type
    enum touchType {
        began,
        moved,
        ended,
        cancelled,
        invalid,
    } type = invalid;
    /// time stamp when the event occured
    TimePoint time;
    /// number of touch points in the event
    int32 numTouches = 0;
    /// max number of touches
    static const int32 MaxNumPoints = 8;
    /// touch points
    struct point {
        uintptr identifier = 0;     // unique 'finger identifier'
        glm::vec2 pos;
        bool isChanged = false;
    } points[MaxNumPoints];
    /// find point with matching identifier, return nullptr if not exists
    const point* findPoint(uintptr touchId) const;
    /// check if all point identifiers in touch event match this touch event
    bool sameTouches(const touch& other) const;
    /// get position of point matching touchId
    const glm::vec2& touchPos(uintptr touchId) const;
};
    
} // namespace _priv
} // namespace Oryol