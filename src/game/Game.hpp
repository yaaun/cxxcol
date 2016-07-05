#include <list>

#ifndef GAME_H
#define GAME_H


class Game {
    public:
        Game();
        ~Game();

        void addCredits(long long);
        long long getCredits() const;
        void setCredits(long long);


    protected:

    private:
        long long credits;
        std::list<Building*> buildings;
};

#endif // GAME_H
