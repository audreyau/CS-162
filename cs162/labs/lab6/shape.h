#ifndef SHAPE_H     
#define SHAPE_H

class Shape {
    private:
        std::string name;
        std::string color;

    public:
        Shape (); 
        Shape (std::string, std::string);
        virtual ~Shape () = default;

        virtual float area () const = 0;
        virtual void display () = 0;
        virtual void settings (float, float) = 0;

        void changeName (std::string);
        void changeColor (std::string);

        std::string getName ();
        std::string getColor ();

        friend bool operator> (const Shape&, const Shape&);
};

#endif