#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>


class Resource {
    public:
        Resource(std::string name):
            name{name}
            {}

    protected:

    private:
        std::string name;
        double amount = 0;
};

#endif // RESOURCE_H
