#ifndef BUILDING_H
#define BUILDING_H


class Building {
    public:
        Building();
        virtual ~Building();

        const std::string& getName() const;
        int getHealth() const;
        int getMaxHealth() const;
    protected:

    private:
        std::string name;
        int health, max_health;
        int power;
};

#endif // BUILDING_H
