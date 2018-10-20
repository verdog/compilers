#pragma once

#include "astbinarynode.hpp"

namespace ast {

    class Assign : public Binary {
        Assign(Base* l, Base* r);
    };

} // ast