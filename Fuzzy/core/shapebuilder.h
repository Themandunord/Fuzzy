#ifndef SHAPEBUILDER_H
#define SHAPEBUILDER_H

#include <vector>

namespace core
{
    template<class T>
    class ShapeBuilder
    {

    public:
        virtual ~ShapeBuilder(){}
        static ShapeBuilder<T> &getInstance();

    private:
        std::pair<std::vector<T>,std::vector<T> > shape;

        ShapeBuilder(){}
        ShapeBuilder(const ShapeBuilder&);
        void operator=(const ShapeBuilder&);
    };

    template<class T>
    ShapeBuilder<T>& ShapeBuilder<T>::getInstance()
    {
        static ShapeBuilder instance;
        return instance;
    }
}

#endif // SHAPEBUILDER_H
