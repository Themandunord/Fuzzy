#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

namespace fuzzy {
    template<class T>
    class MamdaniDefuzz{
    public:
        virtual T evaluate(core::Expression<T>* o) const = 0;
    };

}

#endif // MAMDANIDEFUZZ_H
