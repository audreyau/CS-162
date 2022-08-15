#ifndef SHAPE_H     
#define SHAPE_H

class Shape {
    private:
        std::string name;
        std::string color;

    public:
        Shape (); 
        Shape (std::string, std::string);

        float area ();
        void displayShape ();

        void changeName (std::string);
        void changeColor (std::string);

        std::string getName ();
        std::string getColor ();
};

#endif