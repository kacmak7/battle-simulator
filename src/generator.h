#ifndef GENERATOR_H
#define GENERATOR_H

class Generator {
public:
    Generator();
    ~Generator();

    //TODO: make a method generating units on the field near given position
    //TODO: implement logic of units deployment (exact place of every unit assuming they're circles)

    // Generates and deploys units to battle field
    void generateAndDeployUnits(int numberOfUnits, int x, int y);
};

#endif