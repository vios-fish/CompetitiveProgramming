#include "test001.h"
#include <ostream>

%namespace-open%

/**
 * Default constructor
 */
test001::test001() {
}

/**
 * Default destructor
 */
test001::~test001() {
}

/**
 * Copy constructor
 */
test001::test001(const test001& rhs) {
}

/**
 * Assignment operator
 */
test001& test001::operator=(const test001& rhs) {
    if (this != &rhs) {
        // TODO: implement copy
    }
    return *this;
}

/**
 * stream output operator
 */
std::ostream& operator<<(std::ostream& lhs, const test001& rhs) {
    lhs << "::test001{" <<
        // TODO: implement out stream of member data
        "}";
    return lhs;
}
%namespace-close%

