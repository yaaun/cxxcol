#ifndef DEFERREDACTION_H
#define DEFERREDACTION_H

#include <string>


class DeferredAction {
    public:
        enum class Actions {
            BUILD,
            DEMOLISH,
            MINE,
            PRODUCE,
            BUY,
            SELL,
        };

        DeferredAction();

        Actions getAction() const {return action;}
        int getCount() const {return count;}
        const std::string& getWhat() const {return what;}
    protected:

    private:
        Actions action;
        int count;
        std::string what;
};

#endif // DEFERREDACTION_H
