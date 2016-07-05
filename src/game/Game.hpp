#ifndef GAME_H
#define GAME_H


class Game {
    public:
        Game();
        ~Game();

        void addCredits(long long);
        int getCredits() const;
        void setCredits(long long);
    protected:

    private:
        long long credits;

};

#endif // GAME_H
