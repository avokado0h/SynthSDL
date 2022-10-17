#ifndef INPUT_H
#define INPUT_H

struct myMouse { int x; int y; };

struct inputVars
{
    bool exit;
    double vol;
    myMouse mouse;
};

void getInputs(inputVars* iv);

#endif /* INPUT_H */