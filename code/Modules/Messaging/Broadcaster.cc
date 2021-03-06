//------------------------------------------------------------------------------
//  Broadcaster.cc
//------------------------------------------------------------------------------
#include "Pre.h"
#include "Broadcaster.h"

namespace Oryol {
    
OryolClassPoolAllocImpl(Broadcaster);

//------------------------------------------------------------------------------
Broadcaster::Broadcaster() {
    // empty
}

//------------------------------------------------------------------------------
Broadcaster::~Broadcaster() {
    this->subscribers.Clear();
}

//------------------------------------------------------------------------------
bool
Broadcaster::Put(const Ptr<Message>& msg) {
    bool retval = false;
    for (const Ptr<Port>& sub : this->subscribers) {
        retval |= sub->Put(msg);
    }
    return retval;
}

//------------------------------------------------------------------------------
void
Broadcaster::DoWork() {
    for (const Ptr<Port>& sub : this->subscribers) {
        sub->DoWork();
    }
}

//------------------------------------------------------------------------------
void
Broadcaster::Subscribe(const Ptr<Port>& port) {
    o_assert(InvalidIndex == this->subscribers.FindIndexLinear(port));
    this->subscribers.Add(port);
}
    
//------------------------------------------------------------------------------
void
Broadcaster::Unsubscribe(const Ptr<Port>& port) {
    int32 index = this->subscribers.FindIndexLinear(port);
    o_assert(InvalidIndex != index);
    this->subscribers.Erase(index);
}
    
//------------------------------------------------------------------------------
const Array<Ptr<Port>>&
Broadcaster::GetSubscribers() const {
    return this->subscribers;
}
    
} // namespace Oryol
